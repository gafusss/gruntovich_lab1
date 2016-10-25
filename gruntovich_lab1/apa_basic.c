/*
�������� ���������, ������ 319
*/

#include "apa_basic.h"
#include <stdlib.h>
#include <stdio.h>

//������������ �������� ���� ������� ����������� �����
// a, b - ����������� ����� ������� size ����
uint16_t* apa_add(uint16_t* a, uint16_t* b, uint16_t size)
{
	//����� ����� c = a + b
	uint16_t *c;

	// ��� �������� ������� ��� ��������
	uint16_t d = 0;

	//��������� ������������� �������� ����
	uint32_t T;

	//��������� ������ �������� size + 1 ����
	c = calloc(size + 1, sizeof(uint16_t));

	for (uint16_t i = 0; i < size; i++)
	{
		//������������ �������� ���� ����� � ����� ��������
		T = (uint32_t)(a[i]) + (uint32_t)(b[i]) + (uint32_t)(d);

		//���������� ����������� ��� �������� �����
		c[i] = LOWORD(T);

		//��������� ���� ��������, ������������ ��� ������ �������� T �� ������� �����
		d = HIWORD(T);
	}

	//������ ���� �������� � ������� ������ �����
	c[size] = d;

	return c;
}

//������������ ��������� ���� ������� ����������� �����
// a, b - �����, �������� ������� ����� ���������, ������� size ����
uint16_t* apa_sub(uint16_t* a, uint16_t* b, uint16_t size)
{
	//�������� ����� c = a - b
	uint16_t *c;

	// ��� �������� ������� ��� ���������
	uint16_t d = 0;

	//��������� ������������� ��������� ����
	uint32_t T;

	//��������� ������ �������� size + 1 ����
	c = calloc(size + 1, sizeof(uint16_t));

	for (uint16_t i = 0; i < size; i++)
	{
		//������������ ��������� ���� ����� � ����� ��������
		T = (uint32_t)(a[i]) - (uint32_t)(b[i]) - (uint32_t)(d);

		//���������� ����������� ��� ��������� �����
		c[i] = LOWORD(T);

		//��������� ���� ��������, ������������ ��� ������������ T
		d = (HIWORD(T) == 0) ? 0 : 1;
	}

	//������ ���� �������� � ������� ������ ��������
	c[size] = d;

	return c;
}

//������������ ��������� ���� ������� ����������� �����
// a, b - ������������ ����� ������� size ����
int apa_cmp(uint16_t* a, uint16_t* b, uint16_t size)
{
	for (uint16_t i = size; i > 0; i--)
	{
		if (a[i - 1] > b[i - 1])
		{
			//������ ����� ������ a > b
			return 1;
		}
		if (a[i - 1] < b[i - 1])
		{
			//������ ����� ������ b > a
			return -1;
		}
	}

	//����� ����� a == b
	return 0;
}

//������������ ��������� ���������� �������� ������������ �����
// size - ������ ����� � ������
uint16_t* apa_gen_rand(uint16_t size)
{
	//��������� ����������� ����� ������� size
	uint16_t *a;

	//��������� ������ �������� size ����
	a = calloc(size, sizeof(uint16_t));

	for (uint16_t i = 0; i < size; i++)
	{
		//��� ��� rand() ���������� ��������� ����� �� ����� 15 ��� �������,
		//����� �������� ������� ������� ��� ���������� ����� ����� �� �����������
		//��������� ������� ���� ������������ rand()
		a[i] = MAKEWORD(LOBYTE(rand()), LOBYTE(rand()));
	}

	return a;
}

//������������ ������ �������� ������������ ����� � ����������������� ������� (������� �� ������� ��������)
// � - ����� �������� size ����
void apa_print(uint16_t* a, uint16_t size)
{
	for (uint16_t i = size; i > 0; i--)
	{
		printf("%04x", a[i - 1]);
	}
	printf("\n");
}