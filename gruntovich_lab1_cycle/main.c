/*
�������� ���������, ������ 319
*/

#include "stdint.h"
#include "stdlib.h"
#include "time.h"
#include "stdio.h"
#include "../gruntovich_lab1/apa_basic.h"

//������ ����� � ������
#define SIZE 16

int main(int argc, char *argv[], char *envp[])
{
	//������ ���������
	uint16_t *a;

	//������ ���������
	uint16_t *b;

	//����� ���� ���������
	uint16_t *c;

	//�������� ����� � ������� ����������
	uint16_t *d;

	//��������� ��������� ������� ���������� � ���������
	int e;

	//������������� ���������� �������� ���� ������� ��������
	srand(time(NULL));

	for (uint32_t i = 0; i < UINT32_MAX; i++)
	{
		//����� ������ ��������
		printf("%u\n", i + 1);

		//��������� 256-������ ����������� ����� a � b
		a = apa_gen_rand(SIZE);
		b = apa_gen_rand(SIZE);

		//�������� ����� c = a + b
		c = apa_add(a, b, SIZE);

		//��������� �� ����� ������� ���������� d = c - b
		d = apa_sub(c, b, SIZE);

		//��������� �������� � ������� ���������� (a � d)
		e = apa_cmp(a, d, SIZE);

		//�������� ��������� �������� � ������� ����������
		if (e != 0)
		{
			printf("---!!! ������ !!!---\n");
			apa_print(a, SIZE);
			apa_print(b, SIZE);
			apa_print(c, SIZE);
			apa_print(d, SIZE);
			system("PAUSE");
		}

		//������������ ������
		free(a);
		free(b);
		free(c);
		free(d);
	}

	system("PAUSE");
	return 0;
}