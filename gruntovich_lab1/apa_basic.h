/*
Агафонов Александр, группа 319
*/

#ifndef ARBITRARY_PRECISION_ARITHMETIC_BASIC_H
#define ARBITRARY_PRECISION_ARITHMETIC_BASIC_H

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
uint16_t* apa_add(uint16_t* a, uint16_t* b, uint16_t size);

//Подпрограмма вычитания двух длинных беззнаковых чисел
// a, b - числа, разность которых нужно посчитать, длинной size слов
uint16_t* apa_sub(uint16_t* a, uint16_t* b, uint16_t size);

//Подпрограмма сравнения двух длинных беззнаковых чисел
// a, b - сравниваемые числа длинной size слов
int apa_cmp(uint16_t* a, uint16_t* b, uint16_t size);

//Подпрограмма генерации случайного длинного беззнакового числа
// size - размер числа в словах
uint16_t* apa_gen_rand(uint16_t size);

//Подпрограмма вывода длинного беззнакового числа в шестандцатиричном формате (начиная со старших разрядов)
// а - число размером size слов
void apa_print(uint16_t* a, uint16_t size);

#endif