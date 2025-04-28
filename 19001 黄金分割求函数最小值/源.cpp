#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
#include<iomanip>

double  GOLDEN = 0.6180339887498948l;
double  A[51], B[51], L_X1[51], L_X2[51];
double  X1[51], X2[51], Y1[51], Y2[51];


double  EPS = 0.4E-8;
double f(double x) {
    return exp(x) - 2 * x * x;
}


int GoldenSection(double A0, double B0)
{
    int K;
    A[0] = A0;
    B[0] = B0;
    L_X2[0] = (B[0] - A[0]) * GOLDEN;
    L_X1[0] = L_X2[0] * GOLDEN;
    X2[0] = A[0] + L_X2[0];
    Y2[0] = f(X2[0]);
    X1[0] = A[0] + L_X1[0];
    Y1[0] = f(X1[0]);
    for (K = 1; K < 51; K++)
    {
        L_X2[K] = L_X1[K - 1];
        L_X1[K] = L_X2[K] * GOLDEN;
        if (Y1[K - 1] < Y2[K - 1])
        {
            A[K] = A[K - 1]; B[K] = X2[K - 1];
            X2[K] = X1[K - 1];
            Y2[K] = Y1[K - 1];
            X1[K] = A[K] + L_X1[K];
            Y1[K] = f(X1[K]);
        }
        else
        {
            A[K] = X1[K - 1]; B[K] = B[K - 1];
            X1[K] = X2[K - 1];
            Y1[K] = Y2[K - 1];
            X2[K] = A[K] + L_X2[K];
            Y2[K] = f(X2[K]);
        }
        if (L_X1[K] < EPS) break;
    }
    if (K < 51)K++;
    int RN = K;

    printf("%.9lf %.9lf %.9lf %.9lf ", A[RN - 1], X1[RN - 1], X2[RN - 1], B[RN - 1]);
    printf("%.9lf %.9lf\n", Y1[RN - 1], Y2[RN - 1]);

    return 0;
}



int main()
{
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        double a0, b0;
        std::cin >> a0 >> b0;
        GoldenSection(a0, b0);
    }
}