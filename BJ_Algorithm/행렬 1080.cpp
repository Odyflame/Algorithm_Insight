
/*2015112119 by 이현재*/

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

int n, m;
int A[50][50];
int B[50][50];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &A[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%1d", &B[i][j]);
		}
	}

	vector<pair<pair<int, int>, int>> vec;
	int Sum = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < m - 2; j++) {
			
			if (A[i][j] != B[i][j]) {//원소가 다르면 바꾸어 주어야 한다.
				Sum++;
				for (int k = i; k < i + 3; k++) {
					for (int h = j; h < j + 3; h++) {
						A[k][h] = 1 - A[k][h];
					}
				}

			}

		}
	}


	bool checkflag = true;

	try {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (A[i][j] != B[i][j]) {
					checkflag = false;
					throw - 1;
				}
			}
		}
	}
	catch (...) {
		cout << -1;
	}

	if (checkflag) cout << Sum;
}