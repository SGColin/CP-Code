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

#define N 100007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

int n, a[N];

inline void work() {
	int n = rd();
	rep(i, 2, n) a[i] = a[i - 1] + rd();
	int p = 1, e = n;
	ll pre = 0, ans = 0;
	rep(i, 1, n) {
		if (!(i & 1)) {
			pre += a[e] - a[p];
			--e; ++p;
		}
		ans += pre;
		if (i > 1) putchar(' ');
		printf("%lld", ans);
	}
	puts("");
}

int main() {
	int t = rd();
	while (t--) work();
	return 0;
}