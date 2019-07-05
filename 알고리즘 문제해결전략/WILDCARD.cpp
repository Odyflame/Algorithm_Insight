#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

//완전탐색 알고리즘
//bool match(const string& w, const string &s) {
//	int pos = 0;
//
//	//w와 s를 맟춰나간다,
//	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || s[pos] == w[pos])) pos++;
//	
//	//패턴 끝에 도달해서 끝난 경우 : 문자열도 끝났어야 대응된다.
//	if (pos == w.size()) return pos == s.size();
//
//	if (w[pos] == '*')
//		for (int skip = 0; pos + skip <= s.size(); ++skip)
//			if (match(w.substr(pos + 1), s.substr(pos + skip))) return true;
//
//	return false;
//}

int cache[101][101];
string W, S;

bool matchmamoized(int w, int s) {
	int& ret = cache[w][s];

	if (ret != -1) return ret;
	
	while (s < S.size() && w < W.size() && (W[w] == '?' || S[s] == W[w])) { w++; s++; }

	//더이상 대응할 수 없으면 왜 while문이 끝났는지 확인한다.
	//패턴 끝에 도달해서 끝난 경우 : 문자열도 끝났어야 한다.
	if (w == W.size()) return ret = (s == S.size());

	if (W[w] == '*')
		for (int skip = 0; skip + s <= S.size(); skip++)
			if (matchmamoized(w + 1, s + skip)) return ret = 1;

	return ret = 0;
}

int main() {
	int c, n, cnt=0;

	cin >> c;
	for (int i=0; i < c; i++) {
		vector<string> srr;
		cin >> W;

		cin >> n;

		for (int j = 0; j < n; j++) {
			memset(cache, -1, sizeof(cache));
			
			cin >> S;

			if (matchmamoized(0, 0) == true) srr.push_back(S);

		}
		sort(srr.begin(), srr.end());

		for (auto ele : srr) cout << ele << endl;
		cnt = 0;
	}
}