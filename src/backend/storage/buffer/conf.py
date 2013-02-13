#!/usr/bin/env python

import os, sys, commands

if len(sys.argv) != 2:
	print "Need 2 args"
else:
	commands.getstatusoutput("cp -f bufmgr_" + sys.argv[1] + ".c bufmgr.c")
	commands.getstatusoutput("cp -f freelist_" + sys.argv[1] + ".c freelist.c")
	if sys.argv[1] == "orig":
		commands.getstatusoutput("cp -f buf_init_orig.c buf_init.c")
	else:
		commands.getstatusoutput("cp -f buf_init_mod.c buf_init.c")
	commands.getstatusoutput("cd ../../../..")
	commands.getstatusoutput("make ")
	commands.getstatusoutput("make install")
