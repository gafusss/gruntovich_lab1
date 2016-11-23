/*
Агафонов Александр, группа 319
*/

#include "LibAPA.h"
#include <stdlib.h>
#include <stdio.h>

//Подпрограмма сравнения двух длинных беззнаковых чисел
// a, b - сравниваемые числа длинной size слов
//  Возвращаемые значения:
//     0: a == b
//     1: a > b
//    -1: b > a
int apa_cmp(uint16_t const * const a, uint16_t const * const b, uintmax_t const size)
{
	for (uintmax_t i = size; i > 0; i--)
	{
		if (a[i - 1] > b[i - 1])
		{
			//Первое число больше a > b
			return 1;
		}
		if (a[i - 1] < b[i - 1])
		{
			//Второе число больше b > a
			return -1;
		}
	}

	//Числа равны a == b
	return 0;
}

//Подпрограмма генерации случайного длинного беззнакового числа
// a - массив для записи числа размером size слов
uint16_t* apa_gen_rand(uint16_t* const a, uintmax_t const size)
{

	for (uintmax_t i = 0; i < size; i++)
	{
		//Так как rand() генерирует случайные числа НЕ МЕНЕЕ 15 бит длинной,
		//чтобы избежать нулевой старший бит генерируем байты слова по отдельности
		//используя младший байт возвращаемый rand()
		a[i] = MAKEWORD(LOBYTE(rand()), LOBYTE(rand()));
	}

	return a;
}

//Подпрограмма вывода длинного беззнакового числа в шестандцатиричном формате (начиная со старших разрядов)
// а - число размером size слов
void apa_print(uint16_t const * const a, uintmax_t const size)
{
	for (uintmax_t i = size; i > 0; i--)
	{
		printf("%04x", a[i - 1]);
	}
	printf("\n");
}

//Подпрограмма заполнения длинного беззнакового числа заданным словом
// a - число размером size слов
// value - значение для заполнения
void apa_fill(uint16_t* const a, uintmax_t const size, uint16_t const value)
{
	for (uintmax_t i = 0; i < size; i++)
	{
		a[i] = value;
	}
}

//Подпрограмма присвоения одного длинного беззнакового числа другому
// a - число размером size слов, которому будет присвоено значение числа b
void apa_assign(uint16_t* const a, uint16_t const * const b, uintmax_t size)
{
	for (uintmax_t i = 0; i < size; i++)
	{
		a[i] = b[i];
	}
}