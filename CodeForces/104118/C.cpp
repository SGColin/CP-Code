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

#define N 200007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

int a[N], cntt[N];

unordered_map<int, int> cnt;

int main() {
	int n = rd();
	int k = min(rd(), (int)sqrt(n) + 1);
	rep(i, 1, n) a[i] = rd();
	rep(i, 1, n) ++cnt[a[i]];
	rep(i, 1, n) a[i] = cnt[a[i]];
	rep(t, 2, k) {
		rep(i, 1, n) cntt[a[i]] = 0;
		rep(i, 1, n) ++cntt[a[i]];
		rep(i, 1, n) a[i] = cntt[a[i]];
	}
	rep(i, 1, n) printf("%d ", a[i]);
	return 0;
}