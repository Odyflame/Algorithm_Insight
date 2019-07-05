#include <iostream>

using namespace std;

int arr[1000002];
void eratos() {
	for (int i = 2; i*i < 1e6; i++) {
		if (!arr[i]) {
			for (int j = i * i; j < 1e6; j += i) {
				arr[j] = 1;
			}
		}
	}
	arr[1] = 1;
}

int main() {
	eratos();

	int n=1;
	
	while (n) {
		scanf("%d", &n);
		bool check = false;

		for (int i = 3; i < n; i+=2) {
			if (!arr[i] && !arr[n - i]) {
				cout << n << " = " << i << " + " << n - i << endl;
				check = true;
				break;
			}
		}
		if (!check)
			printf("Goldbach's conjecture is wrong.");
	}
}