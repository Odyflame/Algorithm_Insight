#include <iostream>

using namespace std;

int main() {
	int n, sum = 0, i, check;
	cin >> n;

	for (i = 1; i < n; i++) {
		sum += i;
		if (sum >= n) break;
	}

	check = sum - n;

	if (n == 1) cout << 1 << "/" << 1;
	else if (n == 2) cout << 1 << "/" << 2;
	else if (i % 2 == 1)cout << 1 + check << "/" << i - check;
	else cout << i - check << "/" << 1 + check;
}