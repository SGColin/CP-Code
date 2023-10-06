#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd(){
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define mp make_pair
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 1501

int a[N][N], r[N], c[N];

pii pos[N * N];

int main() {
	int n = rd();
	int m = n * n;
	rep(i, 1, n) rep(j, 1, n) pos[a[i][j] = rd()] = mp(i, j);
	ll tot = 0;
	rep(i, 1, m) {
		auto [x, y] = pos[i];
		tot += r[x] * c[y]; ++r[x]; ++c[y];
	}
	printf("%lld\n", 1ll * n * n * (n - 1) * (n - 1) / 2 - tot);
	return 0;
}