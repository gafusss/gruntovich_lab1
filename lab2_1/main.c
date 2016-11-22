/*
Агафонов Александр, группа 319
*/

#include "stdint.h"
#include "stdlib.h"
#include "time.h"
#include "stdio.h"
#include "LibAPA.h"

#define SIZE 4

int main(int argc, char *argv[], char *envp[])
{

	uint16_t a[SIZE];
	uint16_t b[SIZE];
	uint16_t c[2*SIZE];
	uint16_t d[2 * SIZE];
	uint16_t r;


	//Инициализация начального значения ГПСП текущим временем
	srand(time(NULL));
	
	apa_gen_rand(a, SIZE);
	apa_gen_rand(b, SIZE);
	apa_mult(a, SIZE, b, SIZE, c);
	apa_print(a, SIZE);
	apa_print(b, SIZE);
	apa_print(c, 2* SIZE);

	apa_mult_word(a, SIZE, 7, c);
	apa_print(c, SIZE);
	apa_div_word(c, SIZE, 7, d, &r);
	apa_print(d, SIZE);
	apa_print(&r, 1);

	apa_gen_rand(a, SIZE);
	apa_div_word(a, SIZE, 7, b, &r);
	apa_mult_word(b, SIZE, 7, c);
	*c += r;
	apa_print(a, SIZE);
	apa_print(b, SIZE);
	apa_print(&r, 1);
	apa_print(c, SIZE);
	printf("%d\n", apa_cmp(c, a, SIZE));

	system("PAUSE");
	return 0;
}