#include <iostream>

using namespace std;


int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

//�ּҰ����*�ִ����� = �μ��� ��
int gcm(int a, int b) {
	int c = gcd(a, b);

	return a * b / c;
}

int main() {
	int n, m, z;
	cin >> z;
	for (int i = 0; i < z; i++) {
		cin >> n >> m;
		cout << gcm(n, m)<<endl;
	}
}