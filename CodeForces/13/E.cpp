#include <bits/stdc++.h>
using namespace std;

inline char rdc(){
	static char buf[1 << 16], *l = buf, *r = buf;
	return l == r && (r = (l = buf) + fread(buf, 1, 1 << 16, stdin), l == r) ? EOF : *l++;
}

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = rdc();
	for (; !isdigit(c); c = rdc()) f |= (c == '-');
	for (; isdigit(c); c = rdc()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 100007

int a[N], L[N], R[N], tim[N], lst[N];

int main() {
	int n = rd(), q = rd();
	int m = sqrt(n);
	rep(i, 0, n - 1) {
		a[i] = rd();
		if (i % m == 0) L[i / m] = i;
		R[i / m] = i;
	}

	auto build = [&](int p) {
		int tar = p + a[p];
		if (tar > R[p / m]) {
			tim[p] = 1;
			lst[p] = p;
		} else {
			tim[p] = 1 + tim[tar];
			lst[p] = lst[tar];
		}
	};

	per(i, n - 1, 0) build(i);

	rep(t, 1, q) {
		int op = rd(), pos = rd() - 1;
		if (op) {
			int tot = 0, end = 0;
			for (; pos < n; pos = end + a[end]) {
				tot += tim[pos]; end = lst[pos];
			} 
			printf("%d %d\n", end + 1, tot);
		} else {
			int b = rd();
			a[pos] = b;
			int l = L[pos / m];
			per(i, pos, l) build(i);
		}
	}
	return 0;
}