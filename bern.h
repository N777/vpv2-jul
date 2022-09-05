#pragma once
#include "vpv-lab2.h"

//Подсчет чисел Бернулли
double С[100][100];
double usedC[100][100];
int rec(int n, int k)
{
    if (usedC[n][k])
        return С[n][k];
    else if (n == k || k == 0) {
        usedC[n][k] = 1;
        С[n][k] = 1;
    }
    else if (k == 1) {
        usedC[n][k] = 1;
        С[n][k] = n;
    }
    else {
        С[n][k] = rec(n - 1, k - 1) + rec(n - 1, k);
        usedC[n][k] = 1;
    }
    return С[n][k];
}
double B[100];
double used[100];
double bern(int n) {
    double s, t;
    if (used[n])
        return B[n];
    else if (n == 0) {
        used[n] = 1;
        B[n] = 1.;
    }
    else if (n == 1) {
        used[n] = 1;
        B[n] = -0.5;
    }
    else {
        used[n] = 1;
        s = 0;
        for (int k = 1; k <= n; k++) {
            t = bern(n - k);
            s = s + rec(n + 1, k + 1) * t;
        }
        B[n] = (double)((-1.) * s) / (double)(n + 1);
        return B[n];
    }
    if (n % 2 == 1 && n > 1) {
        B[n] = 0.;
        used[n] = 1;
    }
    return B[n];
}
