#include <iostream>
#include <math.h>
using namespace std;

int arr[100], n, m, Min=10005, Sum=0;
bool check = false;
int main() {
	for (int i = 0; i < 100; i++) arr[i] = pow((i + 1), 2);

	cin >> m >> n;

	for (int i = 0; i < 100; i++) {
		if (arr[i] < m) continue;
		if (arr[i] >= m && arr[i]<=n) {
			Min = (Min > arr[i]) ? arr[i] : Min; Sum += arr[i];
			check = true;
		}if (arr[i] > n) break;
	}

	if (check) cout << Sum << '\n' << Min;
	else cout << -1;
}