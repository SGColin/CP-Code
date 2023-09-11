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

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 100007

int hd = 1, tl = 1, d[N], a[N];

ll sum[N], f[N], g[N];

struct line {
	ll k, b;
	line(ll _k = 0, ll _b = 0) : k(_k), b(_b) {}
	ll getv(ll x) {return 1ll * k * x + b;}
	double inter(const line &obj) {return (obj.b - b) / (1.0 * k - obj.k);}
} q[N];

int main() {
	int n = rd(), m = rd(), p = rd();
	rep(i, 2, n) d[i] = d[i - 1] + rd();
	rep(i, 1, m) {int h = rd(); a[i] = rd() - d[h];}
	sort(a + 1, a + 1 + m);
	rep(i, 1, m) {
		sum[i] = sum[i - 1] + a[i];
		g[i] = 1ll * i * a[i] - sum[i];
	}
	rep(t, 2, p) {
		hd = tl = 1;
		rep(i, 1, m) {
			while (tl > hd && q[hd].getv(a[i]) > q[hd + 1].getv(a[i])) ++hd;
			f[i] = q[hd].getv(a[i]) + 1ll * a[i] * i - sum[i];
			line nw(-i, g[i] + sum[i]);
			while (tl > hd && q[tl].inter(nw) < q[tl].inter(q[tl - 1])) --tl;
			q[++tl] = nw;
		}
		rep(i, 1, m) g[i] = f[i];
	}
	printf("%lld\n", f[m]);
	return 0;
}