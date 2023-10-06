#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 1000007

vector<int> t, s;

ll query() {
	printf("? %d", (int)s.size());
	for (auto x : s) printf(" %d", x);
	puts(""); fflush(stdout);
	return rd();
}

void NO() {puts("! NO"); fflush(stdout);}

void YES() {puts("! YES"); fflush(stdout);}

int main() {
	srand(time(0));
	int n = rd();
	rep(i, 1, n) t.push_back(i);
	s = t;
	ll tot = query();
	rep(i, 1, 29) {
		random_shuffle(t.begin(), t.end());
		s.clear(); rep(i, 1, n / 2) s.push_back(t[i - 1]);
		ll a = query();
		s.clear(); rep(i, n / 2 + 1, n) s.push_back(t[i - 1]);
		ll b = query();
		if ((tot - a - b) % 2 == 1) {NO(); return 0;}
	}
	YES();
	return 0;
}