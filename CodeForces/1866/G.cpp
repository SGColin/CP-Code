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

#define N 200007
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int n, a[N], L[N], R[N], id[N], rem[N];

#define mid ((l + r) / 2)

/* segment tree solution: 1326ms

bool fil[N];

#define ls (rt << 1)
#define rs (rt << 1 | 1)

void pushup(int rt) {fil[rt] = fil[ls] && fil[rs];}

void build(int rt, int l, int r) {
	fil[rt] = false;
	if (l == r) return;
	build(ls, l, mid);
	build(rs, mid + 1, r);
}

int cover(int rt, int l, int r, int L, int R, int x) {
	if (fil[rt]) return x;
	if (l == r) {
		int dlt = min(rem[l], x);
		x -= dlt; rem[l] -= dlt; 
		fil[rt] = (rem[l] == 0);
		return x;
	}
	if (L <= mid) x = cover(ls, l, mid, L, R, x);
	if (!x) {pushup(rt); return x;}
	if (R > mid) x = cover(rs, mid + 1, r, L, R, x);
	pushup(rt); return x;
}

bool valid(int x) {
	build(1, 1, n);
	rep(i, 1, n) rem[i] = x;
	rep(i, 1, n) if (cover(1, 1, n, L[id[i]], R[id[i]], a[id[i]])) return false;
	return true;
}
*/

/* set solution: 2464ms

set<int> s;

bool valid(int x) {
	rep(i, 1, n) {rem[i] = x; s.insert(i);}
	rep(i, 1, n) {
		int lb = L[id[i]], rb = R[id[i]], num = a[id[i]];
		while (num) {
			auto it = s.lower_bound(lb);
			if (it == s.end()) return false;
			int x = *it;
			if (x > rb) return false;
			int del = min(rem[x], num);
			rem[x] -= del; num -= del;
			if (!rem[x]) s.erase(x);
		}
	}
	return true;
}

*/

// Union-Find Set solution

int f[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

bool valid(int x) {
	rep(i, 1, n + 1) {rem[i] = x; f[i] = i;}
	rep(i, 1, n) {
		int lb = L[id[i]], rb = R[id[i]], num = a[id[i]];
		while (num) {
			int p = find(lb);
			if (p > rb) return false;
			int del = min(rem[p], num);
			rem[p] -= del; num -= del;
			if (!rem[p]) f[p] = p + 1;
		}
	}
	return true;
}

int main() {
	n = rd();
	rep(i, 1, n) a[i] = rd();
	rep(i, 1, n) {
		int d = rd();
		id[i] = i;
		L[i] = max(1, i - d); 
		R[i] = min(n, i + d);
	}
	sort(id + 1, id + 1 + n, [&](int x, int y) {return R[x] < R[y];});
	int l = 0, r = 1e9 + 1;
	while (l < r) {valid(mid) ? r = mid : l = mid + 1;}
	printf("%d\n", l);
	return 0;
}