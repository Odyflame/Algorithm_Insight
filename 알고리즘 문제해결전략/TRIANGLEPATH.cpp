/*
*2015112119 by 이현재
*/
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[100][100], cache[100][100];
int c, n;

//그냥 재귀로 하는것 스택 오버플로가 발생할수있다.
//int trianglepath(int y, int x, int sum) {
//	if (y >= n)	return sum;
//
//	return max(trianglepath(y + 1, x, sum + arr[y][x]), trianglepath(y + 1, x + 1, sum + arr[y][x]));
//}

int trianglepath(int y, int x) {
	if (y == n - 1) return arr[y][x];

	int& ret = cache[y][x];
	if (ret != -1) return ret;

	return ret = max(trianglepath(y + 1, x), trianglepath(y + 1, x + 1)) + arr[y][x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> n;

		memset(cache, -1, sizeof(cache));

		for (int j = 0; j < n; j++) {
			for (int k = 0; k <= j; k++) {
				cin >> arr[j][k];
			}
		}

		cout<< trianglepath(0, 0)<<endl;
	}
}