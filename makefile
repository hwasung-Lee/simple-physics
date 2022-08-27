CC=gcc
lib=-lncurses
src=src/
header = header/
opt=$(lib) -I $(header) -g
all_target=free_fall leverage

all: $(all_target)

free_fall: src/free_fall.c header/free_fall.h
	$(CC) $(src)free_fall.c $(opt) -o $@

leverage: src/leverage.c header/leverage.h
	$(CC) $(src)leverage.c $(opt) -o $@ 

