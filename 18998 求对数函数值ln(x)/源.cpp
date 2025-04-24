#include<iostream>
#include<iomanip>
#include<cmath>

#define log2 0.69314718055994531
#define log10 2.3025850929940457
#define min_num 0.5E-100

int GetLogItemNum(double a) {
	int N;
	if (a <= 1) N = -1;
	else if (a <= 1.2) N = 7;
	else if (a <= 1.5) N = 10;
	else if (a <= 2.0) N = 15;
	else if (a <= 3.0) N = 24;
	else if (a <= 10) N = 84;
	else N = 84 * (int)(a / 10);
	return N;
}

double LOGTV(double a) {

	int N = 0, K, NK;
	double x, xx, y;
	x = (a - 1) / (a + 1);
	xx = x * x;
	N = GetLogItemNum(a);
	NK = N * 2 + 1;
	y = 1.0 / NK;

	for (K = N; K > 0; K--) {
		NK -= 2;
		y = 1.0 / NK + xx * y;
	}

	return 2.0 * x * y;
}

double LOG(double a) {

	int TYPE = 0, K = 0;
	double x0, y, power = 2.0;
	double x = a;

	if (x < min_num) 
		return -100;

	if (x < 1) {
		x = 1.0 / x, TYPE = 1;
	}

	while (power < x) {
		power *= 2.0;
		K++;
	}

	y = LOGTV(2.0 * x / power) + K * log2;
	if (TYPE == 1)
		y = -y;

	return y;
}


double LOG10(double a) {
	return LOG(a) / log10;
}

double LOGA(double a, double x) {
	return LOG(x) / LOG(a);
}


signed main() {
	std::cout << std::fixed << std::setprecision(14);
	int m;
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		double x;
		std::cin >> x;
		std::cout<<LOG(x)<<std::endl;
	}
}
