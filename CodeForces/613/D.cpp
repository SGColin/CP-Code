#include <bits/stdc++.h>
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

vector<int> e[N];

int lg[N] = {-1}, tot, dfn[N], f[N], st[17][N];

int getpre(int u, int v) {return dfn[u] < dfn[v] ? u : v;}

void dfs(int u, int fa) {
	st[0][dfn[u] = ++tot] = f[u] = fa;
	for (auto v : e[u]) if (v != fa) dfs(v, u);
}

int lca(int u, int v) {
	if (u == v) return u;
	if ((u = dfn[u]) > (v = dfn[v])) swap(u, v);
	int k = lg[v - u++];
	return getpre(st[k][u], st[k][v - (1 << k) + 1]);
} 

bool vis[N];

int ans = 0;

vector<int> s, son[N];

int dp(int u) {
	int cnt = 0;
	for (auto v : son[u]) cnt += dp(v);
	if (vis[u]) {ans += cnt; return 1;} 
	ans += (cnt > 1);
	return cnt == 1;
}

void work() {
	for (auto x : s) {vis[x] = false; son[x].clear();}
	s.clear();

	int k = rd();
	rep(i, 1, k) {int x = rd(); vis[x] = true; s.pb(x);}
	sort(all(s), [&](int a, int b){return dfn[a] < dfn[b];});
	rep(i, 0, k - 2) {
		if (vis[f[s[i + 1]]]) {puts("-1"); return;}
		s.pb(lca(s[i], s[i + 1]));
	}
	sort(all(s), [&](int a, int b){return dfn[a] < dfn[b];});
	s.erase(unique(all(s)), s.end());
	k = s.size();
	rep(i, 0, k - 2) son[lca(s[i], s[i + 1])].pb(s[i + 1]);
	ans = 0; dp(s.front());
	printf("%d\n", ans);	
}

int main() {
	int n = rd();
	rep(i, 1, n) lg[i] = lg[i >> 1] + 1;
	rep(i, 2, n) {int u = rd(), v = rd(); e[u].pb(v); e[v].pb(u);}
	dfs(1, 1);
	rep(i, 1, lg[n]) 
		rep(u, 1, n - (1 << i) + 1)
			st[i][u] = getpre(st[i - 1][u], st[i - 1][u + (1 << i - 1)]);
	per(q, rd(), 1) work();
	return 0;
}