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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 130007
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) / 2)

struct seg2 {
	struct node {
		int cnt;
		ll sum[2];
		node operator + (const node obj) const {
			node ret;
			ret.cnt = cnt + obj.cnt;
			if (cnt & 1) {
				ret.sum[0] = sum[0] + obj.sum[1];
				ret.sum[1] = sum[1] + obj.sum[0];
			} else {
				ret.sum[0] = sum[0] + obj.sum[0];
				ret.sum[1] = sum[1] + obj.sum[1];
			}
			return ret;
		}
	} c[N << 2];

	void pushup(int rt) {c[rt] = c[ls] + c[rs];}
	
	void add(int rt, int l, int r, int p) {
		if (l == r) {
			auto &cur = c[rt];
			++cur.cnt;
			cur.sum[cur.cnt & 1] += p;
			return;
		}
		p <= mid ? add(ls, l, mid, p) : add(rs, mid + 1, r, p);
		pushup(rt);
	}

	void del(int rt, int l, int r, int p) {
		if (l == r) {
			auto &cur = c[rt]; 
			cur.sum[cur.cnt & 1] -= p;
			--cur.cnt; return;
		}
		p <= mid ? del(ls, l, mid, p) : del(rs, mid + 1, r, p);
		pushup(rt);
	}
} S;

struct seg4 {
	struct node {
		int cnt;
		ll sum[4];
		node operator + (const node obj) const {
			node ret;
			ret.cnt = cnt + obj.cnt;
			int dlt = cnt % 4;
			rep(i, 0, 3) {
				int tar = (i + dlt) % 4;
				ret.sum[tar] = sum[tar] + obj.sum[i];
			}  
			return ret;
		}
	} c[N << 2];

	void pushup(int rt) {c[rt] = c[rs] + c[ls];}
	
	void add(int rt, int l, int r, int p) {
		if (l == r) {
			auto &cur = c[rt];
			++cur.cnt;
			cur.sum[cur.cnt % 4] += p;
			return;
		}
		p <= mid ? add(ls, l, mid, p) : add(rs, mid + 1, r, p);
		pushup(rt);
	}

	void del(int rt, int l, int r, int p) {
		if (l == r) {
			auto &cur = c[rt]; 
			cur.sum[cur.cnt % 4] -= p;
			--cur.cnt; return;
		}
		p <= mid ? del(ls, l, mid, p) : del(rs, mid + 1, r, p);
		pushup(rt);
	}
} F;

ll tot = 0;

int a[N], b[N];

int main() {
	int n = rd(), m = rd();
	rep(i, 1, n) {
		a[i] = rd(); b[i] = rd();
		tot += max(a[i], b[i]);
		if (a[i] <= b[i]) F.add(1, 0, 100000, b[i] - a[i]);
		else S.add(1, 0, 100000, a[i] - b[i]);
	}
	printf("%lld\n", tot - F.c[1].sum[0] - F.c[1].sum[1] - S.c[1].sum[F.c[1].cnt & 1]);
	rep(t, 1, m) {
		int i = rd();
		tot -= max(a[i], b[i]);
		if (a[i] <= b[i]) F.del(1, 0, 100000, b[i] - a[i]);
		else S.del(1, 0, 100000, a[i] - b[i]);
		a[i] = rd(); b[i] = rd();
		tot += max(a[i], b[i]);
		if (a[i] <= b[i]) F.add(1, 0, 100000, b[i] - a[i]);
		else S.add(1, 0, 100000, a[i] - b[i]);
		printf("%lld\n", tot - F.c[1].sum[0] - F.c[1].sum[1] - S.c[1].sum[F.c[1].cnt & 1]);
	}
	return 0;
}