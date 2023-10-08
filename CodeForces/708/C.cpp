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

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 400007

vector<int> e[N];

bool ans[N];

int sz[N], mx[N], n;

void dfs1(int u, int fa) {
	sz[u] = 1;
	for (auto v : e[u])
		if (v != fa) {
			dfs1(v, u);
			sz[u] += sz[v];
			if (sz[v] > n / 2 && sz[v] - mx[v] > n / 2) ans[u] = false;
			mx[u] = max(mx[u], (sz[v] > n / 2 ? mx[v] : sz[v]));
		}
}

void dfs2(int u, int fa, int mxup) {
	multiset<int> s;
	s.insert(mxup);
	for (auto v : e[u])
		if (v != fa) s.insert(sz[v] > n / 2 ? mx[v] : sz[v]);
	for (auto v : e[u])
		if (v != fa) {
			int val = sz[v] > n / 2 ? mx[v] : sz[v];
			s.erase(s.find(val));
			int szup = n - sz[v];
			int nxup = (szup > n / 2 ? *--s.end() : szup);
			if (szup > n / 2 && szup - nxup > n / 2) ans[v] = false;
			dfs2(v, u, nxup);
			s.insert(val);
		}
}

int main() {
	n = rd();
	rep(i, 1, n) ans[i] = true;
	rep(i, 2, n) {
		int u = rd(), v = rd();
		e[u].push_back(v); e[v].push_back(u);
	}
	dfs1(1, 1); dfs2(1, 1, 0);
	rep(i, 1, n) printf("%d ", ans[i]);
	return 0;
}