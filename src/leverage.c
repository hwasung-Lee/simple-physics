#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <wchar.h>
#include <locale.h>

#include "leverage.h"

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "");

	int s;
	puts("1. leverage experiment");
	puts("2. what is torque?");
	printf("others. quit\n > ");
	scanf("%d",&s);
	switch(s)
	{
		case 1://continue
			break;
		case 2://print what is torque and exit
			torque_help();//declared in leverage.h
			exit(0);
		       break;
		default://others
		       exit(0);
	}
	int lever;//lever : length of lever
	int pivot;//pivot : location of pivot point
	int size_x, size_y; //terminal size

	printf("length of lever(integer)\n > ");
	scanf("%d", &lever);

	printf("x-coordinate of pivot point\n > ");
	scanf("%d", &pivot);

	WINDOW *exp =  initscr();
	noecho(); //disable echo what you type
	getmaxyx(exp, size_y, size_x);//get terminal size
	move(size_y/2,size_x/2-lever/2);

	for(int i=0;i<lever;i++)
		printw("_");//draw lever

	move(size_y/2+1,size_x/2);

	printw("%ls",L"Δ");//delta is pivot
	scanw("");
	
	endwin();
}	
