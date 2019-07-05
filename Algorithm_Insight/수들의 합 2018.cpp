#include <iostream>

using namespace std;

int main() {
	int n, sum=0,Count=0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (sum > n) break;
			sum += j;
			if (sum == n) {
				Count++; break;
			}
		}sum = 0;
	}

	cout << Count;
}