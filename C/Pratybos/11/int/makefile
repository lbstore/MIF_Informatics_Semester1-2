FILES = test.c mod.i mod.s mod.o 
all: test.c mod.i mod.s mod.o 
clean: 
	-rm -f *.o executable mod.i mod.s
build: $(FILES)
	
rebuild: clean build	
executable: test.c mod.h
	gcc test.c mod.h -o executable	
mod.i : mod.c	
	gcc -E mod.c -o mod.i
mod.o: mod.s 
	gcc -c mod.s -o mod.o
mod.s: mod.i
	gcc -S mod.i -o mod.s



 
