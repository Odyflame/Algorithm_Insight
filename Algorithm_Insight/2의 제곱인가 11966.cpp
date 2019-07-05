#include <iostream>

using namespace std;

int main() {
	long long n;
	bool check = false;
	cin >> n;

	while (1) {
		if (n == 1) break;
		if (n % 2 == 1) { check = true; break; }
		n /= 2;
	}

	if (!check) cout << 1;
	else cout << 0;
}