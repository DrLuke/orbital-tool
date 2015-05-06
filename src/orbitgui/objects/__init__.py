#!/usr/bin/python3

pluginnames = []

import os
for module in os.listdir(os.path.dirname(__file__)):
    if module == '__init__.py' or module[-3:] != '.py':
        pass
    else:
        __import__("objects." + module[:-3], locals(), globals())
        pluginnames.append(module[:-3])
del module,os
