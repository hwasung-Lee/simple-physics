#ifndef _leverage_H
#define _leverage_H
#endif

#ifdef _leverage_H

#include <stdio.h>
#include <wchar.h>
#include <locale.h>

void usage()
{
	puts("usage :");
	puts("--------------------------------------");
	puts("| ./leverage [options]               |");
	puts("| options : -h : show usage          |");
	puts("|           -w [weight] : set weight |");
	puts("--------------------------------------");
}

void torque_help()
{
	wchar_t *F_v=
{L"     /|\n    / |\n F /  |\n  /   |Fsin๐\n /\\ ๐ |\n/__\\__|\n"};
	setlocale(LC_ALL, "");
	puts("1. define of torque (source : en_Wikipedia)");
	puts("torque : \"the rotational equivalent of liner force.it is also called as the moment, moment of force, rotaional of force or turning effect\"");
	printf("%ls\n", L"๐ means torque. and ๐(vector) equals to r X F");
	puts("note : X means cross product");
	printf("%ls\n",L"and ๐(scala) = |r|*|F|sin๐, then you may think why this formula uses sin๐?");
	printf("%ls\n", L"it is because torque(scalar) equals to |r| * |F(vertical)|.");
	printf("look this to understand\n%ls\n",F_v);
}

void move_pivot(int size_x, int size_y, int lever, int pivot)
{
	move(size_y/2+1,pivot);//move pivot's position
	printw("%ls",L"ฮ");
}

void calc_torque(int size_x, int lever, int pivot, double* torque)
{
	double t1,t2;//t1 : torque1, t2 : torque2
	t1=pivot-(size_x/2 - lever/2);
	t2=(size_x/2 + lever/2) -pivot;
	*torque=t2-t1;
}

void refresh_stat(int size_x, int pivot, double torque)
{
	move(0,size_x/2-7);
	printw("sum of torque");
	move(1,size_x/2);
	clrtoeol();
	if(torque>=0)
		printw("%.3f",torque);
	else
		printw("%.3f",-1*torque);
	printw("Nยทm");
	move(2,0);
	clrtoeol();
	printw("%ls=%d",L"|ฮpivot's position|",abs(pivot-size_x/2));
}

#endif
