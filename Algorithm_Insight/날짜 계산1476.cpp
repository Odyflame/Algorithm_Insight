/*
*2015112119 by ÀÌÇöÀç
*/

#include <iostream>

using namespace std;

int main() {
	int a, b, c, count=1;

	cin >> a >> b >> c;

	while (1) {
		if (a == 1 && b == 1 && c == 1) break;
		else {
			if (a == 1) {
				a += 15;
			}if (b == 1) {
				b += 28;
			}if (c == 1) {
				c += 19;
			}

			a--; b--; c--;
			count++;
		}
	}

	cout << count;
}