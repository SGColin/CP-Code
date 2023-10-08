#include "bits/stdc++.h"
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

#define N 150007
#define mod 1000000007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

inline int mo(int x) {return x >= mod ? x - mod : x;}

struct node {
	int a, b, c, d;
	node(int a = 1, int b = 0, int c = 0, int d = 1) : a(a), b(b), c(c), d(d) {}
	bool operator == (const node &obj) const {
		return (a == obj.a) && (b == obj.b) && (c == obj.c) && (d == obj.d);
	}
	node operator + (const node &obj) const {
		node ret;
		ret.a = mo(a + obj.a);
		ret.b = mo(b + obj.b);
		ret.c = mo(c + obj.c);
		ret.d = mo(d + obj.d);
		return ret;
	}
	node operator * (const node &obj) const {
		node ret;
		ret.a = (1ll * a * obj.a + 1ll * b * obj.c) % mod; 
		ret.b = (1ll * a * obj.b + 1ll * b * obj.d) % mod; 
		ret.c = (1ll * c * obj.a + 1ll * d * obj.c) % mod; 
		ret.d = (1ll * c * obj.b + 1ll * d * obj.d) % mod; 
		return ret;
	}
} sum[N << 2], tag[N << 2], ID;

inline node fpow(node x, int t) {
	node ret;
	for (; t; t >>= 1, x = x * x)
		if (t & 1) ret = ret * x;
	return ret;
}

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) / 2)

inline void mul(int rt, node v) {
	sum[rt] = sum[rt] * v; tag[rt] = tag[rt] * v;
}

inline void pushup(int rt) {
	sum[rt] = sum[ls] + sum[rs];
}

inline void pushdown(int rt) {
	if (tag[rt] == ID) return;
	mul(ls, tag[rt]); mul(rs, tag[rt]); tag[rt] = ID;
}

void build(int rt, int l, int r) {
	if (l == r) {sum[rt] = fpow((node){1, 1, 1, 0}, rd()); return;}
	build(ls, l, mid); build(rs, mid + 1, r); pushup(rt);
}

void upd(int rt, int l, int r, int L, int R, node v) {
	if (L <= l && r <= R) {mul(rt, v); return;}
	pushdown(rt);
	if (L <= mid) upd(ls, l, mid, L, R, v);
	if (R > mid) upd(rs, mid + 1, r, L, R, v);
	pushup(rt);
}

int qsum(int rt, int l, int r, int L, int R) {
	if (L <= l && r <= R) return sum[rt].c;
	pushdown(rt);
	int res = 0;
	if (L <= mid) res = mo(res + qsum(ls, l, mid, L, R));
	if (R > mid) res = mo(res + qsum(rs, mid + 1, r, L, R));
	return res;
}

int main() {
	int n = rd(), m = rd();
	build(1, 1, n);
	rep(i, 1, m) {
		int op = rd(), l = rd(), r = rd();
		if (op == 1) upd(1, 1, n, l, r, fpow((node){1, 1, 1, 0}, rd()));
		else printf("%d\n", qsum(1, 1, n, l, r));
	}
	return 0;
}