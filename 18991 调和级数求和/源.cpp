#include<iostream>
#include<iomanip>
#include<cmath>

signed main() {
	std::cout << std::fixed << std::setprecision(14);
	int m;
	std::cin >> m;
	int k;
	for (int i = 0; i < m; i++) {
		std::cin >> k;
		double res1 = 0;
		double res2 = 0;
		for (double j = 1; j <= k; j++) {
			res1 += (1.0 / j);
		}

		for (double j = k; j >= 1; j--) {
			res2 += (1.0 / j);
		}
		std::cout << res1 << " " << res2 << std::endl;
	}
}