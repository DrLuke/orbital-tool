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
        self.treeStore = self.builder.get_object("mainTreeStore")
        self.newObject = None   #Used for when a new object is created
        self.treeobjects = {}   #Key: Path in treeview, Value: Objects associated with tree row

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
        self.newobjectWindow.window.connect("destroy", self.onNewobjectWindowDestroyed)

    def onOpenClicked(self, button):
        print("'Open' button pressed")

    def onSaveClicked(self, button):
        print("'Save' button pressed")

    # Treeview
    def onNewobjectWindowDestroyed(self, *args):
        if(not self.newObject == None):
            # Add object to tree
            treeiter = self.treeStore.append(None)
            self.treeStore[treeiter] = [self.newObject.ID, self.newObject.name, id(self.newObject)]
            
            self.newObject.treeIter = treeiter
            # Store object in dictionary
            self.treeobjects[id(self.newObject)] = self.newObject
            # Clear reference to object
            self.newObject = None


    def onTreeRowInserted(self, model, path, treeiter):
        pass

    def onTreeRowDeleted(self, model, path):
        pass

    def onRowActivated(self, tree, path, column):
        activatedObject = self.treeobjects[self.treeStore[self.treeStore.get_iter(path)][2]]
        activatedObject.onActivated()

    def onButtonPressEvent(self, treeview, event):
        if(event.button == 3):
            path = self.treeview.get_path_at_pos(int(event.x), int(event.y))
            if(not path == None):
                path = path[0]
                activatedObject = self.treeobjects[self.treeStore[self.treeStore.get_iter(path)][2]]
                activatedObject.showContextMenu(event)

    def requestDelete(self, objectID, deliter):
        self.treeobjects[objectID] = None
        self.treeStore.remove(deliter)


