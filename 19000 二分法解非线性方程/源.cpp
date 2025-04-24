#include<iostream>
#include<iomanip>

#define EPS 0.4e-14
double x[51], y[51], a[51], b[51];

double function(double x) {
	return x * x * x - 2.0 * x - 2;
}

void Bi_Section(double a0, double b0) {
	int k;
	double error;
	a[0] = a0;
	b[0] = b0;
	double f_a = function(a[0]);
	x[0] = (a[0] + b[0]) / 2;
	y[0] = function(x[0]);
	for (k = 1; k < 51; k++) {
		if (f_a * y[k - 1] > 0) {
			a[k] = x[k - 1];
			b[k] = b[k - 1];
		}
		else {
			a[k] = a[k - 1];
			b[k] = x[k - 1];
		}
		x[k] = (a[k] + b[k]) / 2;
		y[k] = function(x[k]);
		error = (b[k] - a[k]) / 2;

		if (error < EPS) {
			break;
		}
	} 
	std::cout << a[k] << " " << b[k] << " " << x[k] << std::endl;
}



signed main() {
	std::cout << std::fixed << std::setprecision(15);
	int m;
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		double a0, b0;
		std::cin >> a0 >> b0;
		Bi_Section(a0, b0);
	}
}