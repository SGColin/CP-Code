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

set<pair<int, int> > s;

int f[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

int main() {
	int n = rd(), m = rd();
	rep(i, 1, n) f[i] = i;
	rep(i, 1, m) f[find(rd())] = find(rd());
	int q = rd();
	rep(i, 1, q) {
		int a = find(rd()), b = find(rd());
		s.insert({a, b}); s.insert({b, a});
	}
	int k = rd();
	rep(i, 1, k) {
		int a = find(rd()), b = find(rd());
		puts(s.find({a, b}) == s.end() ? "Yes" : "No"); 
	}
	return 0;
}