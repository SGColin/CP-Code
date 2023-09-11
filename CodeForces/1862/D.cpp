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

#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

inline void work() {
	ll n = rd();
	if (n == 1) {puts("2"); return;}
	ll l = 1, r = 2000000000;
	while (l < r) {
		ll mid = (l + r + 1) / 2;
		mid * (mid - 1) / 2 > n ? r = mid - 1 : l = mid;
	}
	printf("%lld\n", l + n - l * (l - 1) / 2);
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}