/*
Агафонов Александр, группа 319
*/

#include "LibAPA.h"

//Подпрограмма умножения двух длинных беззнаковых чисел
// a, b - умножаемые числа длинной size_a и size_b слов, соответственно
// c - произведение a и b, размером size_a + size_b слов
void apa_mult(uint16_t const * const a, uintmax_t const size_a, uint16_t const * const b, uintmax_t const size_b, uint16_t* const c)
{
	//Слово переноса разряда при умножении
	uint16_t d;

	//Результат элементарного умножения слов
	uint32_t T;

	//Размер числа c size_a + size_b слов
	uintmax_t const size_c = size_a + size_b;

	//Обнуление результата
	apa_fill(c, size_c, 0);

	for (uintmax_t i = 0; i < size_a; i++)
	{
		//Обнуление переноса
		d = 0;

		for (uintmax_t j = 0; j < size_b; j++)
		{
			//Элементарное умножение слов чисел с переносом
			T = (uint32_t)c[i + j] + (uint32_t)a[i] * (uint32_t)b[j] + (uint32_t)d;

			//Сохранение полученного при умножении слова
			c[i + j] = LOWORD(T);

			//Перенос разряда
			d = HIWORD(T);
		}

		//Сохранение переноса в следующий разряд
		c[i + size_b] = d;
	}
}

//Подпрограмма умножения длинного беззнакового числа на слово
// a - умножаемое число длинной size слов
// b - множитель длинной в 1 слово
// c - произведение a и b, размером size слов
//  Возвращаемые значения:
//     слово переноса
uint16_t apa_mult_word(uint16_t const * const a, uintmax_t const size, uint16_t const b, uint16_t* const c)
{
	//Результат элементарного умножения слов
	uint32_t T;

	//Слово переноса разряда при умножении
	uint16_t d = 0;

	for (uintmax_t i = 0; i < size; i++)
	{
		//Элементарное умножение слов с переносом
		T = (uint32_t)a[i] * (uint32_t)b + (uint32_t)d;

		//Сохранение полученного при умножении слова
		c[i] = LOWORD(T);

		//Перенос разряда
		d = HIWORD(T);
	}

	//Возврат слова переноса
	return d;
}

//Подпрограмма деления длинного беззнакового числа на слово
// a - делимое число длинной size слов
// b - делитель длинной в 1 слово
// c [Nullable] - частное a и b, размером size слов
// r [Nullable] - остаток от деления a на b, размером 1 слово
//  Возвращаемые значения:
//     остаток от деления
uint16_t apa_div_word(uint16_t const * const a, uintmax_t const size, uint16_t const b, uint16_t* const c, uint16_t* const r)
{
	//Элементарное делимое
	uint32_t T = 0;

	if (b == 0)
	{
		//Деление на ноль
		return UINT16_MAX;
	}

	for (uintmax_t i = size; i > 0; i--)
	{
		//Старшее слово - остаток предыдущего элементарного деления
		T <<= sizeof(uint16_t) * 8;

		//Младшее слово - очередное слово делимого числа
		T |= a[i - 1];

		//Сохранение результата элементарного деления
		if (c != NULL) c[i - 1] = LOWORD(T / (uint32_t)b);

		//Сохраниние остатка
		T %= b;
	}

	if (r != NULL)
	{
		//Сохраниние остатка в переменную r, если она передана
		*r = LOWORD(T);
	}

	//Возврат остатка
	return LOWORD(T);
}

