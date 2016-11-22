/*
Агафонов Александр, группа 319
*/

#include "stdint.h"
#include "stdlib.h"
#include "time.h"
#include "stdio.h"
#include "LibAPA.h"

#define SIZE 2

int main(int argc, char *argv[], char *envp[])
{

	uint16_t a[SIZE];
	uint16_t b[SIZE];
	uint16_t c[2*SIZE];


	//Инициализация начального значения ГПСП текущим временем
	srand(time(NULL));
	
	apa_gen_rand(a, SIZE);
	apa_gen_rand(b, SIZE);
	apa_mult(a, SIZE, b, SIZE, c);
	apa_print(a, SIZE);
	apa_print(b, SIZE);
	apa_print(c, 2* SIZE);
	system("PAUSE");
	return 0;
}