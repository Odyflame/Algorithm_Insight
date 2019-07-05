#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int t, n, a;

/*int lis(const vector<int>& A) {
	if (A.empty()) return 0;

	int ret = 0;
	for (int i = 0; i < A.size(); i++) {
		vector<int> B;
		for (int j = i + 1; j < A.size(); j++) {
			if (A[i] < A[j]) B.push_back(j);
		}ret = max(ret, 1 + lis(B));
	}
	return ret;
}*/

/*int lis2(int start) {
	int& ret = cache[start];

	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (S[start] < S[next]) ret = max(ret, lis2(next) + 1);
	}
	return ret;
}*/

int cache[501], S[501];

int lis3(int start) {
	int& ret = cache[start+1];

	if (ret != -1) return ret;

	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (start==-1||S[start] < S[next]) ret = max(ret, lis3(next) + 1);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		//vector<int> A;
		memset(S, -1, sizeof(S));
		memset(cache, -1, sizeof(cache));

		for (int j = 0; j < n; j++) {
			cin >> S[j];
			//A.push_back(a);
		}
		
		/*int maxlen = 0;
		for (int begin = 0; begin < n; begin++) {
			maxlen = max(maxlen, lis2(begin));
		}
		cout << maxlen << endl;*/

		cout << lis3(-1)-1<<endl;
	}
}
