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

#define N 1007

int a[N], ans[N];

int main() {
	int n = rd();
	for (int i = 1; i <= n; ++i) {ans[i] = 2e9; a[i] = rd();}
	for (int i = 1; i <= n; ++i) {
		int x = rd();
		for (int j = 1; j <= n; ++j) ans[j] = min(ans[j], abs(a[j] - x));
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) res = max(res, ans[i]);
	printf("%d\n", res);	
	return 0;
}