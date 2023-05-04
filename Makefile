obj/%.o: src/%.cc
	g++ -fPIC -Iinclude -c $^ -o $@

libmcutils.so: obj/scorer-simple-pairwise.o \
	  obj/scorer-kb.o \
	  obj/scorerP.o
	g++ $^ -shared -o $@

test: libmcutils.so obj/main.o
	g++ -L. obj/main.o -lmcutils -o $@ -Wl,-rpath ./

clean:
	rm -f test libmcutils.so
	rm -rf obj/*

all: test

.PHONY: all clean

