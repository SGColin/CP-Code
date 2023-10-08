#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

inline void getmax(ll &a, ll b) {a = (a > b ? a : b);}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define K 7
#define N 100007

int a[N], id[N], s[N][K];

ll dp[N][1 << K];

int main() {
	int n = rd(), p = rd(), k = rd();
	rep(i, 1, n) id[i] = i, a[i] = rd();
	rep(i, 1, n) rep(j, 0, p - 1) s[i][j] = rd();
	sort(id + 1, id + 1 + n, [&](int x, int y){return a[x] > a[y];});
	
	memset(dp, 0xcf, sizeof(dp)); dp[0][0] = 0;

	int lim = (1 << p) - 1;
	rep(i, 1, n) {
		rep(v, 0, lim) {
			int cnt = __builtin_popcount(v);
			getmax(dp[i][v], dp[i - 1][v] + (i - cnt <= k ? a[id[i]] : 0));
			rep(j, 0, p - 1) {
				if ((v >> j) & 1) continue;
				getmax(dp[i][v | (1 << j)], dp[i - 1][v] + s[id[i]][j]);
			}
		}
	}
	printf("%lld\n", dp[n][lim]);
	return 0;
}