#include <iostream>

using namespace std;

int isGcd(int a) {
	if (a == 1) return 0;
	else {
		for (int i = 2; i < a; i++) {
			if ((a%i) == 0)
				return 0;
		}
	}
	return 1;
}

int main() {
	ios::sync_with_stdio(false);

	int N;
	int arr[50];
	int count = 0;
	int a=0, b=0;
	cin >> N;

	while (N) {

		for (int i = 3; i < N; i++) {
			if (isGcd(i) == 1)
				arr[count++] = i;
		}

		for (int i = 0; i < count; i++) {
			for (int j = i; j < count; j++) {
				if ((arr[i] + arr[j]) == N)
				{
					a = arr[i];
					b = arr[j];
					break;
				}
			}

			if (a != 0)
			{
				cout << N << " = " << a << " + " << b << endl;
				break;
			}
		}
		a = 0; b = 0;
		cin >> N;
	}
}