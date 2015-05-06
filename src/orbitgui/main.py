#!/usr/bin/python3

import signal, sys

from gi.repository import Gtk 
import mainwindow
import objects

def main():
    
    mainwin = mainwindow.mainWindow("ui/ui.glade")
    
    a = objects.plugin1.testobject()

    Gtk.main()



def sigintHandler(*argv):
    sys.exit(1)

if __name__ == "__main__":
    signal.signal(signal.SIGINT, sigintHandler)
    main()

