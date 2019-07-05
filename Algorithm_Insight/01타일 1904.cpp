#include <iostream>
#include <string.h>

using namespace std;

int main() {
	//다이나믹 프로그래밍
	//피보나치 수열과 비슷하다.
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