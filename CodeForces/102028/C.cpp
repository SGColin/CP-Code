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

#define N 400007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

struct SEG {
	int cov[N << 2], add[N << 2], mx[N << 2], mn[N << 2];	
	
	#define ls (rt << 1)
	#define rs (rt << 1 | 1)
	#define mid ((l + r) / 2)

	void pushup(int rt) {
		mx[rt] = max(mx[ls], mx[rs]);
		mn[rt] = min(mn[ls], mn[rs]);
	}

	void build(int rt, int l, int r, int *a) {
		cov[rt] = add[rt] = 0;
		if (l == r) {mx[rt] = mn[rt] = a[l]; return;}
		build(ls, l, mid, a);
		build(rs, mid + 1, r, a);
		pushup(rt);
	}

	void mergecov(int rt, int x) {
		mn[rt] = mx[rt] = cov[rt] = x; add[rt] = 0;
	} 

	void mergeadd(int rt, int x) {
		mn[rt] += x; mx[rt] += x;
		if (cov[rt]) cov[rt] += x;
		else add[rt] += x;
	}

	void pushdown(int rt) {
		if (cov[rt]) {mergecov(ls, cov[rt]); mergecov(rs, cov[rt]);}
		if (add[rt]) {mergeadd(ls, add[rt]); mergeadd(rs, add[rt]);}
		add[rt] = cov[rt] = 0;
	}

	void cover(int rt, int l, int r, int L, int R, int v) {
		if (L <= l && r <= R) {mergecov(rt, v); return;}
		pushdown(rt);
		if (L <= mid) cover(ls, l, mid, L, R, v);
		if (R > mid) cover(rs, mid + 1, r, L, R, v);
		pushup(rt);
	}

	void upd(int rt, int l, int r, int L, int R, int v) {
		//printf("%d %d %d %d -> %d : %d\n", l, r, L, R, v, mx[rt]);
		if (L <= l && r <= R) {mergeadd(rt, v); return;}
		pushdown(rt);
		if (L <= mid) upd(ls, l, mid, L, R, v);
		if (R > mid) upd(rs, mid + 1, r, L, R, v);
		pushup(rt);
	}

	int findl(int rt, int l, int r, int v) { // maximum place <= v
		if (mx[rt] <= v) return r;
		pushdown(rt);
		if (mn[rs] <= v) return findl(rs, mid + 1, r, v);
		else return findl(ls, l, mid, v);
	}

	int findr(int rt, int l, int r, int v) { // minimum place >= v
		if (mn[rt] >= v) return l;
		pushdown(rt);
		if (mx[ls] >= v) return findr(ls, l, mid, v);
		else return findr(rs, mid + 1, r, v);
	}

	void movel(int n, int k) {
		k = min(k, n - 1);
		if (mn[1] > k + 1) upd(1, 1, n, 1, n, -k);
		else {
			int p = findl(1, 1, n, k + 1);
			//printf("p = %d dlt = %d\n", p, -k);
			cover(1, 1, n, 1, p, 1);
			if (p < n) upd(1, 1, n, p + 1, n, -k);
		}
	}

	void mover(int n, int k) {
		k = min(k, n - 1);
		if (mx[1] < n - k) upd(1, 1, n, 1, n, k);
		else {
			int p = findr(1, 1, n, n - k);
			cover(1, 1, n, p, n, n);
			if (p > 1) upd(1, 1, n, 1, p - 1, k);
		}
	}

	int getv(int rt, int l, int r, int p) {
		if (l == r) return mx[rt];
		pushdown(rt);
		return p <= mid ? getv(ls, l, mid, p) : getv(rs, mid + 1, r, p);
	}

} X, Y;

struct BIT {
	int c[N];
	inline void reset(int n) {rep(i, 1, n) c[i] = 0;}
	inline int lowbit(int x) {return x & (-x);}
	inline void add(int p) {for (; p < N; p += lowbit(p)) ++c[p];}
	inline int qsum(int p) {int sum = 0; for (; p; p -= lowbit(p)) sum += c[p]; return sum;}
	inline int sum(int l, int r) {return qsum(r) - (l == 1 ? 0 : qsum(l - 1));}
} B;

#define eb emplace_back
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

vector<pii> s;

vector<tii> preq[N], sufq[N];

int x[N], y[N], tx[N], ty[N];

ll ans1[N], ans2[N];

inline void work() {
	int n = rd(), q = rd();
	rep(i, 1, n) {x[i] = rd(); y[i] = rd();}

	s.clear();
	rep(i, 1, n) s.eb(x[i], i);
	sort(s.begin(), s.end());
	int tot = 0;
	for (auto [p, id] : s) {x[++tot] = p; tx[id] = tot;}
	X.build(1, 1, n, x);

	s.clear();
	rep(i, 1, n) s.eb(y[i], i);
	sort(s.begin(), s.end());
	tot = 0;
	for (auto [p, id] : s) {y[++tot] = p; ty[id] = tot;}
	Y.build(1, 1, n, y);

	auto C2 = [&](int x) {return 1ll * x * (x - 1) / 2;};

	int totq = 0;
	rep(i, 1, q) {
		char c = getchar();
		while (!isalpha(c) && c != '?' && c != '!') c = getchar();
		if (isalpha(c)) {
			if (c == 'L') Y.movel(n, rd());
			else if (c == 'R') Y.mover(n, rd());
			else if (c == 'U') X.movel(n, rd());
			else X.mover(n, rd());
		} else if (c == '?') {
			int id = rd();
			ans1[++totq] = X.getv(1, 1, n, tx[id]);
			ans2[totq] = Y.getv(1, 1, n, ty[id]);
		} else {
			++totq;
			if (X.mn[1] == X.mx[1]) {
				if (Y.mn[1] == Y.mx[1]) ans1[totq] = C2(n);
				else {
					int YL = Y.findl(1, 1, n, Y.mn[1]);
					int YR = Y.findr(1, 1, n, Y.mx[1]);
					preq[YL].eb(1, n, totq);
					sufq[YR].eb(1, n, totq);
				}
			} else {
				int XL = X.findl(1, 1, n, X.mn[1]);
				int XR = X.findr(1, 1, n, X.mx[1]);
				if (Y.mn[1] == Y.mx[1]) {
					preq[n].eb(1, XL, totq);
					preq[n].eb(XR, n, totq);
				} else {
					int YL = Y.findl(1, 1, n, Y.mn[1]);
					int YR = Y.findr(1, 1, n, Y.mx[1]);
					preq[YL].eb(1, XL, totq); preq[YL].eb(XR, n, totq);
					sufq[YR].eb(1, XL, totq); sufq[YR].eb(XR, n, totq);
				}
			}
		}	
	}

	B.reset(n);
	rep(i, 1, n) {
		B.add(tx[s[i - 1].second]);
		for (auto [l, r, id] : preq[i]) ans1[id] += C2(B.sum(l, r));
	}
	
	B.reset(n);
	per(i, n, 1) {
		B.add(tx[s[i - 1].second]);
		for (auto [l, r, id] : sufq[i]) ans1[id] += C2(B.sum(l, r));
	}

	rep(i, 1, n) {preq[i].clear(); sufq[i].clear();}
	rep(i, 1, totq) {
		if (ans2[i]) printf("%lld %lld\n", ans1[i], ans2[i]);
		else printf("%lld\n", ans1[i]);
		ans1[i] = ans2[i] = 0;
	}
}

int main() {
	int t = rd();
	while (t--) work();
	return 0;
}