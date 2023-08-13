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

#define mod 998244353
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
inline int SUM(int x, int y) {return x + y >= mod ? x + y - mod : x + y;}
inline int PROD(int x, int y) {return 1ll * x * y % mod;}

inline int fpow(int x, int t = mod - 2) {
	int res = 1;
	for (; t; t >>= 1, x = 1ll * x * x % mod)
		if (t & 1) res = 1ll * res * x % mod;
	return res;
}

//f[i][s] : the probability of that s is the set of numbers in [1, 10] we can represents using first i dices.
int f[101][1024], ans, n;

int main() {
	n = rd();
	f[0][0] = 1;
	rep(t, 1, n) {
		int a = rd();
		int inv = fpow(a);
		rep(s, 0, 1023) {
			rep(i, 1, min(a, 10)) {
				int tar = ((s | (s << i) | (1 << (i - 1))) & 1023);
				f[t][tar] = SUM(f[t][tar], PROD(f[t - 1][s], inv));
			}
			if (a > 10) f[t][s] = SUM(f[t][s], PROD(f[t - 1][s], PROD(a - 10, inv)));
		}
	}
	rep(s, 512, 1023) ans = SUM(ans, f[n][s]);
	printf("%d\n", ans);
	return 0;
}