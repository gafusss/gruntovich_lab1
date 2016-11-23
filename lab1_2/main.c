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
	//Первое слагаемое
	uint16_t a[SIZE];

	//Второе слагаемое
	uint16_t b[SIZE];

	//Сумма двух слагаемых
	uint16_t c[SIZE];

	//Разность суммы и второго слагаемого
	uint16_t d[SIZE];

	//Результат сравнения первого слагаемого с разностью
	int e;

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

		//Сложение чисел c = a + b
		apa_add(a, b, SIZE, c);

		//Вычитание из суммы второго слагаемого d = c - b
		apa_sub(c, b, SIZE, d);

		//Сравнение разности и первого слагаемого (a и d)
		e = apa_cmp(a, d, SIZE);

		//Проверка равенства разности и первого слагаемого
		if (e != 0)
		{
			printf("---!!! ОШИБКА !!!---\n");
			apa_print(a, SIZE);
			apa_print(b, SIZE);
			apa_print(c, SIZE);
			apa_print(d, SIZE);
			system("PAUSE");
		}
	}

	system("PAUSE");
	return 0;
}