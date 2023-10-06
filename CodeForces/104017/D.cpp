#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<double, int> pdi;

inline int rd(){
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 200007

vector<pdi> s;

int p[N], x[N];

inline void work() {
	int n = rd(), m = rd();
	rep(i, 1, n) p[i] = rd();
	rep(i, 1, m) x[i] = rd();
	sort(x + 1, x + 1 + m);
	int ptr = 0, pos = 0;
	rep(i, 1, n) {
		while (ptr < m && x[ptr + 1] <= pos) ++ptr;
		double dis = 2e9;
		if (ptr > 0) dis = min(dis, 1.0 * abs(pos - x[ptr]));
		if (ptr < m) dis = min(dis, 1.0 * abs(x[ptr + 1] - pos));
		s.emplace_back(pos - dis + 0.1, p[i]);
		s.emplace_back(pos + dis - 0.1, -p[i]);
		pos += 100;
	}
	sort(s.begin(), s.end());
	double lst = s.begin() -> first;
	ll nw = 0, ans = 0;
	for (auto [loc, w] : s) {
		//printf("%.2lf %d\n", loc, w);
		if (fabs(loc - lst) > 0.01) ans = max(ans, nw);
		nw += w; lst = loc;
	}
	ans = max(ans, nw);
	printf("%lld\n", ans);
}

int main() {
	work();
	return 0;
}
