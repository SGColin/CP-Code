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

#define N 507
#define pb push_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

bitset<N> b[N], c[N], ans[N], nw, choose;

int main() {
	int n = rd();
	rep(i, 1, n) {
		nw.reset();
		choose.reset();
		choose[i] = true;
		rep(j, 1, n) nw[j] = rd();
		rep(j, 1, n) 
			if (nw[j]) {
				if (b[j] == 0) {b[j] = nw; c[j] = choose; break;}
				else {nw ^= b[j]; choose ^= c[j];}
			}
	}
	rep(i, 1, n) {
		nw = b[i];
		ans[i] = c[i];
		rep(j, i + 1, n) {
			if (nw[j]) {nw ^= b[j]; ans[i] ^= c[j];}
			if (nw[j]) {puts("-1"); return 0;}
		}
	}
	rep(i, 1, n) {
		rep(j, 1, n) if (ans[i][j]) printf("%d ", j);
		puts("");
	}
	return 0;
}