/*
Агафонов Александр, группа 319
*/

#include "stdint.h"
#include "stdlib.h"
#include "time.h"
#include "stdio.h"

#define MAKEWORD(a,b) ((((uint16_t)(a))<<8)+b)
#define LOWORD(T) ((uint16_t)(T))
#define HIWORD(T) ((uint16_t)(T>>16))
#define MAKEDWORD(a,b) ((((uint32_t)(a))<<16)+b)
#define LOBYTE(T) ((uint8_t)(T))

uint16_t* add(uint16_t* a, uint16_t* b, uint16_t size)
{
	uint16_t d = 0;
	uint32_t T;
	uint16_t i;
	uint16_t *c = calloc(size + 1, sizeof(uint16_t));
	for (i = 0; i < size; i++)
	{
		T = (uint32_t)(a[i]) + (uint32_t)(b[i]) + (uint32_t)(d); // cast d?
		c[i] = LOWORD(T);
		d = HIWORD(T);
	}
	c[size] = d;
	return c;
}

uint16_t* sub(uint16_t* a, uint16_t* b, uint16_t size)
{
	uint16_t d = 0;
	uint32_t T;
	uint16_t i;
	uint16_t *c = calloc(size + 1, sizeof(uint16_t));
	for (i = 0; i < size; i++)
	{
		T = (uint32_t)(a[i]) - (uint32_t)(b[i]) - (uint32_t)(d); // cast d?
		c[i] = LOWORD(T);
		d = (HIWORD(T) == 0) ? 0 : 1;
	}
	c[size] = d;
	return c;
}

int cmp(uint16_t* a, uint16_t* b, uint16_t size)
{
	for (uint16_t i = size; i > 0; i--)
	{
		if (a[i-1] > b[i-1])
		{
			return 1;
		}
		if (a[i-1] < b[i-1])
		{
			return -1;
		}
	}
	return 0;
}

uint16_t* gen_rand(uint16_t size)
{
	uint16_t *a = calloc(size, sizeof(uint16_t));
	for (uint16_t i = 0; i < size; i++)
	{
		a[i] = MAKEWORD(LOBYTE(rand()), LOBYTE(rand()));
	}
	return a;
}

void print(uint16_t* a, uint16_t size)
{
	for (uint16_t i = size; i > 0; i--)
	{
		printf("%04x", a[i - 1]);
	}
	printf("\n");
}

#define SIZE 16

int main(int argc, char *argv[], char *envp[])
{
	uint16_t *a;
	uint16_t *b;
	uint16_t *c;
	uint16_t *d;

	//Инициализация начального значения ГПСП текущим временем
	srand(time(NULL));
	
	//Генерация 256-битных беззнаковых чисел a и b
	a = gen_rand(SIZE);
	b = gen_rand(SIZE);
	
	//Вывод сгенерированных чисел
	print(a, SIZE);
	print(b, SIZE);

	c = add(a, b, SIZE);
	print(c, SIZE);
	d = sub(c, b, SIZE);
	print(d, SIZE);
	printf("%d\n", cmp(a, d, SIZE));

	system("PAUSE");
	return 0;
}