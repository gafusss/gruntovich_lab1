/*
�������� ���������, ������ 319
*/

#ifndef ARBITRARY_PRECISION_ARITHMETIC_BASIC_H
#define ARBITRARY_PRECISION_ARITHMETIC_BASIC_H

#include <stdint.h>

//������ ��������� ����� �� ���� ����
#define MAKEWORD(a,b) ((((uint16_t)(a))<<8)+b)

//������ ��������� �������� �����
#define LOWORD(T) ((uint16_t)(T))

//������ ��������� �������� �����
#define HIWORD(T) ((uint16_t)(T>>16))

//������ ��������� �������� ����� �� ���� ����
#define MAKEDWORD(a,b) ((((uint32_t)(a))<<16)+b)

//������ ��������� �������� �����
#define LOBYTE(T) ((uint8_t)(T))

//������������ �������� ���� ������� ����������� �����
// a, b - ����������� ����� ������� size ����
uint16_t* apa_add(uint16_t* a, uint16_t* b, uint16_t size);

//������������ ��������� ���� ������� ����������� �����
// a, b - �����, �������� ������� ����� ���������, ������� size ����
uint16_t* apa_sub(uint16_t* a, uint16_t* b, uint16_t size);

//������������ ��������� ���� ������� ����������� �����
// a, b - ������������ ����� ������� size ����
int apa_cmp(uint16_t* a, uint16_t* b, uint16_t size);

//������������ ��������� ���������� �������� ������������ �����
// size - ������ ����� � ������
uint16_t* apa_gen_rand(uint16_t size);

//������������ ������ �������� ������������ ����� � ����������������� ������� (������� �� ������� ��������)
// � - ����� �������� size ����
void apa_print(uint16_t* a, uint16_t size);

#endif