#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

//����Ž�� �˰���
//bool match(const string& w, const string &s) {
//	int pos = 0;
//
//	//w�� s�� ���糪����,
//	while (pos < s.size() && pos < w.size() && (w[pos] == '?' || s[pos] == w[pos])) pos++;
//	
//	//���� ���� �����ؼ� ���� ��� : ���ڿ��� ������� �����ȴ�.
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

	//���̻� ������ �� ������ �� while���� �������� Ȯ���Ѵ�.
	//���� ���� �����ؼ� ���� ��� : ���ڿ��� ������� �Ѵ�.
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