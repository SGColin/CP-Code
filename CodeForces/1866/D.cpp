#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 100007
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

ll f[N];

int a[11][N], sum[N];

int main() {
	int n = rd(), m = rd(), k = rd();
	rep(i, 1, n) rep(j, 1, m) a[i][j] = rd();
	rep(j, 1, m) {
		rep(i, 1, n) sum[i] = a[i][j];
		sort(sum + 1, sum + 1 + n, greater<int>());
		rep(i, 1, n) sum[i] += sum[i - 1];
		per(t, j, max(0, j - k + 1))
			rep(_t, max(0, j - k), t - 1) f[t] = max(f[t], f[_t] + sum[t - _t]);
	}
	printf("%lld\n", f[m - k + 1]);
	return 0;
}