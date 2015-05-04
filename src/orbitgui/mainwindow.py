#!/usr/bin/python3

from gi.repository import Gtk

class mainWindow:
    def __init__(self, gladefile):
        self.gladefile = gladefile
        self.builder = Gtk.Builder()
        self.builder.add_from_file(gladefile)
        self.window = self.builder.get_object("mainWindow")
        
        self.notebook = self.builder.get_object("notebook")
        
        self.treeview = self.builder.get_object("mainList")

        if(self.window):
            self.window.connect("destroy", lambda x: Gtk.main_quit())
            self.window.show_all()

        if(self.notebook):
            self.notebookHandler = notebookHandler(self.notebook)
            self.builder.connect_signals(self.notebookHandler)
        
        if(self.treeview):
            print("Treeview success")

class notebookHandler:
    def __init__(self, notebook):
        if(isinstance(notebook, Gtk.Notebook)):
            self.notebook = notebook
            self.curpage = self.notebook.get_current_page()

    def onPageRemoved(self, *args):
        print("Page has been removed")
        print(*args)

    def onPageSwitch(self, notebook, child, page):
        print("Page switched!")
        self.curpage = page

class toolbarHandler:
    def __init__(self, toolbar):
        if(isintance(toolbar,Gtk.Toolbar)):
            self.toolbar = toolbar
