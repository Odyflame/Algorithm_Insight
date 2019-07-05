#include <iostream>

using namespace std;

int main() {
	int n, right,left,sum=-1,cnt=0, check;
	
	cin >> n;
	check = n;

	 do{
		if (n < 10) {
			left = 0; right = n;
		}
		else {
			left = n / 10; right = n % 10;
		}
		sum = left + right;
		
		n = sum % 10 + right*10;
		cnt++;
	 } while (n != check); cout << cnt;
}