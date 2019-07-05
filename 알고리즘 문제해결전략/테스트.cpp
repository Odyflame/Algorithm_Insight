#include <iostream>
#include <vector>
#include <string>

using namespace std;

//bool isInsideCircle(int y, int x, int cx, int cy, int cr) {};

//string getMonthName(int month) {};

const string getMonthName2[] = { "janaury", "Februrary", "march", "aprilll", "may", "June", "July" };

int ck[1000000] = { 1,1 }, n;

int main() {

	for (int i = 2; i < 1e6; i++)
		if (!ck[i]) {
			for (int j = i * 2; j < 1e6; j += i) 
				ck[j] = 1;
		}


	while (scanf("%d", &n), n) {
		for (int i = 1;; i++) if (!ck[i] && !ck[n - i]) {
			printf("%d = %d + %d\n", n, i, n - i);
			break;
		}
	}

	return 0;

}