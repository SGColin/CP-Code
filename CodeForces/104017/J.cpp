#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd(){
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

vector<int> s;

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

inline void work() {
	int w = rd(), l = rd();
	auto add = [&](int x) {
		int lim = sqrt(x);
		rep(i, 1, lim) 
			if (x % i == 0) {
				s.push_back(i);
				s.push_back(x / i);
			}
	};
	add(gcd(w, l - 2));
	add(gcd(w - 2, l));
	add(gcd(w - 1, l - 1));
	add(gcd(w - 1, gcd(l - 2, l)));
	add(gcd(l - 1, gcd(w - 2, w)));
	sort(all(s));
	s.erase(unique(all(s)), s.end());
	printf("%d", (int)s.size());
	for (auto x : s) printf(" %d", x);
	puts(""); s.clear();
}

int main() {
	for (int t = rd(); t; --t) work();
	return 0;
}
