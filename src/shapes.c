#include "shapes.h"
#include <curses.h>

void draw_box(int y,int x, int n)
{
	move(y,x);//move to location where a box will be drawn
	for(int i=0;i<n;i++)
	{
		printw("*");
	}
	move(y-1,x);
	if(n==2)
	{
		for(int i=0;i<n;i++)
		{
			printw("*");
		}
	}
	else
	{
	}
	
}
void draw_line(int n)
{
	for(int i=0;i<n;i++)
		printw("=");
}
