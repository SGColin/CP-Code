#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

inline ll rd() {
	ll x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 101
#define mod 1000000007

inline int fpow(ll x, int t = mod - 2) {
	x = x % mod;
	int ret = 1;
	for (; t; t >>= 1, x = x * x % mod)
		if (t & 1) ret = ret * x % mod;
	return ret;
}

int fac[N] = {1}, ifac[N] = {1};

inline int C(ll n, ll m) {
	if (n < m) return 0;
	if (n - m < m) m = n - m;
	int res = ifac[m];
	for (int i = 0; i < m; ++i) 
		res = (n - i) % mod * res % mod;
	return res;
}

ll f[N];

int main() {
	for (int i = 1; i < N; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		ifac[i] = fpow(fac[i]);
	}
	int n = rd();
	ll tot = rd();
	for (int i = 0; i < n; ++i) f[i] = rd();
	int ans = 0;
	for (int S = 0; S < (1 << n); ++S) {
		ll sum = 0;
		for(int i = 0; i < n; ++i)
			if ((S >> i) & 1) sum += f[i] + 1;
		if (sum > tot) continue;
		int cof = ((__builtin_popcount(S) & 1) ? mod - 1 : 1);	
		int res = C(tot - sum + n - 1, n - 1);
		ans = (ans + 1ll * cof * res) % mod;
	}
	printf("%d\n", ans);
	return 0;
}