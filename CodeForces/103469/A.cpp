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

vector<int> s;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

inline void work() {
	s.clear(); 
	int n = rd();
	rep(i, 1, n) s.push_back(rd());
	int asum = s[0], mn = s[0];
	for (auto x : s) {asum &= x; mn = min(mn, x);}
	if (asum < mn) {puts("-1"); return;}
	printf("%d\n", n * 2);
	for (auto x : s) printf("%d %d ", mn, x);
	puts("");
}

int main() {
	for (int t = rd(); t; --t) work();
	return 0;
}