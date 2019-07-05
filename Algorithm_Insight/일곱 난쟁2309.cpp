/*
*2015112119 by ÀÌÇöÀç
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

	int arr[9] = { 0 };
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	bool check = true;
	
	for (int i = 0; i < 9-1; i++) {
		for (int j = i+1; j < 9; j++) {
			if ((sum - 100) == (arr[i] + arr[j]))
			{
				arr[i] = -1; arr[j] = -1;
				check = false;
				break;
			}
		}
		if (check == false) break;
	}

	sort(arr, arr+9);

	for (int i = 2; i < 9; i++) {
			cout << arr[i] << '\n';
	}
}