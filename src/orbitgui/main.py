#!/usr/bin/python3

import signal, sys

from gi.repository import Gtk 
import mainwindow

def main():
    mainwin = mainwindow.mainWindow("ui/ui.glade")
    

    Gtk.main()



def sigintHandler(*argv):
    sys.exit(1)

if __name__ == "__main__":
    signal.signal(signal.SIGINT, sigintHandler)
    main()

