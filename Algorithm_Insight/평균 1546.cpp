#include <iostream>

using namespace std;

double arr[1001], MAX=0;
double avg=0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		MAX = (MAX > arr[i]) ? MAX : arr[i];
	}

	for (int i = 0; i < n; i++) {
		avg += arr[i] / MAX;
	}

	cout << avg / n*100;
}