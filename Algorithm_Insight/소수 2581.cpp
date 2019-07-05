#include <iostream>
#include <vector>

#define LIMIT 1000000

using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<bool> is_prime(LIMIT + 1, true);
	vector<int> prime;

	for (int i = 2; i <= 10000; i++) {
		if (!is_prime[i]) continue;
		prime.push_back(i);
		for (int j = i * i; j <= LIMIT; j += i)
			is_prime[j] = false;
	}

	int n, m, sum=0, min=0;
	bool check=false;
	cin >> m >> n;

	for (auto ele : prime) {
		if (ele < m) continue;
		if (ele > n) break;

		if (check == false) {
			min = ele;
			check = true;
		}
		sum += ele;
	}

	if (check == false) cout << -1;
	else cout << sum << '\n' << min;

	return 0;
}
