#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

struct node {
	int l, r; 
	mutable ll v;
	node(int l, int r, ll v) : l(l), r(r), v(v) {}
	inline bool operator < (const node &obj) const {return l < obj.l;}
};

int n, m, seed, vmax;

inline int rnd() {
	int ret = seed;
    seed = (seed * 7ll + 13) % 1000000007;
    return ret;
}

set<node> s;

auto split(int p) {
	if (p > n) return s.end();
	auto it = --s.upper_bound(node{p, 0, 0});
	if (it -> l == p) return it;
	auto [l, r, v] = *it;
	s.erase(it); 
	s.insert(node{l, p - 1, v});
	return s.insert(node{p, r, v}).first;
}

void assign(int l, int r, int v) {
	// printf("assign %d %d %d\n", l, r, v);
	auto itr = split(r + 1), itl = split(l);
	s.erase(itl, itr);
	s.insert(node{l, r, v});
}

void add(int l, int r, int x) {
	// printf("add %d %d %d\n", l, r, x);
	auto itr = split(r + 1), itl = split(l);
	for (; itl != itr; ++itl) itl -> v += x;
}

vector<pair<ll, int>> tmp;

ll kth(int l, int r, int x) {
	// printf("kth %d %d %d\n", l, r, x);
	tmp.clear();
	auto itr = split(r + 1), itl = split(l);
	for (; itl != itr; ++itl) {
		auto [l, r, v] = *itl;
		tmp.emplace_back(v, r - l + 1);
	}
	sort(tmp.begin(), tmp.end());
	for (auto [v, len] : tmp)
		if (x <= len) return v;
		else x -= len;
	return -1;
}

int fpow(ll x, int t, int mod) {
	x %= mod;
	int ret = 1;
	for (; t; t >>= 1, x = x * x % mod)
		if (t & 1) ret = ret * x % mod;
	return ret;
}

int sum(int l, int r, int x, int mod) {
	// printf("sum %d %d %d %d\n", l, r, x, mod);
	int ret = 0;
	auto itr = split(r + 1), itl = split(l);
	for (; itl != itr; ++itl) {
		auto [l, r, v] = *itl;
		ret = (ret + 1ll * (r - l + 1) * fpow(v, x, mod)) % mod;
	}
	return ret;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &seed, &vmax);
	rep(i, 1, n) s.insert(node{i, i, (rnd() % vmax) + 1});
	// for (auto [l, r, v] : s) printf("%lld ", v); puts("");
	rep(i, 1, m) {
		int op = rnd() % 4 + 1;
		int l = rnd() % n + 1, r = rnd() % n + 1, x;
		if (l > r) swap(l, r);
		if (op == 3) x = rnd() % (r - l + 1) + 1;
		else x = rnd() % vmax + 1;
		if (op == 1) add(l, r, x);
		else if (op == 2) assign(l, r, x);
		else if (op == 3) printf("%lld\n", kth(l, r, x));
		else printf("%d\n", sum(l, r, x, rnd() % vmax + 1));
	}
	return 0;
}