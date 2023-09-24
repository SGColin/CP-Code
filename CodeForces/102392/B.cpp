#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

inline void getmin(ll &x, ll y) {x = (x > y ? y : x);}

#define N 1001
#define pb push_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

ll f[1001][501], g[1001][501];

struct node {int x, y, t, r;} c[N];

int main() {
	memset(f, 0x3f, sizeof(f));
	memset(g, 0x3f, sizeof(g));
	int n = rd(), s1 = rd(), s2 = rd();
	f[0][0] = g[0][0] = 0;
	rep(i, 1, n) {c[i].x = rd(); c[i].t = rd(); c[i].y = rd(); c[i].r = rd();}
	sort(c + 1, c + 1 + n, [&](node a, node b){return a.x < b.x;});
	int mx = s1 + s2;
	rep(nw, 1, n) {
		auto [x, y, t, r] = c[nw];
		// first level
		rep(i, 0, mx)
			rep(j, 0, s2) {
				if (i < s1) getmin(f[min(mx, i + x)][j], g[i][j] + t);
				if (j < s2) getmin(f[i][min(s2, j + y)], g[i][j] + r);
				g[i][j] = f[i][j];
			}
	}
	ll ans = 1e18;
	rep(i, 0, mx)
		rep(j, 0, s2)
			if (i >= s1 && i + j >= s1 + s2) ans = min(ans, f[i][j]);
	printf("%lld\n", ans > 1e17 ? -1 : ans);
	return 0;
}