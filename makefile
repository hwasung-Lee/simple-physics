CC=gcc
lib=-lncursesw
src=src/
header = header/
opt=$(lib) -I $(header) -g
all_target=free_fall leverage
objs=leverage.o shapes.o

all: $(all_target)

free_fall: src/free_fall.c header/free_fall.h
	$(CC) $(src)free_fall.c $(opt) -o $@

leverage: leverage.o shapes.o
	$(CC) leverage.o shapes.o $(opt) -o $@

leverage.o: src/leverage.c header/leverage.h
	$(CC) -c $(src)leverage.c $(opt) -o $@

shapes.o: src/shapes.c header/shapes.h
	$(CC) $(src)shapes.c -c $(opt) -o $@
	
.PHONY: clean
clean:
	rm $(objs)
