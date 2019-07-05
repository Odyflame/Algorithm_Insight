#include <iostream>
#include <string>
#include <math.h>

using namespace std;

char five = '5';
char six = '6';

int main() {
	
	string a, b;

	int AMAX=0, AMIN=0, BMAX=0,BMIN=0;

	cin >> a >> b;

	for (int i = 0; i < a.length(); i++) {
		char c,d;
		c = a[i];
		d = a[i];

		if (a[i] == six) c = five;
		if (a[i] == five) d = six;

		AMAX += (pow(10, (a.length() - i - 1))*(d - 48));
		AMIN += (pow(10, (a.length() - i - 1))*(c - 48));
	}

	for (int i = 0; i < b.length(); i++) {
		char c,d;
		c = b[i];
		d = b[i];

		if (b[i] == six) c = five;
		if (b[i] == five) d = six;

		BMAX += (pow(10, (b.length() - i - 1))*(d - 48));
		BMIN += (pow(10, (b.length() - i - 1))*(c - 48));
	}

	cout << AMIN + BMIN << " " << AMAX + BMAX;
}