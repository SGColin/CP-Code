#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline char rdc(){
	static char buf[1 << 16], *l = buf, *r = buf;
	return l == r && (r = (l = buf) + fread(buf, 1, 1 << 16, stdin), l == r) ? EOF : *l++;
}

inline ll rd() {
	ll x = 0;
	bool f = 0;
	char c = rdc();
	for (; !isdigit(c); c = rdc()) f |= (c == '-');
	for (; isdigit(c); c = rdc()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 1000007

int hd = 1, tl = 1;

struct sqr {int x, y; ll a;} s[N];

ll dp[N], ans;

struct line {
	ll k, b;
	line(ll _k = 0, ll _b = 0) : k(_k), b(_b) {}
	ll getv(ll x) {return 1ll * k * x + b;}
	double inter(const line &obj) {return (obj.b - b) / (1.0 * k - obj.k);}
} q[N];

int main() {
	int n = rd();
	rep(i, 1, n) {s[i].x = rd(); s[i].y = rd(); s[i].a = rd();}
	sort(s + 1, s + 1 + n, [&](const sqr &a, const sqr &b){return a.x < b.x;});
	rep(i, 1, n) {
		while (tl > hd && q[hd].getv(s[i].y) < q[hd + 1].getv(s[i].y)) ++hd;
		dp[i] = q[hd].getv(s[i].y) + 1ll * s[i].x * s[i].y - s[i].a;
		line nw(-s[i].x, dp[i]);
		while (tl > hd && q[tl].inter(nw) > q[tl].inter(q[tl - 1])) --tl;
		q[++tl] = nw;
		ans = max(ans, dp[i]);
	}
	printf("%lld\n", ans);
	return 0;
}