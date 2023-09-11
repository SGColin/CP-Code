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

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 107
#define M 100007
#define mp make_pair
#define eb emplace_back
#define lb lower_bound
#define all(s) (s).begin(), (s).end()

int w[N], v[N];

ll f[M];

int main() {
	int n = rd(), m = 0;
	int tot = 0, ok = 0;
	rep(i, 1, n) {
		int x = rd(), y = rd(), z = rd();
		if (x > y) ok += z;
		else {
			tot += z;
			v[++m] = z;
			w[m] = (y - x + 1) / 2; 
		} 
	}
	if (ok > tot) {puts("0"); return 0;}
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	rep(i, 1, m) per(j, M - 1, v[i])
		f[j] = min(f[j], f[j - v[i]] + w[i]);
	ll ans = 1e18;
	rep(j, (tot - ok + 1) / 2, M - 1) ans = min(ans, f[j]);
	printf("%lld\n", ans);
	return 0;
}