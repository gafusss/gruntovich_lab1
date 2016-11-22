/*
Агафонов Александр, группа 319
*/

#include "LibAPA.h"

//Подпрограмма умножения двух длинных беззнаковых чисел
// a, b - умножаемые числа длинной size_a и size_b слов, соответственно
// c - произведение a и b, размером size_a + size_b слов
void apa_mult(uint16_t* a, uintmax_t size_a, uint16_t* b, uintmax_t size_b, uint16_t* c)
{
	// TODO: Comment
	uint16_t d;
	uint32_t T;
	uintmax_t size_c = size_a + size_b;
	apa_fill(c, size_c, 0);

	for (uintmax_t i = 0; i < size_a; i++)
	{
		d = 0;
		for (uintmax_t j = 0; j < size_b; j++)
		{
			T = (uint32_t)c[i + j] + (uint32_t)a[i] * (uint32_t)b[j] + (uint32_t)d;
			c[i + j] = LOWORD(T);
			d = HIWORD(T);
		}
		c[i + size_b] = d;
	}
}