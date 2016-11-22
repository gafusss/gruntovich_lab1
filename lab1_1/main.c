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

	//��������� 256-������ ����������� ����� a � b
	apa_gen_rand(a, SIZE);
	apa_gen_rand(b, SIZE);

	//����� ��������������� �����
	apa_print(a, SIZE);
	apa_print(b, SIZE);

	//�������� ����� c = a + b
	apa_add(a, b, SIZE, c);

	//����� ����� c
	apa_print(c, SIZE);

	//��������� �� ����� ������� ���������� d = c - b
	apa_sub(c, b, SIZE, d);

	//����� �������� d
	apa_print(d, SIZE);

	//��������� �������� � ������� ���������� (a � d)
	e = apa_cmp(a, d, SIZE);

	//����� ���������� ��������� �
	printf("%d\n", e);

	system("PAUSE");
	return 0;
}