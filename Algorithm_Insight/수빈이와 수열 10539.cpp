#include <iostream>

using namespace std;

int main() {
	int n, B[101], A[101], sum=0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> B[i];
		A[i] = (i + 1)*B[i] - sum;
		sum += A[i];
	}

	for (int i = 0; i < n; i++)	cout << A[i] << " ";
}