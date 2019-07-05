#include <iostream>
#include <queue>
#include <list>
using namespace std;

int c, n, k;
int arr[1001] = { 0, };

int main() {
	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> n >> k;
		list<int> survivors;

		for (int i = 1; i <= n; i++) {
			survivors.push_back(i);
		}
		
		list<int>::iterator kill = survivors.begin();

		while (n > 2) {
			kill = survivors.erase(kill);
			
			if (kill == survivors.end()) kill = survivors.begin();
			
			for (int i = 0; i < k-1; i++) {
				
				kill++;
				if (kill == survivors.end()) kill = survivors.begin();
			}

			n--;
		}

		cout << survivors.front()<<" "<< survivors.back() << endl;
	}
}