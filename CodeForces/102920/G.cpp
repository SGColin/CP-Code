#include <bits/stdc++.h>
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

#define N 1000007
#define pb push_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

ll a[N];

int main() {
	ll n = rd(), D = rd() * 2;
	rep(i, 1, n) a[i] = rd() * 2;

	auto valid = [&](ll d) {
		ll l = a[1] - d, r = a[1] + d;
		rep(i, 2, n) {
			l = max(l, a[i] - d - D * (i - 1));
			r = min(r, a[i] + d - D * (i - 1));
		}
		//printf("%lld %lld %lld\n", d, l, r);
		if (r >= l) return true;
		l = a[1] - d, r = a[1] + d;
		rep(i, 2, n) {
			l = max(l, a[i] - d + D * (i - 1));
			r = min(r, a[i] + d + D * (i - 1));
		}
		return r >= l;
	};

	ll l = 0, r = 1e18;
	while (r > l) {
		ll mid = (l + r) / 2;
		valid(mid) ? r = mid : l = mid + 1;
	}
	printf("%lld.%lld\n", l / 2, 5 * (l & 1));
	return 0;
}
