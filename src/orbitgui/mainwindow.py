#!/usr/bin/python3

from gi.repository import Gtk
from newobjectwindow import newobjectWindow

class mainWindow:
    def __init__(self, gladefile):
        self.gladefile = gladefile
        self.builder = Gtk.Builder()
        self.builder.add_from_file(gladefile)
        self.builder.connect_signals(self)
        
        self.window = self.builder.get_object("mainWindow")
        
        self.notebook = self.builder.get_object("notebook")
        self.curpage = self.notebook.get_current_page()
        
        # Treeview
        self.treeview = self.builder.get_object("mainList")
        self.treeModel = self.builder.get_object("mainTreeStore")
        self.treeobjects = []

        if(self.window):
            self.window.connect("destroy", lambda x: Gtk.main_quit())
            self.window.show_all()
    
    # Notebook
    def onPageRemoved(self, notebook, child, page):
        self.curpage = page

    def onPageSwitch(self, notebook, child, page):
        self.curpage = page

    # Toolbar
    def onNewClicked(self, button):
        self.newobjectWindow = newobjectWindow("ui/newobjectWindow.glade", self)

    def onOpenClicked(self, button):
        print("'Open' button pressed")

    def onSaveClicked(self, button):
        print("'Save' button pressed")

    # Treeview
    
