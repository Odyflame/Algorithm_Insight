#include <iostream>
#include <string.h>

using namespace std;

int main() {
	//���̳��� ���α׷���
	//�Ǻ���ġ ������ ����ϴ�.
	long long n, sum = 0, a, b;

	cin >> n;

	a = 1; b = 2; 

	for (int i = 2; i < n; i++) {
		sum = a + b;
		a = b % 15746;
		b = sum % 15746;
		sum %= 15746;
	}

	cout << sum;
}