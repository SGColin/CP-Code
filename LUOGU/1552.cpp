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

#define N 100007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

struct node {
	int dis, ls, rs, w;
	node() : dis(0), ls(0), rs(0) {}
} c[N];

int merge(int rt, int _rt) {
	if (!rt || !_rt) return rt | _rt;
	if (c[rt].w < c[_rt].w) swap(rt, _rt);
	int &ls = c[rt].ls, &rs = c[rt].rs;
	rs = merge(rs, _rt);
	if (c[ls].dis < c[rs].dis) swap(ls, rs);
	c[rt].dis = c[rs].dis + 1;
	return rt;
}

int pop_top(int rt) { // return the index of new root
	return merge(c[rt].ls, c[rt].rs);
}

int n, m, l[N], rot[N], sz[N];

vector<int> son[N];

ll ans, sum[N];

void dfs(int u) {
	for (auto v : son[u]) {
		dfs(v);
		if (rot[v]) {
			rot[u] = merge(rot[u], rot[v]);
			sum[u] += sum[v];
			sz[u] += sz[v];
		}
	}
	while (sum[u] > m) {
		--sz[u];
		sum[u] -= c[rot[u]].w;
		rot[u] = pop_top(rot[u]);
	}
	ans = max(ans, 1ll * l[u] * sz[u]);
}

int main() {
	n = rd(); m = rd();
	rep(i, 1, n) {
		son[rd()].push_back(i);
		sum[i] = c[i].w = rd(); 
		l[i] = rd(); rot[i] = i; sz[i] = 1; 
	}
	dfs(1);
	printf("%lld\n", ans);
	return 0;
}