#include <iostream>
#include <string.h>
#include <algorithm>
typedef long long ll;
using namespace std;

ll gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

ll lcm(ll a, ll b) { return a / gcd(a, b)*b; }

pair<ll, ll> mul(pair<ll, ll> a, pair<ll, ll> b) {
	ll x, y, z;
	x = a.first*b.first;
	y = a.second*b.second;
	z = gcd(x, y);
	return { x / y, y / z };
}

int main() {
	int n, a, b;
	int c, d, check=1;
	
	pair<ll, ll> arr[15][15];

	cin >> n;

	for (int i = 0; i < n-1; i++) {
		cin >> a >> b >> c >> d;
		arr[a][b] = pair<ll, ll>(c, d);
		arr[b][a] = pair<ll, ll>(d, c);
	}

	pair<ll, ll> ans[11];
	ans[0] = { 1,1 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans[j].first == 0) continue;
			for (int k = 0; k < n; k++) {
				if (arr[i][j].first == 0 || ans[j].first != 0) continue;

				ans[j] = mul(ans[j], arr[i][j]);
			}
		}
	}

	ll temp = lcm(ans[0].second, ans[1].second);

	for (int i = 2; i < n; i++) temp = lcm(temp, ans[i].second);
	for (int i = 0; i < n; i++) printf("%lld", ans[i].first*temp / ans[i].second);
}