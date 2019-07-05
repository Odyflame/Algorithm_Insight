#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	char c;
	cin >> t;

	vector<char> vec;
	cin.clear();
	cin.ignore();

	for (int j = 0; j < t; j++) {
		
		vec.clear();	

		while ((c = cin.get())!='\n') {
			if(c == '('||c=='['||c=='{') vec.push_back(c);

			if ( c == ')'&& vec.back() == '(') vec.pop_back();
			else if (c == ')' && vec.back() != '(') vec.push_back(c);

			if ( c == ']' && vec.back() == '[') vec.pop_back();
			else if (c == ']' && vec.back() != '[') vec.push_back(c);

			if ( c == '}'&& vec.back() == '{') vec.pop_back();
			else if (c == '}' && vec.back() != '{') vec.push_back(c);
		}

		if (vec.empty()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}