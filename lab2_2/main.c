/*
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
		if (i % 100000 == 0) {
			//Вывод номера итерации
			printf("%llu\n", i + 1);
		}

		//Генерация 256-битных беззнаковых чисел a и b
		apa_gen_rand(a, SIZE);
		apa_gen_rand(b, SIZE);

		//Перемножение чисел c = a * b
		apa_mult(a, SIZE, b, SIZE, c);

		//Деление произведения на второй сомножитель q = c / b, r = c % b
		apa_div(c, b, q, r, 2 * SIZE, SIZE);

		//Сравнение частного и первого сомножителя (q и a)
		tq = apa_cmp(q, a, SIZE);

		//Сравнение остатка и нуля (r и r0)
		tr = apa_cmp(r, r0, SIZE);

		//Проверка равенства разности и первого слагаемого
		if (tq != 0 || tr != 0)
		{
			printf("---!!! ОШИБКА !!!---\n");

			//Вывод сгенерированных чисел
			apa_print(a, SIZE);
			apa_print(b, SIZE);

			//Вывод произведения c
			apa_print(c, 2 * SIZE);

			//Вывод частного q
			apa_print(q, SIZE);

			//Вывод остатка r
			apa_print(r, SIZE);

			system("PAUSE");
		}
	}

	return 0;
}