# General C/C++ compile flags
CFLAGS=-Wall -g -ggdb
# C/C++ compile flags for Geant4-related sources
#G4CFLAGS:=$(shell geant4-config --cflags)
# linkage flags for Geant4-related libraries and utils
#G4LDFLAGS:=$(shell geant4-config --libs)

G4MACLDFLAGS=-Wl,-rpath,/Users/polinakargina/Desktop/geant4-v10.7.0/install/lib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4Tree.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4FR.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4GMocren.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4visHepRep.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4RayTracer.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4VRML.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4OpenGL.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4gl2ps.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4visQt3D.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4vis_management.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4modeling.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4interfaces.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4persistency.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4error_propagation.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4readout.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4physicslists.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4tasking.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4parmodels.dylib /Library/Developer/CommandLineTools/SDKs/MacOSX11.3.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd /usr/local/Cellar/qt@5/5.15.8_3/lib/QtOpenGL.framework/QtOpenGL /usr/local/Cellar/qt@5/5.15.8_3/lib/QtPrintSupport.framework/QtPrintSupport /usr/local/Cellar/qt@5/5.15.8_3/lib/QtWidgets.framework/QtWidgets /usr/local/Cellar/qt@5/5.15.8_3/lib/Qt3DExtras.framework/Qt3DExtras /usr/local/Cellar/qt@5/5.15.8_3/lib/Qt3DInput.framework/Qt3DInput /usr/local/Cellar/qt@5/5.15.8_3/lib/QtGamepad.framework/QtGamepad /usr/local/Cellar/qt@5/5.15.8_3/lib/Qt3DLogic.framework/Qt3DLogic /usr/local/Cellar/qt@5/5.15.8_3/lib/Qt3DRender.framework/Qt3DRender /usr/local/Cellar/qt@5/5.15.8_3/lib/Qt3DCore.framework/Qt3DCore /usr/local/Cellar/qt@5/5.15.8_3/lib/QtGui.framework/QtGui /usr/local/Cellar/qt@5/5.15.8_3/lib/QtNetwork.framework/QtNetwork /usr/local/Cellar/qt@5/5.15.8_3/lib/QtCore.framework/QtCore /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4run.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4event.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4tracking.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4processes.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4analysis.dylib /Library/Developer/CommandLineTools/SDKs/MacOSX11.3.sdk/usr/lib/libexpat.tbd /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4digits_hits.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4track.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4particles.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4geometry.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4materials.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4zlib.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4graphics_reps.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4intercoms.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4global.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4clhep.dylib /Users/polinakargina/Desktop/geant4-v10.7.0/install/lib/libG4ptl.0.0.2.dylib 

G4CFLAGS=`geant4-config --cflags` -I/Users/polinakargina/Desktop/geant4-v10.7.0/install/include/
G4LDFLAGS=`geant4-config --libs` -lG4tasking -lG4ptl


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
		obj/Geometry-hodoscope.o \
		obj/Geometry-calorimeter.o \
		libmcutils.so
	g++ $^ -o $@ ${G4LDFLAGS} ${G4MACLDFLAGS}

# Library with common utilities
libmcutils.so: obj/scorer-simple-pairwise.o \
	  obj/scorer-kb.o \
	  obj/scorerP.o
	g++ $^ -shared -o $@

clean:
	rm -f libmcutils.so myProj
	rm -rf obj/*

.PHONY: all clean

