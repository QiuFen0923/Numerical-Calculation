#include<iostream>
#include<cmath>
#include<iomanip>

#define PI 3.1415926535897932l

int GetCosItemNum(double x) {
    int N = 14;
    if (x < 0)x = -x;
    if (x <= PI / 8) N = 6;
    else if (x <= PI / 4) N = 8;
    else if (x <= PI / 2) N = 10;
    else if (x <= 3 * PI / 4) N = 12;
    return N;
}

double COSTNV(double x) {

    double y = 1.0;
    int N = GetCosItemNum(x) + 1;
    int K = N * 2;
    double x_squared = x * x;
    while (K > 0) {
        y = 1.0 - y * x_squared / (K * (K - 1));
        K -= 2; // 每次处理两项
    }
    return y;
}


signed main() {
    std::cout << std::fixed << std::setprecision(14);
    int m;
    std::cin >> m;
    double x;
    for (int i = 0; i < m; i++) {
        std::cin >> x;
        std::cout << COSTNV(x) << std::endl;
    }
}