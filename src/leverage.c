#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <wchar.h>
#include <locale.h>

#include "leverage.h"
#include "shapes.h"

#define left_arrow 260
#define right_arrow 261

int main(int argc, char** argv)
{
	double weight=1;
	int s;

	if(argc>=2)
	{
		if(strcmp(argv[1],"-w")==0)
		{
			if(argc != 3)
			{
				usage();
				exit(1);
			}
			else
			{
				weight = atof(argv[2]);	
				if(weight <= 0)
				{
					usage();
					exit(1);
				}
			}

		}
		else if(strcmp(argv[1], "-h")==0)
		{
			usage();
			exit(0);
		}
	}

	setlocale(LC_ALL, "");

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

	int lever=0;//lever : length of lever
	int pivot;//pivot : location of pivot point
	int size_x, size_y; //terminal size
	double torque = 0; //sum of torque
	
	do // get length of lever
	{	
		printf("length of lever(integer,odd, over 5)\n > ");
		scanf("%d", &lever);
	}while(lever<=5 || lever%2==0);
	

	WINDOW *exp =  initscr();
	keypad(exp, 1);
	noecho(); //disable echo what you type
	getmaxyx(exp, size_y, size_x);//get terminal size
	move(size_y/2,size_x/2-lever/2);
	
	draw_line(lever);

	pivot=size_x/2;
	move(size_y/2+1,pivot);//move pivot's position

	printw("%ls",L"Δ");//delta is pivot

	draw_box(size_y/2-1,size_x/2-lever/2, 2);//left box
	//right box
	if(lever%2==0)
		draw_box(size_y/2-1,size_x/2+lever/2-2, 2);
	else
		draw_box(size_y/2-1,size_x/2+lever/2-1, 2);
	
	move(0,size_x/2-7);
	printw("sum of torque");
	move(1,size_x/2);
	printw("%.3fN·m",torque);
	move(2,0);
	printw("%ls=%d",L"|Δpivot's position|",abs(pivot-size_x/2));

	int i;
	while(i=getch())
	{
		if(i==left_arrow || i == right_arrow)
		{
			move(size_y/2+1,pivot);//move pivot's position
			printw(" ");
			if(i==left_arrow)//if user typed left arrow key
			{
				pivot-=1;
			}
			else //if user typed right arrow key
			{
				pivot+=1;
			}
			move_pivot(size_x, size_y, lever, pivot);
			calc_torque(size_x, lever, pivot, &torque);
			refresh_stat(size_x, pivot, torque*weight);
			if(torque>0)
			{
				move(size_y/2-5,size_x/2-2);
				printw(" ");
				move(size_y/2-5,size_x/2+2);
				printw("%ls",L"↓");
			}
			else if(torque < 0)
			{
				move(size_y/2-5,size_x/2+2);
				printw(" ");
				move(size_y/2-5,size_x/2-2);
				printw("%ls",L"↓");
			}
			else
			{
				move(size_y/2-5,size_x/2-2);
				printw("     ");
			}
		}
		else if(i=='q')
			break;	
	}
	endwin();
}	
