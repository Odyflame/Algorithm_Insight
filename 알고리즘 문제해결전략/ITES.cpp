//#include <iostream>	
//
//using namespace std;
//
//unsigned A[50000001] = { 1983u, };
//
//int main() {
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//
//	int t, sum, k,n, Count=0;
//
//	for (int i = 1; i < 50000000; i++) {
//		A[i] = (((A[i - 1] * 214013u) + 2531011u)%10000)+1;
//	}
//
//	cin >> t;
//
//	for (int j = 0; j < t; j++) {
//		sum = 0;
//		cin >> k >> n;
//		
//		for (int i = 1; i < n; i++) {
//			for (int h = i; h < n; h++) {
//				sum += A[h];
//				if (sum == k) { Count++; sum = 0; break; }
//				if (sum > k) { sum = 0; break;
//				}
//			}
//		}
//		cout << Count << '\n';
//		Count = 0;
//	}
//}


#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct RNG {
	unsigned seed;

	RNG():seed(1983){}

	unsigned next() {
		unsigned ret = seed;
		seed = ((seed * 214013u) + 2531011u);
		return ret % 10000 + 1;
	}
};

int countRanges(int k, int n) {
	RNG rng;
	queue<int> range;
	int ret = 0, rangesum = 0;
	for (int i = 0; i < n; i++) {
		int newSignal = rng.next();
		rangesum += newSignal;
		range.push(newSignal);


		while (rangesum > k) {
			rangesum -= range.front();
			range.pop();
		}

		if (rangesum == k) ret++;
	}
	return ret;
}

int main() {
	int t, a,b;

	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout<<countRanges(a, b)<<'\n';
	}
}