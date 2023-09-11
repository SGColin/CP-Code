#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 200007
#define mod 998244353
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

inline int mo(int x) {return x >= mod ? x - mod : x;}

int fac[N], ifac[N];

inline int fpow(int x, int t = mod - 2) {
	int res = 1;
	for (; t; t >>= 1, x = 1ll * x * x % mod)
		if (t & 1) res = 1ll * res * x % mod;
	return res;
}

inline int C(int n, int m) {
	if (n > m) return 0;
	return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

int main() {
	fac[0] = ifac[0] = 1;
	rep(i, 1, N) fac[i] = 1ll * fac[i - 1] * i % mod;
	ifac[N - 1] = fpow(fac[N - 1]);
	per(i, N - 2, 1) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;

	int n = rd(), k = rd(), ans = 0;
	per(i, min(n, k), 0) {
		int cnti = 1ll * fac[i] * (fpow(i + 1, k - i + 1) + mod - fpow(i, k - i + 1)) % mod; 
		ans = (ans + 1ll * cnti * fac[n] % mod * ifac[n - i] % mod) % mod;
	}
	printf("%d\n", ans);
	return 0;
}