#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

inline int rd(){
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007

int c[N];
inline int lowbit(int x) {return x & (-x);}
inline void add(int p, int w) {for (; p < N; p += lowbit(p)) c[p] = max(c[p], w);}
inline int premx(int p) {int res = 0; for (; p; p -= lowbit(p)) res = max(res, c[p]); return res;}

ll t[N];

vector<pll> a;

vector<ll> s;

int main() {
	int n = rd(), v = rd();
	rep(i, 1, n) t[i] = 1ll * rd() * v;
	rep(i, 1, n) {
		int w = rd(); 
		if (abs(w) > t[i]) continue;
		a.eb(t[i] - w, t[i] + w);
	}
	sort(all(a));
	for (auto [x, y] : a) s.push_back(y);
	sort(all(s));
	s.erase(unique(all(s)), s.end());
	for (auto [x, y] : a) {
		int nw = lower_bound(all(s), y) - s.begin() + 1;
		add(nw, premx(nw) + 1);
	}
	printf("%d\n", premx(N - 1));
	return 0;
}