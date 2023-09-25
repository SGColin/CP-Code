#include <bits/stdc++.h>
using namespace std;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

const double PI = 3.1415926535897932384626433832795;

inline double sqr(double x) {return x * x;}

inline void work() {
	int a = rd(), b = rd(), r = rd(), d = rd();
	double ang = atan(1.0 * b / (r + a));
	double dd = d * PI / 180;
	if (dd > ang) printf("%.12lf\n", sqrt(sqr(b) + sqr(r + a)) - r);
	else printf("%.12lf\n", cos(ang - dd) * sqrt(sqr(b) + sqr(r + a)) - r);
}

int main() {
	int t = rd();
	while (t--) work();
	return 0;
}