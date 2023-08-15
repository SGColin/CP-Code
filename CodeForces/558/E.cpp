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

#define N 131072
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

struct segtree {
	
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) / 2) 

	int sum[N << 2], tag[N << 2];

	segtree(){
		memset(sum, 0, sizeof(sum));
		memset(tag, -1, sizeof(tag));
	}

	void pushup(int rt) {
		sum[rt] = sum[ls] + sum[rs];
	}

	void pushdown(int rt, int l, int r) {
		if (tag[rt] != -1) {
			tag[ls] = tag[rs] = tag[rt];
			sum[ls] = (mid - l + 1) * tag[rt];
			sum[rs] = (r - mid) * tag[rt];
			tag[rt] = -1;
		}
	}

	void insert(int rt, int l, int r, int p) {
		if (l == r) {sum[rt] = 1; return;}
		pushdown(rt, l, r);
		p <= mid ? insert(ls, l, mid, p) : insert(rs, mid + 1, r, p);
		pushup(rt);
	}

	int qpos(int rt, int l, int r, int p) {
		if (l == r) return sum[rt];
		pushdown(rt, l, r);
		return p <= mid ? qpos(ls, l, mid, p) : qpos(rs, mid + 1, r, p);
	}

	void cover(int rt, int l, int r, int L, int R, int op) {
		if (L <= l && r <= R) {
			sum[rt] = (r - l + 1) * op;
			tag[rt] = op; return;
		}
		pushdown(rt, l, r);
		if (L <= mid) cover(ls, l, mid, L, R, op);
		if (R > mid) cover(rs, mid + 1, r, L, R, op);
		pushup(rt);
	}

	int qsum(int rt, int l, int r, int L, int R) {
		if (L <= l && r <= R) return sum[rt];
		pushdown(rt, l, r);
		int ans = 0;
		if (L <= mid) ans += qsum(ls, l, mid, L, R);
		if (R > mid) ans += qsum(rs, mid + 1, r, L, R);
		return ans;
	}
} tr[26];

int main() {
	int n = rd(), q = rd();
	rep(i, 1, n) {
		char c = getchar();
		while (!isalpha(c)) c = getchar();
		tr[c - 'a'].insert(1, 1, n, i);
	}
	rep(i, 1, q) {
		int L = rd(), R = rd(), op = rd(), cnt[26];
		rep(c, 0, 25) {
			cnt[c] = tr[c].qsum(1, 1, n, L, R);
			if (cnt[c]) tr[c].cover(1, 1, n, L, R, 0);
		}
		rep(c, 0, 25) {
			int x = op ? c : 25 - c;
			if (!cnt[x]) continue;
			tr[x].cover(1, 1, n, L, L + cnt[x] - 1, 1);
			L += cnt[x];
		}
	}
	rep(i, 1, n)
		rep(c, 0, 25) 
			if (tr[c].qpos(1, 1, n, i)) {putchar('a' + c); break;}
	return 0;
}