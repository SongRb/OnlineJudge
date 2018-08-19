import json
import os
import re
import time

import requests
from bs4 import BeautifulSoup

import constants
from constants import ALGORITHMS_DIR
from input import Input


class Downloader:
    def __init__(self, input):
        self.session = requests.Session()
        self.input = input
        self.credentials = self.input.get_credentials()
        self.path = Input.get_path()
        self.algorithms_path = Input.get_algorithms_path()
        content = requests.get('https://leetcode.com/api/problems/algorithms/').content
        # get all problems
        self.questions = json.loads(content)['stat_status_pairs']
        self.title2id = {stat['stat']['question__title']: stat['stat']['frontend_question_id'] for
                         stat in self.questions}
        self.overwrite = False
        self.stored_problem_path = os.path.join(self.path,'result.json')
        self.stored_problem = dict()

        self.error_problem_path = os.path.join(self.path, 'error.json')
        self.error_list = list()

    def load_stored_problem(self):
        if not self.overwrite and os.path.exists(self.stored_problem_path):
            with open(self.stored_problem_path) as fin:
                self.stored_problem = json.load(fin)
        else:
            self.stored_problem = dict()

    def save_stored_problem(self):
        with open(os.path.join(self.path, 'result.json'), 'w') as fout:
            json.dump(self.stored_problem, fout)

    def save_error_problem(self):
        with open(os.path.join(self.path, 'error.json'), 'w') as fout:
            json.dump(self.error_list, fout)

    def get_token(self):
        response = self.session.get(constants.LOGIN_URL)
        return BeautifulSoup(response.content, "html.parser").find(
            attrs={"name": "csrfmiddlewaretoken"})['value']

    def login(self):
        self.session.post(constants.LOGIN_URL,
                          data={
                              "login": self.credentials['username'],
                              "password": self.credentials['password'],
                              "csrfmiddlewaretoken": self.get_token()
                          },
                          headers={"Referer": constants.LOGIN_URL})

    def download(self):
        self.login()
        self.load_stored_problem()

        for problem_set in constants.PROBLEM_SETS:
            response = self.session.get(constants.PROBLEMS_URL + problem_set)
            self.save_solutions(problem_set,
                                self.get_accepted_questions(json.loads(response.content)))

        self.save_stored_problem()

    @staticmethod
    def get_accepted_questions(problems):
        return [question['stat']['question__title_slug'] for question in
                problems['stat_status_pairs'] if question['status'] == "ac"]

    def save_solutions(self, problem_set, questions):
        for question in questions:
            try:
                response = self.session.get(
                    constants.SUBMISSIONS_URL + question + constants.SUBMISSION_PARAMETERS)
                accepted_submissions = self.get_latest_accepted_submission(json.loads(response.content))
                submission_url = accepted_submissions[0]["url"]
                if accepted_submissions and submission_url not in self.stored_problem:
                    for i in range(3):
                        try:
                            self.save_solution(problem_set, question, submission_url)
                        except AttributeError:
                            time.sleep(1)
                            continue
                        break
                else:
                    print("No newer accepted solution found for %s" % question)
            except Exception as e:
                print("Parse %s error..., caused by %s" % (question, str(e)))
                self.error_list.append([question, str(e)])

    def save_solution(self, problem_set, question, submission_url):
        response = self.session.get(constants.BASE_URL + submission_url)
        soup = BeautifulSoup(response.content, "html.parser")
        file_name = soup.find("a", attrs={"href": "/problems/" + question + "/"}).text
        tag = soup.find("script", text=re.compile(r"submissionCode:*")).text
        code_type = Downloader.get_attribute_value(tag, "getLangDisplay", "submissionCode")
        code = Downloader.get_attribute_value(tag, "submissionCode", "editCodeUrl")
        self.save_solution_file(problem_set, file_name, code_type, code)
        self.stored_problem[submission_url] = file_name

    def save_solution_file(self, problem_set, file_name, code_type, code):
        print("Saving solution for '" + file_name + "'")
        filepath = "{0}/{1}-{2}.{3}".format(self.algorithms_path, self.title2id[file_name], file_name, code_type)
        with open(filepath, 'w', encoding='utf8') as file_:
            file_.write(code)

    @staticmethod
    def get_latest_accepted_submission(submissions):
        return [submission for submission in submissions["submissions_dump"] if
                submission['status_display'] == 'Accepted']

    @staticmethod
    def get_attribute_value(tag, attribute, next_attribute):
        attribute_value = tag[tag.index(attribute + ": '"):tag.index(next_attribute + ": '")]
        return attribute_value[attribute_value.index("'") + 1:attribute_value.rindex("'")] \
            .encode('utf8').decode('unicode_escape')
