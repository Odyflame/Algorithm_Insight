#include <iostream>

using namespace std;

int main() {
	int c, x1, x2, x3, y1, y2, y3;
	int nx, ny;
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> c;

	for (int i = 0; i < c; i++) {

		cin >> x1 >> y1;
		cin >> x2 >> y2;
		cin >> x3 >> y3;

		if (x1 == x2) nx = x3;
		else if (x1 == x3) nx = x2;
		else if (x2 == x3) nx = x1;
		
		if (y1 == y2) ny = y3;
		else if (y1 == y3) ny = y2;
		else if (y2 == y3) ny = y1;

		cout << nx << " " << ny << endl;
	}
}