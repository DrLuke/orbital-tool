#!/usr/bin/python3

pluginname = "testplugin"
plugindescription = "This is a plugin that tests things"
classes = ["testobject"]

from gi.repository import Gtk

class testobject():
    name = "Testobject"
    description = "This is a testobject"
    
    def __init__(self, ID, mainWindow):
        self.parent = None
        self.valid = False

        self.mainWindow = mainWindow

        self.ID = ID


        self.menu = Gtk.Menu() 
        
        self.menuabout = Gtk.MenuItem(label="About")
        self.menu.append(self.menuabout)
        self.menuabout.connect("activate", self.onAbout)
        
        self.menudelete = Gtk.MenuItem("Delete")
        #TODO: Are you sure dialog
        self.menu.append(self.menudelete)
        self.menudelete.connect("activate", self.onDelete)

        self.menuSep = Gtk.SeparatorMenuItem()
        self.menu.append(self.menuSep)
        
        self.addMenuItems(self.menu)
        
        self.menu.show_all()
    
    ## Context menu
    def addMenuItems(self, menu):
        # You can add and connect custom menuitems here!
        pass

    def onAbout(self, menuItem):
        print("About!")

    def onDelete(self, menutiem):
        self.mainWindow.requestDelete(id(self), self.treeIter)

    ## External
    def onActivated(self):
        pass

    def showContextMenu(self, event):
        self.menu.popup(None, None, None, None, event.button, event.time)
        
