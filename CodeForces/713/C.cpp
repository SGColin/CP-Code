#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 3007

int a[N], b[N];

ll f[N], mn[N];

int main() {
	int n = rd();
	for (int i = 1; i <= n; ++i) a[i] = b[i] = rd() - i;
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) f[j] = mn[j] + abs(a[i] - b[j]);
		mn[1] = f[1];
		for (int j = 2; j <= n; ++j) mn[j] = min(mn[j - 1], f[j]);
	}
	printf("%lld\n", mn[n]);
	return 0;
}
