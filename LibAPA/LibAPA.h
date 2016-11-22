/*
Агафонов Александр, группа 319
*/

#pragma once
#ifndef ARBITRARY_PRECISION_ARITHMETIC_H
#define ARBITRARY_PRECISION_ARITHMETIC_H

#include <stdint.h>

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

//Подпрограмма сложения двух длинных беззнаковых чисел
// a, b - суммируемые числа длинной size слов
// c - сумма a и b, размером size слов
//  Возвращаемые значения:
//     бит переноса
uint16_t apa_add(uint16_t* a, uint16_t* b, uintmax_t size, uint16_t* c);

//Подпрограмма вычитания двух длинных беззнаковых чисел
// a, b - числа, разность которых нужно посчитать, длинной size слов
// c - разность a и b, размером size слов
//  Возвращаемые значения:
//     бит переноса
uint16_t apa_sub(uint16_t* a, uint16_t* b, uintmax_t size, uint16_t* c);

//Подпрограмма сравнения двух длинных беззнаковых чисел
// a, b - сравниваемые числа длинной size слов
//  Возвращаемые значения:
//     0: a == b
//     1: a > b
//    -1: b > a
int apa_cmp(uint16_t* a, uint16_t* b, uintmax_t size);

//Подпрограмма генерации случайного длинного беззнакового числа
// a - массив для записи числа размером size слов
uint16_t* apa_gen_rand(uint16_t* a, uintmax_t size);

//Подпрограмма вывода длинного беззнакового числа в шестандцатиричном формате (начиная со старших разрядов)
// а - число размером size слов
void apa_print(uint16_t* a, uintmax_t size);

//Подпрограмма заполнения длинного беззнакового числа заданным словом
// a - число размером size слов
// value - значение для заполнения
void apa_fill(uint16_t* a, uintmax_t size, uint16_t value);

//Подпрограмма умножения двух длинных беззнаковых чисел
// a, b - умножаемые числа длинной size_a и size_b слов, соответственно
// c - произведение a и b, размером size_a + size_b слов
void apa_mult(uint16_t* a, uintmax_t size_a, uint16_t* b, uintmax_t size_b, uint16_t* c);

#endif