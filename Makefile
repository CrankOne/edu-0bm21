obj/%.o: src/%.cc
	g++ -Iinclude -c $^ -o $@

test: obj/scorer.o \
	  obj/main.o
	g++ $^ -o $@

clean:
	rm -f test
	rm obj/*

all: test

.PHONY: all clean
