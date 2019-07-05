#include <iostream>

using namespace std;

//���ڵ�
//int gcd(int n, int m) {
//	if (n < m)
//	{
//		int temp = m;
//		m = n;
//		n = temp;
//	}
//	
//	while (n != 0) {
//		if (n % m == 0) {
//			return m;
//		}
//		else {
//			int temp_m = n % m;
//			n = m;
//			m = temp_m;
//			gcd(n, m);
//		}
//	}
//	return 0;
//}

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int gcd2(int a, int b)
{
	int c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
//�ּҰ����*�ִ����� = �μ��� ��
int gcm(int a, int b) {
	int c = gcd(a, b);

	return a * b / c;
}

int main() {
	int n, m;

	cin >> n >> m;

	cout << gcd(n, m) << endl;
	cout << gcm(n, m);
}