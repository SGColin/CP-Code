#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 1000007

int cnt[N];

int main() {
	int n = rd();
	rep(i, 1, n) ++cnt[rd()];
	ll ans = 0;
	rep(i, 1, N - 7)
		if (cnt[i]) {
			rep(j, i + 1, N) {
				ll d = 1ll * j * j - 1ll * i * i;
				if (d > 1000000) break;
				ans += 1ll * cnt[i] * cnt[d];
			}
		}
	printf("%lld\n", ans);
	return 0;
}