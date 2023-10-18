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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

inline void work() {
	int n = rd(), m = rd();
	ll tot = 1ll * n * (n + 1) / 2 * m * (m + 1) / 2;
	if (tot & 1) {puts("No"); return;}

	bool fl = false;
	if (m % 4 == 1 || m % 4 == 2) {fl = true; swap(n, m);}

	ll need = 1ll * m * (m - 3) / 4;
	vector<int> s;
	while (need) {
		int x = sqrt(2 * need);
		while (1ll * x * (x + 1) <= 2 * need) ++x;
		s.push_back(x);
		need -= 1ll * x * (x - 1) / 2;
	}
	vector<int> r;
	int nw = 0;
	for (auto x : s) {
		rep(i, 1, x) r.push_back(nw);
		nw ^= 1;
		m -=  x;
	}
	rep(i, 1, m) {r.push_back(nw); nw ^= 1;}

	puts("Yes");
	if (!fl) rep(i, 1, n) {for (auto x : r) printf("%d ", x); puts("");}
	else for (auto x : r) {rep(i, 1, n) printf("%d ", x); puts("");}
}

int main() {
	for (int t = rd(); t; --t) work();
	return 0;
}