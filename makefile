# Copyright 2021 A.Garcia arturog@bu.edu

# This Makefile
# gives instructions to the command
# make
# about how and whether to build programs
#
# The syntax is

# thingtobuild:  what-it-needs-or-depends-on
#    instructions on how to build it
#

# make uses the modification dates to determine
# if the programs need to be re-built

all: platform

platform: platform.cpp
	g++ platform.cpp -o platform -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio