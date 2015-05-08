#!/usr/bin/python3

from gi.repository import Gtk
import plugins

class newobjectWindow:
    # Continuous ID for newly generated objects
    contID = 0

    def __init__(self, gladefile, owner):
        self.gladefile = gladefile
        self.owner = owner
        self.builder = Gtk.Builder()
        self.builder.add_from_file(self.gladefile)
        self.builder.connect_signals(self)
        
        self.liststore = self.builder.get_object("newObjectsStore")
        self.treeview = self.builder.get_object("treeview")
        self.treeviewSelection = self.treeview.get_selection()

        # Populate liststore with all available objects
        for plugin in plugins.pluginnames:
            module = getattr(plugins, plugin)
            for classname in module.classes:
                pluginclass = getattr(module, classname)

                listiter = self.liststore.append()
                self.liststore[listiter] = [pluginclass.name, pluginclass.description, plugin, classname]


        self.window = self.builder.get_object("newObjectWindow")
        if(self.window):
            self.window.show_all()

    def onCancelClicked(self, button):
        self.window.destroy()

    def onNewClicked(self, button):
        #get selection from listview, return to mainwindow
        #self.owner.treeobjects.append(selection)
        model, listiter = self.treeviewSelection.get_selected()
        self.newObject(self.liststore.get_value(listiter, 2), self.liststore.get_value(listiter, 3))


    def newObject(self, plugin, classname):
        # Generate new object, give it an ID, and return it
        assignID = self.__class__.contID
        self.__class__.contID += 1
        
        module = getattr(plugins, plugin)
        newClass = getattr(module, classname)
        newObject = newClass(assignID)
        self.owner.treeobjects.append(newObject)

        self.window.destroy()
        
