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

#define N 20001
#define mod 1000000007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

inline void add(int &a, int b) {a = (a + b >= mod ? a + b - mod : a + b);}

int f[N], g[N], bs = 10000;

int main() {
	int n = rd(), sum = 0;
	rep(p, 1, n) {
		int w = rd();
		rep(i, 0, N - 1) 
			if (g[i]) {add(f[i + w], g[i]); add(f[i - w], g[i]);}
		add(f[bs + w], 1); add(f[bs - w], 1);
		rep(i, 0, N - 1) {g[i] = f[i]; f[i] = 0;}
		add(sum, g[bs]);
	}
	printf("%d\n", sum);
	return 0;
}