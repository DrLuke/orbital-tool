#!/usr/bin/python3

from gi.repository import Gtk as gtk

from mainwindow import mainwindow

def main():
    
    mainwin = mainwindow("ui/ui.glade")

    gtk.main()


if __name__ == "__main__":
    main()
