#!/usr/bin/python3

from itertools import count

class treeObject:
    consecutiveID = 0
    def __init__(self):
        self.name = ""
        self.ID = treeObject.consecutiveID
        treeObject.consecutiveID += 1
        self.objtype = "object"
        self.parent = None

class treeOrbiter(treeObject):
    def __init__(self):
        treeObject.__init__(self)
        self.objtype = "orbiter"

class treeOrbitable(treeObject):
    def __init__(self):
        treeObject.__init__(self)
        self.objtype = "orbitable"
