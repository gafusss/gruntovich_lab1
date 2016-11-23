/*
�������� ���������, ������ 319
*/

#include "LibAPA.h"
#include <stdlib.h>
#include <stdio.h>

//������������ ��������� ���� ������� ����������� �����
// a, b - ������������ ����� ������� size ����
//  ������������ ��������:
//     0: a == b
//     1: a > b
//    -1: b > a
int apa_cmp(uint16_t const * const a, uint16_t const * const b, uintmax_t const size)
{
	for (uintmax_t i = size; i > 0; i--)
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
// a - ������ ��� ������ ����� �������� size ����
uint16_t* apa_gen_rand(uint16_t* const a, uintmax_t const size)
{

	for (uintmax_t i = 0; i < size; i++)
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
void apa_print(uint16_t const * const a, uintmax_t const size)
{
	for (uintmax_t i = size; i > 0; i--)
	{
		printf("%04x", a[i - 1]);
	}
	printf("\n");
}

//������������ ���������� �������� ������������ ����� �������� ������
// a - ����� �������� size ����
// value - �������� ��� ����������
void apa_fill(uint16_t* const a, uintmax_t const size, uint16_t const value)
{
	for (uintmax_t i = 0; i < size; i++)
	{
		a[i] = value;
	}
}

//������������ ���������� ������ �������� ������������ ����� �������
// a - ����� �������� size ����, �������� ����� ��������� �������� ����� b
void apa_assign(uint16_t* const a, uint16_t const * const b, uintmax_t size)
{
	for (uintmax_t i = 0; i < size; i++)
	{
		a[i] = b[i];
	}
}