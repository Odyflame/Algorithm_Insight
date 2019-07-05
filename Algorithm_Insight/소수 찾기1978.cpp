#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	int n;
	int arr[100];
	int count = 0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	count = n;
	
	for (int i = 0; i < n; i++) {

		if (arr[i] == 1) count--;
		else if (arr[i] == 2) continue;
		else if ((arr[i] % 2) == 0 && arr[i] != 2) count--;
		else {
			for (int j = arr[i] - 1; j > 1; --j) {
				if (arr[i] % j == 0) {
					count--;
					break;
				}
			}
		}
	}
	
	cout << count;
}