/*
Агафонов Александр, группа 319
*/

#pragma once
#ifndef ARBITRARY_PRECISION_ARITHMETIC_H
#define ARBITRARY_PRECISION_ARITHMETIC_H

#pragma region includes

#include <stdint.h>

#pragma endregion Вложения

#pragma region defines

//Настройка функции apa_div.
//MAX_DIV_OPERAND_SIZE - наибольшая возможная в проекте длина в словах аргументов функции apa_div.
//Эта константа необходима для эффективного выделения памяти в функции apa_div.
//Оставьте ее без изменения, если не понимаете, что это значит.
#define MAX_DIV_OPERAND_SIZE 32

//Настройка функции apa_mod_mult.
//MAX_MOD_MULT_OPERAND_SIZE - наибольшая возможная в проекте длина в словах аргументов функции apa_mod_mult.
//Эта константа необходима для эффективного выделения памяти в функции apa_mod_mult.
//Оставьте ее без изменения, если не понимаете, что это значит.
#define MAX_MOD_MULT_OPERAND_SIZE 32

#pragma region macros

//Макрос получения слова из двух байт
#define MAKEWORD(a,b) ((((uint16_t)(a))<<8)+b)

//Макрос получения младшего слова
#define LOWORD(T) ((uint16_t)(T))

//Макрос получения старшего слова
#define HIWORD(T) ((uint16_t)(T>>16))

//Макрос получения двойного слова из двух слов
#define MAKEDWORD(a,b) ((((uint32_t)(a))<<16)+b)

//Макрос получения младшего байта
#define LOBYTE(T) ((uint8_t)(T))

#pragma endregion Макросы

#pragma endregion Макросы и константы

#pragma region util

//Подпрограмма сравнения двух длинных беззнаковых чисел
// a, b - сравниваемые числа длинной size слов
//  Возвращаемые значения:
//     0: a == b
//     1: a > b
//    -1: b > a
int apa_cmp(uint16_t const * const a, uint16_t const * const b, uintmax_t const size);

//Подпрограмма генерации случайного длинного беззнакового числа
// a - массив для записи числа размером size слов
uint16_t* apa_gen_rand(uint16_t* const a, uintmax_t const size);

//Подпрограмма вывода длинного беззнакового числа в шестандцатиричном формате (начиная со старших разрядов)
// а - число размером size слов
void apa_print(uint16_t const * const a, uintmax_t const size);

//Подпрограмма заполнения длинного беззнакового числа заданным словом
// a - число размером size слов
// value - значение для заполнения
void apa_fill(uint16_t* const a, uintmax_t const size, uint16_t const value);

//Подпрограмма присвоения одного длинного беззнакового числа другому
// a - число размером size слов, которому будет присвоено значение числа b
void apa_assign(uint16_t* const a, uint16_t const * const b, uintmax_t size);

#pragma endregion Вспомогательные подпрограммы (файл util.c)

#pragma region basic_add_sub

//Подпрограмма сложения двух длинных беззнаковых чисел
// a, b - суммируемые числа длинной size слов
// c - сумма a и b, размером size слов
//  Возвращаемые значения:
//     бит переноса
uint16_t apa_add(uint16_t const * const a, uint16_t const * const b, uintmax_t const size, uint16_t * const c);

//Подпрограмма вычитания двух длинных беззнаковых чисел
// a, b - числа, разность которых нужно посчитать, длинной size слов
// c - разность a и b, размером size слов
//  Возвращаемые значения:
//     бит переноса
uint16_t apa_sub(uint16_t const * const a, uint16_t const * const b, uintmax_t const size, uint16_t * const c);

#pragma endregion Подпрограммы сложения и вычитания (файл basic_add_sub.c)

#pragma region basic_mult_div

//Подпрограмма умножения длинного беззнакового числа на слово
// a - умножаемое число длинной size слов
// b - множитель длинной в 1 слово
// c - произведение a и b, размером size слов
//  Возвращаемые значения:
//     слово переноса
uint16_t apa_mult_word(uint16_t const * const a, uintmax_t const size, uint16_t const b, uint16_t* const c);

//Подпрограмма деления длинного беззнакового числа на слово
// a - делимое число длинной size слов
// b - делитель длинной в 1 слово
// c [Nullable] - частное a и b, размером size слов
// r [Nullable] - остаток от деления a на b, размером 1 слово
//  Возвращаемые значения:
//     остаток от деления
uint16_t apa_div_word(uint16_t const * const a, uintmax_t const size, uint16_t const b, uint16_t* const c, uint16_t* const r);

//Подпрограмма умножения двух длинных беззнаковых чисел
// a, b - умножаемые числа длинной size_a и size_b слов, соответственно
// c - произведение a и b, размером size_a + size_b слов
void apa_mult(uint16_t const * const a, uintmax_t const size_a, uint16_t const * const b, uintmax_t const size_b, uint16_t* const c);

//Подпрограмма деления двух длинных беззнаковых чисел
// U - делимое, размером sizeU слов
// V - делитель, размером sizeV слов
// Q [Nullable] - частное, размером sizeU слов
// R [Nullable] - остаток, размером sizeV слов
// sizeU <= MAX_DIV_OPERAND_SIZE (см. LibAPA.h)
// sizeV <= MAX_DIV_OPERAND_SIZE (см. LibAPA.h)
void apa_div(uint16_t const * const U, uint16_t const * const V, uint16_t* const Q, uint16_t* const R, uintmax_t sizeU, uintmax_t sizeV);

#pragma endregion Подпрограммы умножения и деления (файл basic_mult_div.c)

#pragma region mod_mult_pow

//Подпрограмма вычисления длинного беззнакового числа по модулю другого длинного беззнакового числа
// a - число, модуль которого необходимо вычислить, размером size_a слов
// b - модуль, размером size_b слов
// с - a mod b, размером size_b слов
void apa_mod(uint16_t const * const a, uintmax_t const size_a, uint16_t const * const b, uintmax_t const size_b, uint16_t* const c);

//Подпрограмма вычисления произведения двух длинных беззнаковых чисел по модулю длинного беззнакового числа
// a - первый сомножитель, размером size слов
// b - второй сомножитель, размером size слов
// n - модуль, размером size слов
// c - a * b mod n, размеров size слов
// size <= MAX_MOD_MULT_OPERAND_SIZE (см. LibAPA.h)
void apa_mod_mult(uint16_t const * const a, uint16_t const * const b, uint16_t const * const n, uint16_t* const c, uintmax_t const size);

//Подпрограмма возведения длинного беззнакового числа в степень длинного беззнакового числа по модулю длинного беззнакового числа
// a - основание, размером size_a слов
// b - показатель, размером size_b слов
// n - модуль, размером size_a слов
// c - a ^ b mod n, размеров size_a слов
void apa_mod_pow(uint16_t const * const a, uintmax_t const size_a, uint16_t const * const b, uintmax_t const size_b, uint16_t const * const n, uint16_t* const c);

#pragma endregion Подпрограммы операций по модулю (файл mod_mult_pow.c)

#endif