
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

int A[1001][1001];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	}

	string srr = "";
	string srr2 = "";

	if (n % 2 == 1) {//n이 홀수면 무조건 다 합칠수있다.
		for (int i = 0; i < m - 1; i++) cout << "R";
		
		for (int i = 0; i < n - 1; i += 2) {
			cout << "D";
			for (int j = 0; j < m - 1; j++) cout << "L";
			
			cout << "D";
			for (int j = 0; j < m - 1; j++) cout << "R";
		}

		/*for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				for (int j = 0; j < m - 1; j++) srr += "R";
				if (i != n - 1) {
					srr += "D";
				}
			}
			else {
				for (int j = 0; j < m - 1; j++) srr += "L";
				srr += "D";
			}
		}
		cout << srr;*/
	}
	else if( m % 2 == 1){//m이 홀수라도 무조건 다 합칠수있다.

		for (int i = 0; i < n - 1; i++) cout << "D";

		for (int j = 0; j < m - 1; j += 2) {
			cout << "R";
			for (int i = 0; i < n - 1; i++) cout << "U";
			cout << "R";
			for (int i = 0; i < n - 1; i++) cout << "D";
		}

		/*for (int j = 0; j < m; j++) {
			if (j % 2 == 0) {
				for (int i = 0; i < n - 1; i++) cout<< "D";
				if (j != m - 1) cout<< "R";
			}
			else {
				for (int i = 0; i < n - 1; i++)cout<< "U";
				cout<< "R";
			}
		}*/
	}
	else {//코드가 같은데 틀리는 이유가 무엇인가
		
		pair<int, int> temp = { 0,1 };

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (A[i][j] < A[temp.first][temp.second]) temp.first = i; temp.second = j;				
			}
		}

		int x1 = 0;
		int y1 = 0;
		int x2 = n - 1;
		int y2 = m - 1;

		while (x2 - x1 > 1) {
			if (x1/2 < temp.first/2) {
				for (int j = 0; j < m - 1; j++) srr += 'R';
				srr += 'D';
				for (int j = 0; j < m - 1; j++) srr += 'L';
				srr += 'D';
				x1 += 2;
			}if (temp.first/2 < x2/2 ) {
				for (int j = 0; j < m - 1; j++) srr2 += 'R';
				srr2 += 'D';
				for (int j = 0; j < m - 1; j++) srr2 += 'L';
				srr2 += 'D';
				x2 -= 2;
			}
		}while (y2 - y1 > 1) {
			if (y1/2 < temp.second/2) {
				srr += 'D';
				srr += 'R';
				srr += 'U';
				srr += 'R';
				y1 += 2;
			}if (temp.second/2 < y2/2) {
				srr2 += 'D';
				srr2 += 'R';
				srr2 += 'U';
				srr2 += 'R';
				y2 -= 2;
			}
		}

		if (temp.second == y1) {
			srr += 'R';
			srr += 'D';
		}
		else {
			srr += 'D';
			srr += 'R';
		}

		reverse(srr2.begin(), srr2.end());

		srr += srr2;
		cout << srr;
	}
}