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
#define mt make_tuple
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

vector<int> s;

int main() {
	int n = rd(), m = rd();
	rep(i, 1, n) s.pb(rd());

	auto valid = [&](ll x) {
		int cnt = 1;
		ll nwl = -1;
		for (auto t : s) {
			if (t > x) return false;
			if (nwl + 1 + t <= x) nwl += 1 + t;
			else {++cnt; nwl = t;}
		}
		return cnt <= m;
	};

	ll l = 1, r = 1e18;
	while (l < r) {
		ll mid = (l + r) / 2;
		valid(mid) ? r = mid : l = mid + 1;
	}
	printf("%lld\n", l);
	return 0;
}