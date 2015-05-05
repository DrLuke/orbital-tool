#!/usr/bin/python3

from gi.repository import Gtk

class newobjectWindow:
    def __init__(self, gladefile):
        self.gladefile = gladefile
        self.builder = Gtk.Builder()
        self.builder.add_from_file(self.gladefile)
        self.builder.connect_signals(self)

        self.window = self.builder.get_object("newObjectWindow")
        if(self.window):
            self.window.show_all()

    def onCancelClicked(self, button):
        self.window.destroy()

    def onNewClicked():
        #get selection from listview, return to mainwindow
        pass
