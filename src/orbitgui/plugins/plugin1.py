#!/usr/bin/python3

pluginname = "testplugin"
plugindescription = "This is a plugin that tests things"
classes = ["testobject"]


class testobject():
    name = "Testobject"
    description = "This is a testobject"
    
    def __init__(self, ID, mainWindow):
        self.parent = None
        self.valid = False

        self.mainWindow = mainWindow

        self.ID = ID
        print("This is testobject, my ID is: " + str(self.ID))


    def onActivated(self):
        print("I have been activated! Testobject ID: " + str(self.ID))
