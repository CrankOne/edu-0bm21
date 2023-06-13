# General C/C++ compile flags
CFLAGS=-Wall -g -ggdb
# C/C++ compile flags for Geant4-related sources
G4CFLAGS:=$(shell geant4-config --cflags)
# linkage flags for Geant4-related libraries and utils
#G4LDFLAGS:=$(shell geant4-config --libs) -lG4tasking -lG4ptl
G4LDFLAGS:=$(shell geant4-config --libs) -Wl,-rpath,/home/rdusaev/Sw/lib

# Rule to compile object files from sources from src/g4/ dir
obj/%.o: src/g4/%.cc
	g++ ${G4CFLAGS} -fPIC -Iinclude -c $^ -o $@
# Rule to compile object files from src/util/ dir
obj/%.o: src/util/%.cc
	g++ -fPIC -Iinclude/util -c $^ -o $@

all: myProj 

# Main project executable
myProj: obj/main.o \
		obj/DetectorConstruction.o \
		obj/PrimaryGeneratorAction.o \
		obj/ActionInitialization.o \
		obj/Geometry-hodoscope.o \
		obj/Geometry-homo-calorimeter.o \
		obj/Geometry-hetero-calorimeter.o \
		obj/SD-hodoscope.o \
		obj/SD-calorimeter.o \
		libmcutils.so
	g++ $^ -o $@ ${G4LDFLAGS}

# Library with common utilities
libmcutils.so: obj/scorer-simple-pairwise.o \
	  obj/scorer-kb.o \
	  obj/scorerP.o
	g++ $^ -shared -o $@

clean:
	rm -f libmcutils.so myProj
	rm -rf obj/*

.PHONY: all clean

