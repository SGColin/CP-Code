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
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

bool vis[N];

vector<int> e[N], sp;

int fa[N], ans;

void dfs(int u, int fat) {
	fa[u] = fat;
	for (auto v : e[u]) if (v != fat) dfs(v, u);
}

void mark(int u) {
	while (!vis[u]) {vis[u] = true; ++ans; u = fa[u];}
}

int main() {
	int n = rd(), k = rd();
	rep(i, 1, n - 1) {
		int u = rd(), v = rd(), w = rd();
		e[u].pb(v); e[v].pb(u);
	}
	rep(i, 1, k) sp.pb(rd());
	dfs(sp[0], sp[0]);
	for (auto x : sp) mark(x);
	printf("%d\n", ans);
	return 0;
}