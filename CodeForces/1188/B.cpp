#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

vector<int> s;

int main() {
	int n = rd(), p = rd(), k = rd();
	for (int i = 1; i <= n; ++i) {
		int w = rd();
		int w2 = 1ll * w * w % p;
		int w4 = 1ll * w2 * w2 % p;
		s.push_back((w4 + p - 1ll * k * w % p) % p);
	}
	sort(s.begin(), s.end());
	
	ll ans = 0;
	int lst = -1, cnt = 0;
	for (auto x : s)
		if (x == lst) ++cnt;
		else {ans += 1ll * cnt * (cnt - 1) / 2; cnt = 1; lst = x;}
	ans += 1ll * cnt * (cnt - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}