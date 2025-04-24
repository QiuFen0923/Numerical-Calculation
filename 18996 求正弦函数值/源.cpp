#include<iostream>
#include<iomanip>
#include<cmath>

#define PI 3.1415926535897932l

// ̩�ռ���չ��
// ���� x �Ĵ�С�����ؼ��� sin(x) �����̩��չ������ N
// xԽС��̩��չ������Խ�죬��Ҫ������Խ�٣���֮��Ҫ����������֤����

int GetSinItemNumber(double x) {
    int N = 14;
    if (x < 0)x = -x;
    if (x <= PI / 8) N = 6;
    else if (x <= PI / 4) N = 8;
    else if (x <= PI / 2) N = 10;
    else if (x <= 3 * PI / 4) N = 12;
    return N;
}

double SINTNV(double x) {

    double y = 1.0;
    int N = GetSinItemNumber(x);
    int K = N * 2;
    double x_squared = x * x;
    while (K > 0) {
        y = 1.0 - y * x_squared / (K * (K + 1));
        K -= 2; // ÿ�δ�������
    }
    return y * x;
}


signed main() {
	std::cout << std::fixed << std::setprecision(14);
	int m;
	std::cin >> m;
	double x;
	for (int i = 0; i < m; i++) {
        std::cin >> x;
        std::cout << SINTNV(x) << std::endl;
	}
}