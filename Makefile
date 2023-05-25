G4CFLAGS=`geant4-config --cflags`
G4LDFLAGS=`geant4-config --ldflags`

obj/%.o: src/g4/%.cc
	g++ ${G4CFLAGS} -fPIC -Iinclude -c $^ -o $@

obj/%.o: src/util/%.cc
	g++ -fPIC -Iinclude/util -c $^ -o $@

libmcutils.so: obj/scorer-simple-pairwise.o \
	  obj/scorer-kb.o \
	  obj/scorerP.o
	g++ $^ -shared -o $@

myProj: obj/main.o libmcutils.so
	g++ $^ -o $@ ${G4LDFLAGS}

test: libmcutils.so obj/main.o
	g++ -L. obj/main.o -lmcutils -o $@ -Wl,-rpath ./

clean:
	rm -f libmcutils.so myProj
	rm -rf obj/*

all: test

.PHONY: all clean

