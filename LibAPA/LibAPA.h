/*
�������� ���������, ������ 319
*/

#pragma once
#ifndef ARBITRARY_PRECISION_ARITHMETIC_H
#define ARBITRARY_PRECISION_ARITHMETIC_H

#include <stdint.h>

//��������� ������� apa_div.
//MAX_DIV_OPERAND_SIZE - ���������� ��������� � ������� ����� � ������ ���������� ������� apa_div.
//��� ��������� ���������� ��� ������������ ��������� ������ � ������� apa_div.
//�������� �� ��� ���������, ���� �� ���������, ��� ��� ������.
#define MAX_DIV_OPERAND_SIZE 32

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
uint16_t apa_add(uint16_t const * const a, uint16_t const * const b, uintmax_t const size, uint16_t * const c);

//������������ ��������� ���� ������� ����������� �����
// a, b - �����, �������� ������� ����� ���������, ������� size ����
// c - �������� a � b, �������� size ����
//  ������������ ��������:
//     ��� ��������
uint16_t apa_sub(uint16_t const * const a, uint16_t const * const b, uintmax_t const size, uint16_t * const c);

//������������ ��������� ���� ������� ����������� �����
// a, b - ������������ ����� ������� size ����
//  ������������ ��������:
//     0: a == b
//     1: a > b
//    -1: b > a
int apa_cmp(uint16_t const * const a, uint16_t const * const b, uintmax_t const size);

//������������ ��������� ���������� �������� ������������ �����
// a - ������ ��� ������ ����� �������� size ����
uint16_t* apa_gen_rand(uint16_t* const a, uintmax_t const size);

//������������ ������ �������� ������������ ����� � ����������������� ������� (������� �� ������� ��������)
// � - ����� �������� size ����
void apa_print(uint16_t const * const a, uintmax_t const size);

//������������ ���������� �������� ������������ ����� �������� ������
// a - ����� �������� size ����
// value - �������� ��� ����������
void apa_fill(uint16_t* const a, uintmax_t const size, uint16_t const value);

//������������ ��������� ���� ������� ����������� �����
// a, b - ���������� ����� ������� size_a � size_b ����, ��������������
// c - ������������ a � b, �������� size_a + size_b ����
void apa_mult(uint16_t const * const a, uintmax_t const size_a, uint16_t const * const b, uintmax_t const size_b, uint16_t* const c);

//������������ ��������� �������� ������������ ����� �� �����
// a - ���������� ����� ������� size ����
// b - ��������� ������� � 1 �����
// c - ������������ a � b, �������� size ����
//  ������������ ��������:
//     ����� ��������
uint16_t apa_mult_word(uint16_t const * const a, uintmax_t const size, uint16_t const b, uint16_t* const c);

//������������ ������� �������� ������������ ����� �� �����
// a - ������� ����� ������� size ����
// b - �������� ������� � 1 �����
// c [Nullable] - ������� a � b, �������� size ����
// r [Nullable] - ������� �� ������� a �� b, �������� 1 �����
//  ������������ ��������:
//     ������� �� �������
uint16_t apa_div_word(uint16_t const * const a, uintmax_t const size, uint16_t const b, uint16_t* const c, uint16_t* const r);

//������������ ���������� ������ �������� ������������ ����� �������
// a - ����� �������� size ����, �������� ����� ��������� �������� ����� b
void apa_assign(uint16_t* const a, uint16_t const * const b, uintmax_t size);

//������������ ������� ���� ������� ����������� �����
// U - �������, �������� sizeU ����
// V - ��������, �������� sizeV ����
// Q [Nullable] - �������, �������� sizeU ����
// R [Nullable] - �������, �������� sizeV ����
void apa_div(uint16_t const * const U, uint16_t const * const V, uint16_t* const Q,	uint16_t* const R, uintmax_t sizeU,	uintmax_t sizeV);
#endif