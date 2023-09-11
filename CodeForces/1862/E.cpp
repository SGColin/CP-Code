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

#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

multiset<int> s;

inline void work() {
	int n = rd(), m = rd() - 1, d = rd();
	s.clear();
	ll ans = 0, sum = 0;
	rep(i, 1, n) {
		int x = rd();
		if (x <= 0) continue;
		sum += x; s.insert(x);
		ans = max(ans, sum - 1ll * i * d);
		while (s.size() > m) {
			sum -= *s.begin(); s.erase(s.begin());
		}
	}
	printf("%lld\n", ans);
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}