#include <iostream>

using namespace std;


int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

//최소공배수*최대공약수 = 두수의 곱
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