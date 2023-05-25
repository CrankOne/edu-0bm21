G4CFLAGS=-DG4VIS_USE_OPENGL -DG4UI_USE_TCSH -DG4UI_USE_QT -DG4VIS_USE_OPENGLQT \
	   -DG4VIS_USE_TOOLSSG_QT_GLES -I/usr/include/x86_64-linux-gnu/qt5/ \
	   -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore \
	   -isystem /usr/lib/x86_64-linux-gnu/qt5//mkspecs/linux-g++ \
	   -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui \
	   -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets \
	   -isystem /usr/include/x86_64-linux-gnu/qt5/QtOpenGL \
	   -isystem /usr/include/x86_64-linux-gnu/qt5/QtPrintSupport \
	   -W -Wall -pedantic -Wno-non-virtual-dtor -Wno-long-long -Wwrite-strings \
	   -Wpointer-arith -Woverloaded-virtual -Wno-variadic-macros -Wshadow \
	   -pipe -pthread -ftls-model=initial-exec -std=c++17 \
	   -I/home/crank/Sw/include/Geant4

G4LDFLAGS=-L/home/crank/Sw/lib -lG4OpenGL -lG4Tree -lG4FR -lG4GMocren \
		-lG4visHepRep -lG4RayTracer -lG4VRML -lG4ToolsSG -lG4vis_management \
		-lG4modeling -lG4interfaces -lG4persistency -lG4analysis \
		-lG4error_propagation -lG4readout -lG4physicslists -lG4run -lG4event \
		-lG4tracking -lG4parmodels -lG4processes -lG4digits_hits -lG4track \
		-lG4particles -lG4geometry -lG4materials -lG4graphics_reps \
		-lG4intercoms -lG4global -lG4clhep -lG4zlib -lG4ptl

obj/g4/%.o: src/g4/%.cc
	g++ ${G4CFLAGS} -fPIC -Iinclude -c $^ -o $@

obj/%.o: src/util/%.cc
	g++ -fPIC -Iinclude/util -c $^ -o $@

libmcutils.so: obj/scorer-simple-pairwise.o \
	  obj/scorer-kb.o \
	  obj/scorerP.o
	g++ $^ -shared -o $@

myProj: obj/g4/main.o libmcutils.so
	g++ $^ -o $@ ${G4LDFLAGS}

test: libmcutils.so obj/main.o
	g++ -L. obj/main.o -lmcutils -o $@ -Wl,-rpath ./

clean:
	rm -f libmcutils.so myProj
	rm -rf obj/*

all: test

.PHONY: all clean

