#include<iostream>
#include<iomanip>

#define EPOW10  22026.465794806717

double EXPTV(double x) {
	int N = 23;
	double y = 1.0;
	if (x <= 0.5) N = 14;
	else if (x <= 1.0) N = 18;
	else N = 23;
	while (N > 0) {
		y = 1.0 + y * x / N;
		N--;
	}
	return y;
}


double EXP(double x) {
	bool type = false;
	double y = 1.0;
	if (x < 0) {
		type = true;
		x = -x;
	}

	while (true) {
		if (x > 10) {
			x -= 10;
			y *= EPOW10;
		}
		else if (x > 2) {
			x -= 2;
			y *= EXPTV(2);
		}
		else break;
	}
	y *= EXPTV(x);
	if (type == true) {
		return 1.0 / y;
	}
	else return y;
}


signed main() {
	std::cout << std::fixed << std::setprecision(14);
	int m;
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		double x;
		std::cin >> x;
		std::cout << EXP(x) << std::endl;
	}
}