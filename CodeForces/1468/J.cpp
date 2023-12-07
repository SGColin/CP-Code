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

#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 200007

int f[N];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

struct edge{
	int u, v, w;
	inline bool operator < (const edge &obj) const {return w < obj.w;}
} e[N];

inline void work() {
	int n = rd(), m = rd(), k = rd(), mnd = 2e9;
	rep(i, 1, n) f[i] = i;
	rep(i, 1, m) {
		e[i].u = rd(); e[i].v = rd(); e[i].w = rd(); 
		mnd = min(mnd, abs(e[i].w - k));
	}
	sort(e + 1, e + 1 + m);
	ll ans = 0;
	rep(i, 1, m) {
		if (find(e[i].u) != find(e[i].v)) {
			f[find(e[i].u)] = find(e[i].v);
			ans += max(0, e[i].w - k);
		}
	}
	if (ans == 0ll) printf("%d\n", mnd);
	else printf("%lld\n", ans);
}

int main() {
	int t = rd();
	while(t--) work();
	return 0;
}