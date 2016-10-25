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

int main(int argc, char *argv[], char *envp[])
{
	uint16_t *a, *b;
	srand(time(NULL));
	a = gen_rand(2);
	b = gen_rand(2);
	print(a, 2);
	print(b, 2);
	print(add(a, b, 2), 3);
	system("PAUSE");
	return 0;
}