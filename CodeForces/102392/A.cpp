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

#define N 200007

int a[N];

vector<int> pos[N];

struct node {int pre, suf, ans;} c[N * 5];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) / 2)
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int nw = 1;

void pushup(int rt, int l, int r) {
	bool fl = (1ll * (a[mid] - nw) * (a[mid + 1] - nw) < 0ll);
	c[rt].pre = c[ls].pre; 
	c[rt].suf = c[rs].suf;
	c[rt].ans = c[ls].ans + c[rs].ans;
	if (!fl) { // cannot connect
		if (c[ls].suf != mid - l + 1) c[rt].ans += c[ls].suf / 2;
		if (c[rs].pre != r - mid) c[rt].ans += c[rs].pre / 2;
	} else { // connected
		if (c[ls].suf == mid - l + 1) {fl = false; c[rt].pre = c[rs].pre + mid - l + 1;}
		if (c[rs].pre == r - mid) {fl = false; c[rt].suf = c[ls].suf + r - mid;}
		if (fl) c[rt].ans += (c[ls].suf + c[rs].pre) / 2;
	}	
}

void build(int rt, int l, int r) {
	if (l == r) c[rt] = (a[l] == nw ? (node){0, 0, 0} : (node){1, 1, 0});
	else {build(ls, l, mid); build(rs, mid + 1, r); pushup(rt, l, r);}
}

void upd(int rt, int l, int r, int pos) {
	if (l == r) c[rt] = (a[l] == nw ? (node){0, 0, 0} : (node){1, 1, 0});
	else {
		pos <= mid ? upd(ls, l, mid, pos) : upd(rs, mid + 1, r, pos); 
		pushup(rt, l, r);
	}
	//printf("[%d, %d], pre = %d, suf = %d, ans = %d\n", l, r, c[rt].pre, c[rt].suf, c[rt].ans);
}

int main() {
	int n = rd(), m = rd();
	rep(i, 1, n) pos[a[i] = rd()].push_back(i);
	build(1, 1, n);
	auto calc = [&]() {
		if (pos[nw].empty()) return -1;
		auto [pre, suf, ans] = c[1];
		ans += n - pos[nw].size();
		bool fl = (1ll * (a[1] - nw) * (a[n] - nw) < 0ll);
		return fl ? ((pre + suf) / 2 + ans) : (pre / 2 + suf / 2 + ans);
	};
	printf("%d ", calc());
	rep(i, 2, m) {
		nw = i;
		rep(j, i - 1, i + 1) for (auto x : pos[j]) upd(1, 1, n, x);
		printf("%d ", calc());
	}
	return 0;
}