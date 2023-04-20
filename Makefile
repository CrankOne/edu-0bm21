obj/%.o: src/%.cc
	g++ -Iinclude -c $^ -o $@

test: obj/main.o \
	  obj/scorer-simple-pairwise.o \
	  obj/scorer-kb.o \
	  obj/scorerP.o
	g++ $^ -o $@

clean:
	rm -f test
	rm obj/*

all: test

.PHONY: all clean
