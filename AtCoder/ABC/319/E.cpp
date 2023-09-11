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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 100007

int n, X, Y, p[N], t[N];

ll ans[841];

int main() {
	n = rd() - 1; X = rd(); Y = rd();
	rep(i, 1, n) {p[i] = rd(); t[i] = rd();}
	rep(t0, 0, 839) {
		ll nw = t0 + X;
		rep(i, 1, n) nw += (nw % p[i] == 0 ? 0 : p[i] - nw % p[i]) + t[i];
		ans[t0] = nw + Y;
	}
	int q = rd();
	rep(i, 1, q) {
		int t0 = rd();
		printf("%lld\n", t0 / 840 * 840 + ans[t0 % 840]);
	}
	return 0;
}