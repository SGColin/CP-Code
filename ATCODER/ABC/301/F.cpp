#include <bits/stdc++.h>
using namespace std;

#define N 300007
#define mod 998244353
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i) 


char s[N];

int suf[N], pow52[N] = {1}, pow26[N] = {1};

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	rep(i, 1, n) {
		pow52[i] = pow52[i - 1] * 52ll % mod;
		pow26[i] = pow26[i - 1] * 26ll % mod;
	}
	for (auto x : s) {

	}
	return 0;
}