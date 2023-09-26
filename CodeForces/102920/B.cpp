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

#define pb push_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;} 

int main() {
	vector<int> a, b;
	rep(i, 1, 6) a.pb(rd());
	rep(i, 1, 6) b.pb(rd());
	int ans = 0;
	for (auto x : a) for (auto y : b) ans += (x > y);
	int g = gcd(36, ans);
	printf("%d/%d\n", ans / g, 36 / g);
	return 0;
}