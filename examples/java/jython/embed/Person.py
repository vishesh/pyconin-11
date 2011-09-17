#
# We implement PersonInterface here
#

import PersonInterface

class Person(PersonInterface):
    def __init__(self, pname, page):
        self.pname = pname
        self.page = page

    def getName(self):
        return self.pname

    def getAge(self):
        return self.page


