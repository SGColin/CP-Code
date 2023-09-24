#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 100007
#define pb push_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

int a[N];

ll sum[N], fm[N], fc[N], nm[N], nc[N];

int main() {
	int n = rd(), k = rd();
	int lc = rd(), pc = rd(), lm = rd(), pm = rd();
	int t = rd(), d = rd();
	rep(i, 1, n) a[i] = rd();
	sort(a + 1, a + 1 + n);
	rep(i, 1, n) sum[i] = sum[i - 1] + min(a[i] - 1, d);
	rep(i, 1, n) {
		fm[i] = fm[i - 1] + min(max(0, a[i] - lm), d);
		fc[i] = fc[i - 1] + min(max(0, a[i] - lc), d);
		nm[i] = nm[i - 1] + (lm - a[i] <= d ? max(0, lm - a[i]) : 100000000000ll);
		nc[i] = nc[i - 1] + (lc - a[i] <= d ? max(0, lc - a[i]) : 100000000000ll);
	}
	
	ll ans = 1e18;
	for (int i = 0; (i - 1) * k <= n; ++i) {
		int p2 = n - i;
		int p1 = min(p2, i * (k - 1));
		ll free = sum[p1] + fm[p2] - fm[p1] + fc[n] - fc[p2];
		ll need = nm[p2] - nm[p1] + nc[n] - nc[p2];
		if (need > free) continue;
		ans = min(ans, t * need + 1ll * i * pc + 1ll * max(0, n - i * k) * pm);
	}
	if (ans > 9e17) puts("-1");
	else printf("%lld\n", ans);
	return 0;
}