#include <bits/stdc++.h>
using namespace std;
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
#define mod 998244353
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

inline int mo(int x) {return x >= mod ? x - mod : x;}

int deg[N], ans[N], cnt[N][2];

vector<pii> ew[N];

vector<int> e[N], s;

queue<int> q;

int main() {
	int n = rd();
	rep(i, 1, n) {
		deg[i] = rd();
		rep(j, 1, deg[i]) {
			int v = rd(), w = rd();
			ew[i].eb(v, w); e[v].pb(i);
		}
		if (deg[i] == 0) q.push(i);
	}
	while (!q.empty()) {
		int v = q.front(); s.pb(v); q.pop();
		for (auto u : e[v]) if (!--deg[u]) q.push(u);
	}
	for (auto u : s) {
		for (auto [v, w] : ew[u]) {
			++cnt[u][w];
			if (w == 0) ans[u] = mo(ans[u] + cnt[u][1]);
			ans[u] = (ans[u] + 1ll * cnt[u][1] * cnt[v][0] + ans[v]) % mod;
			rep(k, 0, 1) cnt[u][k] = mo(cnt[u][k] + cnt[v][k]);
		}
	}
	printf("%d\n", ans[1]);
	return 0;
}