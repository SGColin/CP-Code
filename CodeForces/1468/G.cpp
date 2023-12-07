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

#define N 200007
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define T double
const T eps = 1e-9;
#define z(x) (abs((x)) <= eps) // is zero

struct P {
	T x, y;
	P (T x = 0, T y = 0) : x(x), y(y) {}
	P operator + (const P &p) const {return {x + p.x, y + p.y};} 
	P operator - (const P &p) const {return {x - p.x, y - p.y};} 
    P operator * (const T &d) const {return {x * d, y * d};}
    P operator / (const T &d) const {return {x / d, y / d};}
    P operator - () const {return {-x, -y};}

    T operator | (const P &p) const {return x * p.x + y * p.y;} // dot
    T operator ^ (const P &p) const {return x * p.y - y * p.x;} // cross

    T abs() const {return sqrt(x * x + y * y);}
    int ori(const P &p) const {T t = (*this) ^ p; return (t > eps) - (t < -eps);}
} a[N], p, zero;

struct L {
    P p, v;
    L(const P &p = zero, const P &v = zero) : p(p), v(v) {}
    int ori (const P &a) const {return v.ori(a - p);} 
    P inter(const L &l) const {return p + v * ((l.v ^ (p - l.p)) / (v ^ l.v));} 
};

bool orth(const L &p, const L &q) {return z(p.v | q.v);} // orthogonal
bool para(const L &p, const L &q) {return z(p.v ^ q.v);} // parallel

int main() {
	int n = rd(), H = rd();
	rep(i, 1, n) {a[i].x = rd(); a[i].y = rd();}
	p = a[n]; p.y += H;
	L l{p, a[n] - p};
	double ans = 0;
	per(i, n, 1) if (l.ori(a[i]) <= 0) {
		L tmp{a[i], a[i + 1] - a[i]};
		if (para(tmp, l)) ans += (a[i] - a[i + 1]).abs();
		else ans += (l.inter(tmp) - a[i]).abs();
		l.v = a[i] - p;
	}
	printf("%.10lf\n", ans);
	return 0;
}