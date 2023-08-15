
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

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
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

vector<int> e[N], sdep[N];

int lg[N] = {-1}, tot, dfn[N], dep[N], f[N];

int st[17][N], mn[17][N];

int getpre(int u, int v) {return dfn[u] < dfn[v] ? u : v;}

void dfs(int u, int fa) {
	sdep[dep[u] = dep[fa] + 1].pb(u);
	st[0][dfn[u] = ++tot] = f[u] = fa;
	for (auto v : e[u]) if (v != fa) dfs(v, u);
}

int lca(int u, int v) {
	if (u == v) return u;
	if ((u = dfn[u]) > (v = dfn[v])) swap(u, v);
	int k = lg[v - u++];
	return getpre(st[k][u], st[k][v - (1 << k) + 1]);
} 

ll ans = 0;

int tar = 0;

vector<int> son[N];

int qmn(int l, int r) {
	int k = lg[r++ - l++ + 1];
	return min(mn[k][l], mn[k][r - (1 << k) + 1]);
}

ll dp(int u, int fa) {
	if (dep[u] == tar) return qmn(tar - dep[u], tar - dep[fa]);
	ll sum = 0;
	for (auto v : son[u]) sum += dp(v, u);
	return min(sum, 1ll * qmn(tar - dep[u], tar - dep[fa]));
}

int calc(vector<int> &s) {
	sort(all(s), [&](int a, int b){return dfn[a] < dfn[b];});
	per(i, s.size() - 2, 0) s.pb(lca(s[i], s[i + 1]));
	sort(all(s), [&](int a, int b){return dfn[a] < dfn[b];});
	s.erase(unique(all(s)), s.end());
	per(i, s.size() - 2, 0) son[lca(s[i], s[i + 1])].pb(s[i + 1]);

	ans += dp(s.front(), 1);
	for (auto x : s) son[x].clear();
}

void work() {
	int n = rd();
	tot = 0;
	rep(i, 1, n) mn[0][i] = rd(), e[i].clear(), sdep[i].clear();
	rep(i, 2, n) {int u = rd(), v = rd(); e[u].pb(v); e[v].pb(u);}
	dfs(1, 0);
	rep(i, 1, lg[n]) 
		rep(u, 1, n - (1 << i) + 1) {
			st[i][u] = getpre(st[i - 1][u], st[i - 1][u + (1 << i - 1)]);
			mn[i][u] = min(mn[i - 1][u], mn[i - 1][u + (1 << i - 1)]);
		}
	ans = 0;
	for (int i = 1; i <= n; ++i) 
		if (!sdep[i].empty()) tar = i, calc(sdep[i]);
	printf("%lld\n", ans);
}

int main() {
	rep(i, 1, N - 1) lg[i] = lg[i >> 1] + 1;
	per(t, rd(), 1) work();
	return 0;
}