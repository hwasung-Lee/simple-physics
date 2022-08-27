#ifndef _leverage_H
#define _leverage_H
#endif

#ifdef _leverage_H

#include <stdio.h>
#include <wchar.h>
#include <locale.h>
void torque_help()
{
	wchar_t *F_v=
{L"     /|\n    / |\n F /  |\n  /   |Fsin𝜃\n /\\ 𝜃 |\n/__\\__|\n"};
	setlocale(LC_ALL, "");
	puts("1. define of torque (source : en_Wikipedia");
	puts("torque : \"the rotational equivalent of liner force.it is also called as the moment, moment of force, rotaional of force or turning effect\"");
	printf("%ls\n", L"𝛕 means torque. and 𝛕(vector) equals to r X F");
	puts("note : X means cross product");
	printf("%ls\n",L"and 𝜏(scala) = |r|*|F|sin𝜃, then you may think why this formula uses sin𝜃?");
	printf("%ls\n", L"it is because torque(scalar) equals to |r| * |F(vertical)|.");
	printf("look this to understand\n%ls\n",F_v);
	
}

#endif

