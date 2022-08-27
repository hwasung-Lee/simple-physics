CC=gcc
lib=-lncurses
src=src/
header = header/
opt=$(lib) -I $(header) -g

free_fall: src/free_fall.c
	$(CC) $(src)free_fall.c $(opt) -o $@

leverage: src/leverage.c
	$(CC) $(src)leverage.c $(opt) -o $@ 

