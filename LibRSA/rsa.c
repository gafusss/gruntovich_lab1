/*
Агафонов Александр, группа 319
*/

#include "LibRSA.h"
#include "LibAPA.h"

void rsa_encrypt(uint16_t const * const M, uintmax_t const s, uint16_t const * const e, uint16_t const * const n, uint16_t* const C, uintmax_t const k)
{
	apa_mod_pow(M, s / 2, e, s / 2, n, C);
}
void rsa_decrypt(uint16_t const * const C, uint16_t const * const d, uint16_t const * const n, uint16_t* const M, uintmax_t const k)
{
	apa_mod_pow(C, k/16, d, k/16, n, M);
}