//Подпрограмма деления двух длинных беззнаковых чисел
// U - делимое, размером sizeU слов
// V - делитель, размером sizeV слов
// Q [Nullable] - частное, размером sizeU слов
// R [Nullable] - остаток, размером sizeV слов
void apa_div(uint16_t const * const U, uint16_t const * const V, uint16_t* const Q, uint16_t* const R, uintmax_t sizeU, uintmax_t sizeV)
{
	uint16_t q, buf1, buf2;                /* для промежуточного хранения */
	uint16_t U2[MAX_DIV_OPERAND_SIZE + 1],   /* для нормализованного U */
		V2[MAX_DIV_OPERAND_SIZE + 1],   /* для нормализованного V */
		R2[MAX_DIV_OPERAND_SIZE + 1];	/* для промежуточного умножения */
	uint32_t inter;                     /* для промежуточных операций */
	uintmax_t i, j, k;                          /* индексные переменные */
	uint16_t d;                            /* нормализующий множитель */

										/*--- Проверки, подготовка: */
	if (R != NULL) apa_fill(R, sizeV, 0);                /* если адрес остатка R не 0, обнуляем остаток */
	if (Q != NULL) apa_fill(Q, sizeU, 0);                /* если адрес частного Q не 0, обнуляем частное */

	// ReSharper disable once CppPossiblyErroneousEmptyStatements
	for (i = sizeV; (i > 0)&(!V[i - 1]); i--);  /* анализ делителя, отсекаем старшие незначащие нули */
	sizeV = i;                          /* новый размер делителя */
	if (sizeV == 0) return;                  /* исключение "Деление на ноль" (просто уходим) */

	// ReSharper disable once CppPossiblyErroneousEmptyStatements
	for (k = sizeU; (k > 0)&(!U[k - 1]); k--);  /* анализ делимого, отсекаем старшие незначащие нули */
	sizeU = k;                          /* новый размер делимого */

	if (sizeV > sizeU)                     /* если делитель больше делимого, то */
	{
		if (R != NULL) apa_assign(R, U, sizeU);        /* остаток равен делимому */
		return;                        /* уходим */
	}
	if (sizeV == 1)                   /* если делитель - 1 слово, то */
	{
		apa_div_word(U, sizeU, V[0], Q, R);     /* применяем упрощенный алгоритм */
		return;                        /* уходим */
	}

	/*--- Нормализация: */
	d = (uint16_t)(((uint32_t)UINT16_MAX + 1) / ((uint32_t)V[sizeV - 1] + 1)); /* нормализующий множитель */
	if (d != 1)                            /* если d не 1, */
	{
		V2[sizeV] = apa_mult_word(V, sizeV, d, V2);   /* умножаем V на d */
		U2[sizeU] = apa_mult_word(U, sizeU, d, U2);   /* умножаем U на d */
	}
	else
	{                                   /* если d == 1, */
		apa_assign(V2, V, sizeV);             /* V2 = V */
		V2[sizeV] = 0;
		apa_assign(U2, U, sizeU);             /* U2 = U */
		U2[sizeU] = 0;
	}

	/*--- Основной цикл */
	for (j = sizeU; j >= sizeV; j--)           /* организация главного цикла по j (sizeU-sizeV раз) */
	{
		/*--- Очередное слово частного */
		inter = MAKEDWORD(U2[j], U2[j - 1]); /* пригодится */
		if (U2[j] == V2[sizeV - 1])          /* если старшие слова равны, */
			q = UINT16_MAX;                 /* слово частного q = MAXDIGIT */
		else {                        /* иначе */
			q = (uint16_t)(inter / V2[sizeV - 1]);/* j-е слово частного q находим делением */
											   /* если q великоват, */

											   /*--- Коррекция слова частного */
			if (((uint32_t)V2[sizeV - 2] * q) > (MAKEDWORD((uint16_t)(inter%V2[sizeV - 1]), U2[j - 2])))
			{
				q--;    /* коррекция слова частного уменьшением q на 1 */
			}
		}

		 /*--- Вычитание кратного делителя */
		buf1 = apa_mult_word(V2, sizeV, q, R2);  /* умножаем V на q */
		buf2 = apa_sub(U2 + j - sizeV, R2, sizeV, U2 + j - sizeV);/* вычитаем результат умножения */
		inter = (uint32_t)U2[j] - buf1 - buf2;
		//U2[j] = LOWORD(inter); //Never used

		/*--- Коррекция остатка и частного */
		if (HIWORD(inter))              /* если результат шага отрицательный, */
		{                               /* компенсирующее сложение */
			/*buf2 = */apa_add(U2 + j - sizeV, V2, sizeV, U2 + j - sizeV);
			//U2[j] += buf2; //Never used
			q--;                        /* коррекция слова частного q на 1 */
		}
		if (Q != NULL)                           /* если адрес частного Q не 0, */
			Q[j - sizeV] = q;               /* запоминаем j-е слово частного q */
	}

	/*--- Завершение */
	if (R != NULL)                               /* если адрес остатка R не 0, */
	{
		apa_div_word(U2, sizeV, d, R, NULL);   /* денормализация остатка R */
	}
}
