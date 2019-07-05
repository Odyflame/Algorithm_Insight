#include <iostream>

using namespace std;

double arr[2][2], MAX=0, sum=0;
int Count = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> arr[0][0] >> arr[0][1];
	cin >> arr[1][0] >> arr[1][1];
	MAX = (arr[0][0] / arr[1][0]) + (arr[0][1] / arr[1][1]);
	
	for (int i = 0; i < 4; i++) {

		double temp = arr[0][0];
		arr[0][0] = arr[1][0];
		arr[1][0] = arr[1][1];
		arr[1][1] = arr[0][1];
		arr[0][1] = temp;

		sum = (arr[0][0] / arr[1][0]) + (arr[0][1] / arr[1][1]);

		if (MAX < sum) {
			MAX = sum;
			Count=i+1;
		}
	}

	cout << Count;
}