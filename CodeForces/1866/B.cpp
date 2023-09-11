#include <bits/stdc++.h>
using namespace std;

#define N 100007
#define mod 998244353
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int a[N], b[N], c[N], d[N];

int main() {
	int n; cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> b[i];
	int m; cin >> m;
	rep(i, 1, m) cin >> c[i];
	rep(i, 1, m) cin >> d[i];
	int ptr = 1, ans = 1;
	rep(i, 1, m) {
		for (; ptr <= n && a[ptr] < c[i]; ++ptr) ans = (ans << 1) % mod;
		if (ptr > n || a[ptr] != c[i] || b[ptr] < d[i]) {cout << "0" << endl; return 0;}
		if (b[ptr] > d[i]) ans = (ans << 1) % mod;
		++ptr;
	}
	for (; ptr <= n; ++ptr) ans = (ans << 1) % mod;
	printf("%d\n", ans);
	return 0;
}