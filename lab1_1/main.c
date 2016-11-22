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

	//Генерация 256-битных беззнаковых чисел a и b
	apa_gen_rand(a, SIZE);
	apa_gen_rand(b, SIZE);

	//Вывод сгенерированных чисел
	apa_print(a, SIZE);
	apa_print(b, SIZE);

	//Сложение чисел c = a + b
	apa_add(a, b, SIZE, c);

	//Вывод суммы c
	apa_print(c, SIZE);

	//Вычитание из суммы второго слагаемого d = c - b
	apa_sub(c, b, SIZE, d);

	//Вывод разности d
	apa_print(d, SIZE);

	//Сравнение разности и первого слагаемого (a и d)
	e = apa_cmp(a, d, SIZE);

	//Вывод результата сравнения е
	printf("%d\n", e);

	system("PAUSE");
	return 0;
}