#!/usr/bin/python3

pluginname = "testplugin"
plugindescription = "This is a plugin that tests things"
classes = ["testobject"]


class testobject():
    name = "Testobject"
    description = "This is a testobject"
    
    def __init__(self, ID):
        self.parent = None
        self.valid = False

        self.ID = ID
        print("This is testobject, my ID is: " + str(self.ID))
