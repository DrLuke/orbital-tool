#!/usr/bin/python3

from gi.repository import Gtk 
import mainwindow

def main():
    
    mainwin = mainwindow.mainWindow("ui/ui.glade")
    
    Gtk.main()


if __name__ == "__main__":
    main()
