#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

#include "leverage.h"

int main(int argc, char** argv)
{
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
	printf("length of lever(integer)\n > ");
	scanf("%d", &lever);
	printf("x-coordinate of pivot point\n > ");
	scanf("%d", &pivot);
	initscr();
	noecho(); //disable echo what you 
	endwin();
}	
