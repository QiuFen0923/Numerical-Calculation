#include<iostream>
#include<iomanip>
#include<cmath>
#define int long long
#define err 0.005 // 精确到小数点后2位有效数


signed main() {
	std::cout << std::fixed << std::setprecision(2);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		double x;
		std::cin >> x;
		double y1 = log(x);
		double delta_x = 1; // 步长
		double result1 = 50; // 随意设定的初始导数值
		double flag = 50; // 记录导数变化量
		while (flag > err) { // 变化量<0.005时停止
			double result2 = (log(x + delta_x) - log(x)) / delta_x;
			flag = fabs(result1 - result2);
			result1 = result2;
			delta_x /= 2.0;
		}
		std::cout << result1 << std::endl;
	}
}