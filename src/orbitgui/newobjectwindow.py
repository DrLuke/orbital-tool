#!/usr/bin/python3

from gi.repository import Gtk
import plugins

class newobjectWindow:
    # Continuous ID for newly generated objects
    contID = 0

    def __init__(self, gladefile, owner):
        self.gladefile = gladefile
        self.builder = Gtk.Builder()
        self.builder.add_from_file(self.gladefile)
        self.builder.connect_signals(self)
        
        self.liststore = self.builder.get_object("newObjectsStore")

        # Populate liststore with all available objects
        for plugin in plugins.pluginnames:
            module = getattr(plugins, plugin)
            
            listiter = self.liststore.append()
            self.liststore[listiter] = [module.modulename, module.description]


        self.window = self.builder.get_object("newObjectWindow")
        if(self.window):
            self.window.show_all()

    def onCancelClicked(self, button):
        self.window.destroy()

    def onNewClicked():
        #get selection from listview, return to mainwindow
        #self.owner.treeobjects.append(selection)
        pass

    def newObject(self, plugin, objectname):
        # Generate new object, give it an ID, and return it
        assignID = self.__class__.contID
        self.__class__.contID += 1
        
        # Create new object here
        # newobj = setattr(plugins, plugin, objectname)()
        
        
