#!/usr/bin/python3

from gi.repository import Gtk as gtk

class mainwindow:




    def __init__(self, gladefile):
        self.gladefile = gladefile
        self.builder = gtk.Builder()
        self.builder.add_from_file(gladefile)
        self.window = self.builder.get_object("mainWindow")


        if (self.window):
            self.window.connect("destroy", lambda x: gtk.main_quit())
            self.window.show_all()


