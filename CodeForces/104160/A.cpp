#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<double, double, double> tddd;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 1000007

tddd a[N], b[N];

vector<pii> A, B;

vector<int> p;

int main() {
	int n = rd(), m = rd();
	double tota = 0, totb = 0;
	bool fa = false, fb = false;
	rep(i, 1, n) {
		int l = rd(), r = rd(); 
		A.eb(l, r); p.eb(l); p.eb(r); 
		fa |= (l != r); tota += (r - l);
	}
	rep(i, 1, m) {
		int l = rd(), r = rd(); 
		B.eb(l, r); p.eb(l); p.eb(r); 
		fb |= (l != r); totb += (r - l);
	}
	if (!tota) tota = n;
	if (!totb) totb = m;
	n = m = 0;
	sort(all(A)); sort(all(B)); 
	sort(all(p)); p.erase(unique(all(p)), p.end());
	for (auto [l, r] : A) {
		if (l == r) {if (!fa) a[++n] = mt(l, r, 1.0 / tota); continue;} 
		while (l != r) {
			int nxt = *upper_bound(all(p), l);
			a[++n] = mt(l, nxt, (nxt - l) / tota);
			l = nxt;
		}
	}
	for (auto [l, r] : B) {
		if (l == r) {if (!fb) b[++m] = mt(l, r, 1.0 / totb); continue;} 
		while (l != r) {
			int nxt = *upper_bound(all(p), l);
			b[++m] = mt(l, nxt, (nxt - l) / totb);
			l = nxt;
		}
	}

	double ppre = 0, mpre = 0, psuf = 1, msuf = 0;
	rep(i, 1, m) {auto [l, r, p] = b[i]; msuf += p * (l + r) / 2;}

	double ans = 0;

	int ptr = 1;
	rep(i, 1, n) {
		auto [_l, _r, _p] = a[i];
		for (; ptr <= m; ++ptr) {
			auto [l, r, p] = b[ptr];
			if (r > _l || (l == _r)) break;
			mpre += p * (l + r) / 2; ppre += p;
			msuf -= p * (l + r) / 2; psuf -= p;
		}
		double mid = (_l + _r) / 2;
		double nw = mid * ppre - mpre;
		if (ptr <= m) {
			auto [l, r, p] = b[ptr];
			if (l == _l && r == _r) {
				nw += p * (r - l) / 3; 
				mpre += p * (l + r) / 2; ppre += p;
				msuf -= p * (l + r) / 2; psuf -= p;
				++ptr;
			}
		}
		nw += (msuf - mid * psuf);
		ans += nw * _p;
	}
	printf("%.12lf\n", ans);
	return 0;
}