/*
Агафонов Александр, группа 319
*/

#include "LibAPA.h"

//Подпрограмма умножения двух длинных беззнаковых чисел
// a, b - умножаемые числа длинной size_a и size_b слов, соответственно
// c - произведение a и b, размером size_a + size_b слов
void apa_mult(uint16_t const * const a, uintmax_t const size_a, uint16_t const * const b, uintmax_t const size_b, uint16_t* const c)
{
	// Слово переноса разряда при умножении
	uint16_t d;

	//Результат элементарного умножения слов
	uint32_t T;

	//Размер числа c
	uintmax_t size_c = size_a + size_b;

	//Обнуление результата
	apa_fill(c, size_c, 0);

	for (uintmax_t i = 0; i < size_a; i++)
	{
		//Обнуление переноса
		d = 0;

		for (uintmax_t j = 0; j < size_b; j++)
		{
			//Элементарное умножение слов чисел с переносом
			T = (uint32_t)c[i + j] + (uint32_t)a[i] * (uint32_t)b[j] + (uint32_t)d;

			//Сохранение полученного при умножении слова
			c[i + j] = LOWORD(T);

			//Перенос разряда
			d = HIWORD(T);
		}

		//Сохранение переноса в следующий разряд
		c[i + size_b] = d;
	}
}