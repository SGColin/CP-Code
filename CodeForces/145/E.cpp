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

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 1050007

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) / 2)

char s[N];

struct msg {
	int cnt0, cnt1, mx01, mx10;
	msg() : cnt0(0), cnt1(0), mx01(0), mx10(0) {}
	msg operator + (const msg &obj) {
		msg ret;
		ret.cnt0 = cnt0 + obj.cnt0;
		ret.cnt1 = cnt1 + obj.cnt1;
		ret.mx01 = max(mx01 + obj.cnt1, cnt0 + obj.mx01);
		ret.mx10 = max(mx10 + obj.cnt0, cnt1 + obj.mx10);
		return ret;
	}
	void rev() {swap(cnt0, cnt1); swap(mx01, mx10);}
} c[N << 2];

bool rev[N << 2];

void build(int rt, int l, int r) {
	if (l == r) {
		s[l] == '4' ? c[rt].cnt0 = 1 : c[rt].cnt1 = 1;
		c[rt].mx01 = c[rt].mx10 = 1; return;
	}
	build(ls, l, mid); build(rs, mid + 1, r);
	c[rt] = c[ls] + c[rs];
}

void pushdown(int rt) {
	if (rev[rt]) {
		rev[ls] ^= 1; c[ls].rev();
		rev[rs] ^= 1; c[rs].rev();
		rev[rt] = false;
	} 
}

void upd(int rt, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		rev[rt] ^= 1; c[rt].rev(); return;
	}
	pushdown(rt);
	if (L <= mid) upd(ls, l, mid, L, R);
	if (R > mid) upd(rs, mid + 1, r, L, R);
	c[rt] = c[ls] + c[rs];
}

int main() {
	int n = rd(), m = rd();
	scanf("%s", s + 1);
	build(1, 1, n); 
	rep(i, 1, m) {
		scanf("%s", s + 1);
		if (s[1] == 'c') printf("%d\n", c[1].mx01);
		else {int l = rd(), r = rd(); upd(1, 1, n, l, r);}
	}
	return 0;
}