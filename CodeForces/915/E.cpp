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

#define N 15000007

int tot = 1;

struct node {int ls, rs, tag, sum;} c[N];

void upd(int rt, int l, int r, int L, int R, bool t) {
	auto &[ls, rs, tag, sum] = c[rt];
	if (L <= l && r <= R) {
		tag = t;
		sum = (tag ? r - l + 1 : 0);
		return;
	}
	int mid = (l + r) / 2;
	if (!ls) ls = ++tot;
	if (!rs) rs = ++tot;
	if (tag != -1) {
		c[ls].tag = c[rs].tag = tag;
		if (tag) {c[ls].sum = mid - l + 1; c[rs].sum = r - mid;} 
		else c[ls].sum = c[rs].sum = 0;
		tag = -1;
	}
	if (L <= mid) upd(ls, l, mid, L, R, t);
	if (R > mid) upd(rs, mid + 1, r, L, R, t);
	sum = c[ls].sum + c[rs].sum;
}

int main() {
	int n = rd(), q = rd();
	upd(1, 1, n, 1, n, 1);
	for (int i = 1; i <= q; ++i) {
		int l = rd(), r = rd(), op = rd() - 1;
		upd(1, 1, n, l, r, op);
		printf("%d\n", c[1].sum);
	}
	return 0;
}
