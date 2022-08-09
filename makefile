CC=gcc
lib=-lncurses
src=src/
header = header/
opt=$(lib) -I $(header) -g

fall: src/fall.c
	$(CC) $(src)fall.c $(opt) -o fall

