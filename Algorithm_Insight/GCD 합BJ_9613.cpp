#include <iostream>
#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main() {
	ios::sync_with_stdio(false);
	int m, z;
	int arr[105];
	long long int sum = 0;

	cin >> z;
	for (int i = 0; i < z; i++) {
		cin >> m;
		for (int j = 0; j < m; j++) {
			cin >> arr[j];
		}

		for (int j = 0; j < m - 1; j++) {
			for (int k = j+1; k < m; k++) {
				sum += gcd(arr[j], arr[k]);
			}
		}

		cout << sum << endl;
		sum = 0;
	}

	return 0;
}