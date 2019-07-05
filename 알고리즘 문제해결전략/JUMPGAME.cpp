#include <iostream>
using namespace std;

int c, n, arr[100][100];
int check[100][100];

int jumpgame(int y, int x) {
	

	if (y == (n-1) && x == (n-1)) return 1;
	if (y > (n-1) || x > (n-1)) return 0;

	int& ret = check[y][x];

	if (ret != -1) return ret;

	int jumpsize = arr[y][x];
	return ret = (jumpgame(y + jumpsize, x) || jumpgame(y, jumpsize + x));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				check[j][k] = -1;
			}
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				cin >> arr[j][k];
			}
		}

		if (jumpgame(0, 0)==1) cout << "YES" << endl;
		else cout << "NO" << endl;

	}

	return 0;
}