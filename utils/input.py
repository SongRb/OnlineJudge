import getpass
import os

class Input():
    @staticmethod
    def get_credentials():
        return {"username": input("Username: "), "password": getpass.getpass("Password: ")}

    @staticmethod
    def get_path():
        return os.path.join('.','Leetcode')

    @staticmethod
    def get_algorithms_path():
        return os.path.join('.','Leetcode','algorithms')
