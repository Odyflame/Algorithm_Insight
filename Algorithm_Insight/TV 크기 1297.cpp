#include <iostream>
#include <math.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);

	double a, b, c, x;

	cin >> a >> b >> c;

	x = sqrt(pow(a, 2) / (pow(b, 2) + pow(c, 2)));
	int ansx = b * x;
	int ansy = c * x;
	cout << ansx <<" "<< ansy;
}