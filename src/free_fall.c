#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <time.h>
#include <free_fall.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
	int a;
	double g, n=0;
	if(argc>=2)
	{
		if(strcmp(argv[1],"-g")==0)
		{
			if(argc < 3)
			{
				usage();
				return 0;
			}
			g=atof(argv[2]);
		}
		else
		{
			printf("%s is not defined arugment\n",argv[1]);
			return 0;
		}
	}
	else
		g=10;

	initscr();
	noecho();
	struct timeval start_time, end_time;
	
	printw("Press 'space key' to start\n");
	while(getch()!=32);
	gettimeofday(&start_time,NULL);

	printw("Press 'space key to stop\n");
	while(getch()!=32);
	gettimeofday(&end_time,NULL);

	double t=(double)(end_time.tv_sec-start_time.tv_sec) + micro*(double)(end_time.tv_usec-start_time.tv_usec);
	endwin();
	double len=calc_len(0, g, t);
	printf("%lfm\n",len);	
	return 0;
}
