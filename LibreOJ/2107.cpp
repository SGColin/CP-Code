#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll rd() {
	ll x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 300007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

struct node {
	int dis, ls, rs;
	ll w, add, mul;
	node() : dis(0), ls(0), rs(0), w(0), add(0), mul(1) {}
	void update(ll _add, ll _mul) {
		mul = mul * _mul;
		add = add * _mul + _add;
		w = w * _mul + _add;
	}
} c[N];

void pushdown(int rt) {
	int &ls = c[rt].ls, &rs = c[rt].rs;
	if (ls) c[ls].update(c[rt].add, c[rt].mul);
	if (rs) c[rs].update(c[rt].add, c[rt].mul);
	c[rt].add = 0; c[rt].mul = 1;
}

int merge(int rt, int _rt) {
	if (!rt || !_rt) return rt | _rt;
	if (c[rt].w > c[_rt].w || (c[rt].w == c[_rt].w && rt > _rt)) swap(rt, _rt);
	pushdown(rt);
	int &ls = c[rt].ls, &rs = c[rt].rs;
	rs = merge(rs, _rt);
	if (c[ls].dis < c[rs].dis) swap(ls, rs);
	c[rt].dis = c[rs].dis + 1;
	return rt;
}

int pop_top(int rt) { // return the index of new root
	pushdown(rt);
	return merge(c[rt].ls, c[rt].rs);
}

int rot[N], dep[N] = {0, 1};

int dead[N], ans[N];

ll h[N], a[N], v[N];

vector<int> son[N];

void dfs(int u) {
	for (auto v : son[u]) {
		dep[v] = dep[u] + 1; dfs(v);
		if (rot[v]) rot[u] = merge(rot[u], rot[v]);
	}
	while (rot[u] && c[rot[u]].w < h[u]) {
		++dead[u];
		ans[rot[u]] -= dep[u];
		rot[u] = pop_top(rot[u]);
	}
	if (rot[u]) { // update
		if (a[u] == 0) c[rot[u]].update(v[u], 1);
		else c[rot[u]].update(0, v[u]);
	}
}

int main() {
	int n = rd(), m = rd();
	rep(i, 1, n) h[i] = rd();
	rep(i, 2, n) {
		int fa = rd();
		son[fa].push_back(i);
		dep[i] = dep[fa] + 1; 
		a[i] = rd(); v[i] = rd();
	}
	rep(i, 1, m) {
		c[i].w = rd();
		int bel = rd();
		ans[i] = dep[bel];
		if (!rot[bel]) rot[bel] = i;
		else rot[bel] = merge(rot[bel], i);
	}
	dfs(1);
	rep(i, 1, n) printf("%d\n", dead[i]);
	rep(i, 1, m) printf("%d\n", ans[i]);
	return 0;
}