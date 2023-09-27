#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;


inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 200007
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

vector<pii> s;

int main() {
	int n = rd(), k = rd(), big = 0;
	rep(i, 1, n) {
		int l = rd(), r = rd();
		if (r - l + 1 >= k) ++big;
		else {
			l = l % k;
			r = r % k;
			if (l > r) {
				s.eb(0, 1);
				s.eb(r + 1, -1);
				s.eb(l, 1);
				s.eb(k, -1);
			} else {
				s.eb(l, 1);
				s.eb(r + 1, -1);
			}
		}
	}
	if (s.empty()) {printf("%d\n", big); return 0;}
	sort(s.begin(), s.end());
	int lst = s[0].first, ans = 0, tmp = 0;
	for (auto [pos, v] : s) {
		if (pos != lst) ans = max(ans, tmp);
		tmp += v; lst = pos;
	}
	ans = max(ans, tmp);
	printf("%d\n", ans + big);
	return 0;
}