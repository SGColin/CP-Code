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

int main() {
	int n = rd(), p = rd(), q = rd();
	int mn = 2e9;
	for (int i = 1; i <= n; ++i) mn = min(mn, rd());
	printf("%d\n", min(p, q + mn));
	return 0;
}