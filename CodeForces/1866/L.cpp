#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tii;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 100007
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

int main() {
	int n = rd(), m = rd();
	auto sum = [&](ll a, ll d) {
		if (a > n) return 0ll;
		int cnt = (n - a) / d + 1;
		return (a * 2 + d * (cnt - 1)) * cnt / 2;
	};
	ll ans = 0, bst = 1;
	rep(i, 2, m) {
		ll tmpans = 0;
		if (n % i == 0) tmpans = sum(i, i);
		else {
			if (gcd(n, i) != 1) continue; 
			int cnt = 1, nw = i;
			rep(j, 1, i) {
				if (cnt < nw) tmpans += sum(nw, i);
				else {
					int tim = (cnt - nw + i - 2) / (i - 1);
					if (tim == (cnt - nw) / (i - 1)) ++tim;
					tmpans += sum(nw + i * tim, i);
				}
				int add = (n - nw) / i + 1;
				nw = (nw + add * i - 1) % n + 1;
				cnt += add;
			}
		}
		if (tmpans > ans) {ans = tmpans; bst = i;}
	}
	printf("%lld\n", bst);
	return 0;
}