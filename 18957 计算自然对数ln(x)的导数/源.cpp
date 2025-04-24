#include<iostream>
#include<iomanip>
#include<cmath>
#define int long long
#define err 0.005 // ��ȷ��С�����2λ��Ч��


signed main() {
	std::cout << std::fixed << std::setprecision(2);
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		double x;
		std::cin >> x;
		double y1 = log(x);
		double delta_x = 1; // ����
		double result1 = 50; // �����趨�ĳ�ʼ����ֵ
		double flag = 50; // ��¼�����仯��
		while (flag > err) { // �仯��<0.005ʱֹͣ
			double result2 = (log(x + delta_x) - log(x)) / delta_x;
			flag = fabs(result1 - result2);
			result1 = result2;
			delta_x /= 2.0;
		}
		std::cout << result1 << std::endl;
	}
}