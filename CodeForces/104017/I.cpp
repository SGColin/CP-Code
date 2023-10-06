#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd(){
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 300007
#define inf 1000000000
#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) / 2)

int p[N], dis[N];

queue<int> q;

struct segtree {
	int mn[N << 2], mx[N << 2];
	void pushup(int rt) {
		mn[rt] = min(mn[ls], mn[rs]);
		mx[rt] = max(mx[ls], mx[rs]);
	}
	void build(int rt, int l, int r, int pos) {
		if (l == r) {
			mn[rt] = (l == pos ? inf : l - p[l]); 
			mx[rt] = (l == pos ? -inf : l + p[l]);
			return;
		}
		build(ls, l, mid, pos); 
		build(rs, mid + 1, r, pos);
		pushup(rt);
	}
	void findmn(int rt, int l, int r, int L, int R, int w, int d) {
		if (mn[rt] > w) return;
		if (l == r) {
			q.push(l); dis[l] = d;
			mn[rt] = inf; mx[rt] = -inf; return;
		}
		if (L <= mid) findmn(ls, l, mid, L, R, w, d);
		if (R > mid) findmn(rs, mid + 1, r, L, R, w, d); 
		pushup(rt);
	}
	void findmx(int rt, int l, int r, int L, int R, int w, int d) {
		if (mx[rt] < w) return;
		if (l == r) {
			q.push(l); dis[l] = d;
			mn[rt] = inf; mx[rt] = -inf; return;
		}
		if (L <= mid) findmx(ls, l, mid, L, R, w, d);
		if (R > mid) findmx(rs, mid + 1, r, L, R, w, d); 
		pushup(rt);
	}
} seg;

inline void work() {
	int n = rd(), s = rd(), t = rd();
	rep(i, 1, n) p[i] = rd(), dis[i] = -1;
	if (s == t) {puts("0"); return;}
	while (!q.empty()) q.pop();
	seg.build(1, 1, n, s); 
	q.push(s); dis[s] = 0; 
	while (!q.empty()) {
		int u = q.front(); q.pop();
		//cout << u << " " << dis[u] << endl;
		if (u > 1) seg.findmx(1, 1, n, max(1, u - p[u]), u - 1, u, dis[u] + 1);
		if (u < n) seg.findmn(1, 1, n, u + 1, min(n, u + p[u]), u, dis[u] + 1);
		//cout << "????" << dis[t] << endl;
		if (dis[t] > -1) {printf("%d\n", dis[t]); return;}
	}
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}
