﻿/*
Агафонов Александр, группа 319
*/

#include "stdint.h"
#include "stdlib.h"
#include "time.h"
#include "stdio.h"
#include "LibAPA.h"

//Размер чисел в словах
#define SIZE 16

int main(int argc, char *argv[], char *envp[])
{
	uint16_t e[SIZE] = { 0x55f3, 0x6091, 0xb60e, 0x0f69, 0x74fc, 0x8ff0, 0x1307, 0x8abe, 0x6893, 0x76f6, 0x6cd2, 0x8f67, 0xff91, 0x5ea0, 0x8c90, 0xd207 };
	uint16_t d[SIZE] = { 0x080b, 0xb511, 0xd27c, 0xe1c6, 0x2076, 0x3ba7, 0x8711, 0x9a53, 0xe430, 0x286b, 0xabbc, 0x2d38, 0x456c, 0x0cd0, 0x50d7, 0x8add };
	uint16_t n[SIZE] = { 0x6d13, 0xffcb, 0xd640, 0xba83, 0x1158, 0x9c72, 0xdae5, 0x1b7b, 0x4387, 0x3d6d, 0x8a17, 0x678f, 0x0aa3, 0x74cd, 0x128b, 0xd9ae };

	//Первый сомножитель
	uint16_t a[SIZE];

	//Второй сомножитель
	uint16_t b[SIZE];

	//Произведение a и b
	uint16_t c[2 * SIZE];

	//Частное деления произведения на второй сомножитель c / b
	uint16_t q[2 * SIZE];

	//Остаток деления произведения на второй сомножитель c % b
	uint16_t r[SIZE];

	//Ноль
	uint16_t r0[SIZE] = { 0 };

	//Результат сравнения частного с первым сомножителем
	int tq;

	//Результат сравнения остатка с нулем
	int tr;

	//Инициализация начального значения ГПСП текущим временем
	srand(time(NULL));

	for (uintmax_t i = 0; i < UINTMAX_MAX; i++)
	{
		if (i % 1000 == 0) {
			//Вывод номера итерации
			printf("%llu\n", i + 1);
		}

		//Генерация 256-битных беззнаковых чисел a и b
		apa_gen_rand(a, SIZE);

		apa_mod_pow(a, SIZE, e, SIZE, n, b);

		apa_mod_pow(b, SIZE, d, SIZE, n, c);

		apa_mod(a, SIZE, n, SIZE, q);

		tq = apa_cmp(q, c, SIZE);

		//Проверка равенства разности и первого слагаемого
		if (tq != 0)
		{
			printf("---!!! ОШИБКА !!!---\n");
			printf("%llu\n", i);
			apa_print(a, SIZE);
			apa_print(b, SIZE);
			apa_print(c, SIZE);

			system("PAUSE");
		}
	}

	return 0;
}