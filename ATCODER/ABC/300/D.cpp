#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 1000007

vector<int> prm;

int sum[N];

int main() {
	for (int i = 2; i < N; ++i) {
		if (!sum[i]) prm.push_back(i);
		if (1ll * i * i >= N) continue;
		for (int j = i * i; j < N; j += i) sum[j] = 1;
	}
	for (int i = 2; i < N; ++i) sum[i] = 1 - sum[i] + sum[i - 1];

	ll n, ans = 0; cin >> n;
	for (auto x : prm) {
		if (x > 251) break;
		for (auto y : prm) {
			if (y <= x) continue;
			if (y > 10000) break;
			ans += max(0, sum[(int)sqrt(n / x / x / y)] - sum[y]);
		}
	}
	cout << ans << endl;
	return 0;
}