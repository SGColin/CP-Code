#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 5007

int n, d, a[N];

int main() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	ll ans = 0;

	auto check = [&](int l, int r) {
		ll tmp = 0;
		for (int i = 1; i < n; ++i) {
			int nw = min(r, max(l, a[i]));
			int nxt = min(r, max(l, a[i + 1]));
			tmp += abs(nw - nxt);
		}
		return tmp;
	};

	for (int i = 1; i <= n; ++i) {
		ans = max(ans, check(a[i], a[i] + d));
		ans = max(ans, check(a[i] - d, a[i]));
	}
	printf("%lld\n", ans);
	return 0;
}