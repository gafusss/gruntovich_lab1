/*
Агафонов Александр, группа 319
*/

#include "LibAPA.h"

//Подпрограмма вычисления длинного беззнакового числа по модулю длинного беззнакового числа
// a - число, модуль которого необходимо вычислить, размером size_a слов
// b - модуль, размером size_b слов
// с - a mod b, размером size_b слов
void apa_mod(uint16_t const * const a, uintmax_t const size_a, uint16_t const * const b, uintmax_t const size_b, uint16_t* const c)
{
	// c = a % b
	apa_div(a, b, NULL, c, size_a, size_b);
}

//Подпрограмма вычисления произведения двух длинных беззнаковых чисел по модулю длинного беззнакового числа
// a - первый сомножитель, размером size слов
// b - второй сомножитель, размером size слов
// n - модуль, размером size слов
// c - a * b mod n, размеров size слов
// size <= MAX_MOD_MULT_OPERAND_SIZE (см. LibAPA.h)
void apa_mod_mult(uint16_t const * const a, uint16_t const * const b, uint16_t const * const n, uint16_t* const c, uintmax_t const size)
{
	// Произведение сомножителей
	uint16_t d[MAX_MOD_MULT_OPERAND_SIZE * 2];

	// d = a * b
	apa_mult(a, size, b, size, d);

	// c = d % n
	apa_mod(d, 2 * size, n, size, c);
}

//Подпрограмма возведения длинного беззнакового числа в степень длинного беззнакового числа по модулю длинного беззнакового числа
// a - основание, размером size_a слов
// b - показатель, размером size_b слов
// n - модуль, размером size_a слов
// c - a ^ b mod n, размеров size_a слов
void apa_mod_pow(uint16_t const * const a, uintmax_t const size_a, uint16_t const * const b, uintmax_t const size_b, uint16_t const * const n, uint16_t* const c)
{
	// c = 1
	apa_fill(c, size_a, 0);
	c[0] = 1;

	//Для всех битов показателя
	for (uintmax_t i = 16 * size_b; i > 0; i--)
	{
		// c = c * c mod n
		apa_mod_mult(c, c, n, c, size_a);

		//Если i-ый бит показателя == 1
		if((b[(i-1)/16]>>((i-1)%16))&1)
		{
			//c = c * a mod n
			apa_mod_mult(c, a, n, c, size_a);
		}
	}
}