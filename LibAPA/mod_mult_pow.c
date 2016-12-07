/*
Агафонов Александр, группа 319
*/

#include "LibAPA.h"

void apa_mod(uint16_t const * const a, uintmax_t const size_a, uint16_t const * const b, uintmax_t const size_b, uint16_t* const c)
{
	apa_div(a, b, NULL, c, size_a, size_b);
}

void apa_mod_mult(uint16_t const * const a, uint16_t const * const b, uint16_t const * const n, uint16_t* const c, uintmax_t const size)
{
	uint16_t d[MAX_MOD_MULT_OPERAND_SIZE * 2];

	apa_mult(a, size, b, size, d);

	apa_mod(d, 2 * size, n, size, c);
}

void apa_mod_pow(uint16_t const * const a, uintmax_t const size_a, uint16_t const * const b, uintmax_t const size_b, uint16_t const * const n, uint16_t* const c)
{
	apa_fill(c, size_a, 0);
	c[0] = 1;

	for (uintmax_t i = 16 * size_b; i > 0; i--)
	{
		apa_mod_mult(c, c, n, c, size_a);
		if((b[(i-1)/16]>>((i-1)%16))&1)
		{
			apa_mod_mult(c, a, n, c, size_a);
		}
	}
}