//**************************************************************************************
// Пример исследования реализации функции sin(x)/x = 1 - x^2/3! + x^4/5! - x^6/7! + x^8/9!...
// sinx_divx: март 2020:: nvnulstu@gmail.com 
//**************************************************************************************
#pragma once
#include "vpv-lab2.h"

// массив коэффициентов
float flCoef[LEN_POLINOM] = {KOEF1, KOEF2, KOEF3, KOEF4, KOEF5, KOEF6, KOEF7, KOEF8, KOEF9, KOEF10, KOEF11, KOEF12,
                             KOEF13,};

// Факториал для int - не может иметь n > 12
double factorial(int n) {
	double fact = n;
	while (--n > 0) {
		fact *= n;
	}
	return fact;
}

// Библиотечная реализация функции на основе библиотеки math.h для измерения
float flMathFunc(float x) {
	return (float)log(cos(x));
}

// Цикл формулы ряда 1 - x^2/3! + x^4/5! - x^6/7! + x^8/9! через цикл sum += x^2n/(2n+1)!
float flCyNoGorn(float x) {
    double sum = 0;
    float test = 0.987;

//    for (int n = 10; n < 20; n++) {
//        sum = ((n * factorial(2 * n) / (pow(2, 2 * n - 1) * (pow(2, 2 * n) - 1) * abs(bern(2*n)) * pow(1, 2 * n))
//                ));
//        continue;
//    }

    if (x >= test){
        printf("");
    }

	for (int n = 1; n < LEN_POLINOM; n++) {
        sum -= ((pow(2, 2 * n - 1) * (pow(2, 2 * n) - 1) * abs(bern(2*n)) * pow(x, 2 * n))
                / (n * factorial(2 * n)));
	}
	return (float)sum;
}

// Непосредственная реализация формулы 1 - x^2/3! + x^4/5! - x^6/7! + x^8/9!
float flNoCyNoGorn(float x) {
    return -((pow(2, 1) * (pow(2, 2) - 1) * abs(bern(2)) * pow(x, 2))) / (1 * factorial(2)) -
           ((pow(2, 3) * (pow(2, 4) - 1) * abs(bern(4)) * pow(x, 4))) / (2 * factorial(4)) -
           ((pow(2, 5) * (pow(2, 6) - 1) * abs(bern(6)) * pow(x, 6))) / (3 * factorial(6)) -
           ((pow(2, 7) * (pow(2, 8) - 1) * abs(bern(8)) * pow(x, 8))) / (4 * factorial(8)) -
           ((pow(2, 9) * (pow(2, 10) - 1) * abs(bern(10)) * pow(x, 10))) / (5 * factorial(10)) -
           ((pow(2, 11) * (pow(2, 12) - 1) * abs(bern(12)) * pow(x, 12))) / (6 * factorial(12)) -
           ((pow(2, 13) * (pow(2, 14) - 1) * abs(bern(14)) * pow(x, 14))) / (7 * factorial(14)) -
           ((pow(2, 15) * (pow(2, 16) - 1) * abs(bern(16)) * pow(x, 16))) / (8 * factorial(16)) -
           ((pow(2, 17) * (pow(2, 18) - 1) * abs(bern(18)) * pow(x, 18))) / (9 * factorial(18)) -
           ((pow(2, 19) * (pow(2, 20) - 1) * abs(bern(20)) * pow(x, 20))) / (10 * factorial(20)) -
           ((pow(2, 21) * (pow(2, 22) - 1) * abs(bern(22)) * pow(x, 22))) / (11 * factorial(22)) -
           ((pow(2, 23) * (pow(2, 24) - 1) * abs(bern(24)) * pow(x, 24))) / (12 * factorial(24)) -
           ((pow(2, 25) * (pow(2, 26) - 1) * abs(bern(26)) * pow(x, 26))) / (13 * factorial(26));
}
// Цикл схемы Горнера
float flCycleGorn(float x) {
	float x2 = x * x, sum = flCoef[LEN_POLINOM-1];
	for (int n = LEN_POLINOM-1; n > 0; n--)
		sum = sum * x2 - flCoef[n-1];
	return sum * x2;
}

// Бесцикловая схема Горнера классическая sin(x)/x = (((a[4]*x^2 + a[3])*x^2 + a[2])*x^2 + a[1])*x^2 + a[0]
float flNoCyGornArr(float x) {
	float x2 = x * x; // за скобки выносится x^2
    return ((((((((((((flCoef[12] * x2 - flCoef[11]) * x2 - flCoef[10]) * x2 - flCoef[9]) * x2 - flCoef[8]) * x2 -
                   flCoef[7]) * x2 - flCoef[6]) * x2 - flCoef[5]) * x2 - flCoef[4]) * x2 - flCoef[3]) * x2 -
              flCoef[2]) * x2 - flCoef[1]) * x2 - flCoef[0]) * x2;
}

// Бесцикловая схема Горнера - константы вместо элементов массива
float flNoCyGornConst(float x) {
	float x2 = x * x;
	return ((((((((((((KOEF13 * x2 - KOEF12) * x2 - KOEF11) * x2 - KOEF10) * x2 - KOEF9) * x2 - KOEF8) * x2 - KOEF7) *
                 x2 - KOEF6) * x2 - KOEF5) * x2 - KOEF4) * x2 - KOEF3) * x2 - KOEF2) * x2 - KOEF1) * x2;
}

