#include <time.h>
#define micro 0.000001/* 10^-6  */

double calc_len(double v0, double g, double t)
{
	double len = 0;
	double v=v0 + g*t;
	len = (v+v0)*t;
	return len;
}
void draw_graph(double v0, double g, double t);
void usage()
{
	puts("usage");
	puts("fall [option]");
	puts("option");
	puts("-g [num] : set gravitational acceleration as [num](default : 10)");
}
