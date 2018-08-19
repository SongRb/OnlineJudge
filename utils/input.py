import getpass
import os

class Input:
    def __init__(self):
        self.username = None
        self.password = None

    def get_credentials(self):
        if self.username is None or self.password is None:
            self.username = input("Username: ")
            self.password = getpass.getpass("Password: ")
        return {"username": self.username, "password": self.password}

    @staticmethod
    def get_path():
        return os.path.join('.','Leetcode')

    @staticmethod
    def get_algorithms_path():
        return os.path.join('.','Leetcode','algorithms')
