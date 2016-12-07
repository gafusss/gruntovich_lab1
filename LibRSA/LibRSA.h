/*
Агафонов Александр, группа 319
*/

#pragma once
#ifndef RIVEST_SHAMIR_ADLEMAN_H
#define RIVEST_SHAMIR_ADLEMAN_H

#pragma region includes

#include <stdint.h>

#pragma endregion Вложения


void rsa_encrypt(uint16_t const * const M, uintmax_t const s, uint16_t const * const e, uint16_t const * const n, uint16_t* const C, uintmax_t const k);
void rsa_decrypt(uint16_t const * const C, uint16_t const * const d, uint16_t const * const n, uint16_t* const M, uintmax_t const k);



#endif