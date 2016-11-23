/*
�������� ���������, ������ 319
*/

#include "stdint.h"
#include "stdlib.h"
#include "time.h"
#include "stdio.h"
#include "LibAPA.h"

//������ ����� � ������
#define SIZE 16

int main(int argc, char *argv[], char *envp[])
{
	//������ ���������
	uint16_t a[SIZE];

	//������ ���������
	uint16_t b[SIZE];

	//����� ���� ���������
	uint16_t c[SIZE];

	//�������� ����� � ������� ����������
	uint16_t d[SIZE];

	//��������� ��������� ������� ���������� � ���������
	int e;

	//������������� ���������� �������� ���� ������� ��������
	srand(time(NULL));

	for (uintmax_t i = 0; i < UINTMAX_MAX; i++)
	{
		if (i % 100000 == 0) {
			//����� ������ ��������
			printf("%llu\n", i + 1);
		}

		//��������� 256-������ ����������� ����� a � b
		apa_gen_rand(a, SIZE);
		apa_gen_rand(b, SIZE);

		//�������� ����� c = a + b
		apa_add(a, b, SIZE, c);

		//��������� �� ����� ������� ���������� d = c - b
		apa_sub(c, b, SIZE, d);

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
	}

	system("PAUSE");
	return 0;
}