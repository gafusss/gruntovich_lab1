/*
�������� ���������, ������ 319
*/

#pragma once
#ifndef ARBITRARY_PRECISION_ARITHMETIC_H
#define ARBITRARY_PRECISION_ARITHMETIC_H

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
// c - ����� a � b, �������� size ����
//  ������������ ��������:
//     ��� ��������
uint16_t apa_add(uint16_t* a, uint16_t* b, uintmax_t size, uint16_t* c);

//������������ ��������� ���� ������� ����������� �����
// a, b - �����, �������� ������� ����� ���������, ������� size ����
// c - �������� a � b, �������� size ����
//  ������������ ��������:
//     ��� ��������
uint16_t apa_sub(uint16_t* a, uint16_t* b, uintmax_t size, uint16_t* c);

//������������ ��������� ���� ������� ����������� �����
// a, b - ������������ ����� ������� size ����
//  ������������ ��������:
//     0: a == b
//     1: a > b
//    -1: b > a
int apa_cmp(uint16_t* a, uint16_t* b, uintmax_t size);

//������������ ��������� ���������� �������� ������������ �����
// a - ������ ��� ������ ����� �������� size ����
uint16_t* apa_gen_rand(uint16_t* a, uintmax_t size);

//������������ ������ �������� ������������ ����� � ����������������� ������� (������� �� ������� ��������)
// � - ����� �������� size ����
void apa_print(uint16_t* a, uintmax_t size);

//������������ ���������� �������� ������������ ����� �������� ������
// a - ����� �������� size ����
// value - �������� ��� ����������
void apa_fill(uint16_t* a, uintmax_t size, uint16_t value);

//������������ ��������� ���� ������� ����������� �����
// a, b - ���������� ����� ������� size_a � size_b ����, ��������������
// c - ������������ a � b, �������� size_a + size_b ����
void apa_mult(uint16_t* a, uintmax_t size_a, uint16_t* b, uintmax_t size_b, uint16_t* c);

#endif