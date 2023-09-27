#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

inline ll rd() {
	ll x = 0;
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
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

vector<pii> s;

int a[N], b[N], ans[N];

set<pii> easy, waste, use;

int main() {
	int n = rd();
	ll S = rd();
	rep(i, 1, n) a[i] = rd();
	rep(i, 1, n) b[i] = rd();
	rep(i, 1, n) s.eb(a[i], i);
	sort(s.begin(), s.end());

	ll tot = 0;
	int mx = 0;
	for (auto [x, pos] : s) {
		tot += x;
		if (tot > S) {
			tot -= x;
			waste.insert(mp(b[pos], pos));
		} else {
			mx = x;
			ans[pos] = 1;
			easy.insert(mp(x, pos));
			use.insert(mp(b[pos] - a[pos], pos));
		}
	}

	while (!use.empty()) {
		if (waste.empty()) {
			auto [cstu, posu] = *use.begin();
			if (tot + cstu <= S) {
				tot += cstu; ans[posu] = 2;
				easy.erase(mp(a[posu], posu));
				use.erase(use.begin());
			} else break;
		} else {
			auto [cstu, posu] = *use.begin();
			int cstw = waste.begin() -> first - (--easy.end()) -> first;
			int posw = waste.begin() -> second;
			if (cstu < cstw) {
				if (tot + cstu <= S) {
					tot += cstu; ans[posu] = 2;
					easy.erase(mp(a[posu], posu));
					use.erase(use.begin());
				} else break;
			} else {
				if (tot + cstw <= S) {
					tot += cstw; ans[posw] = 2;
					waste.erase(waste.begin());
					auto epos = (--easy.end()) -> second;
					ans[epos] = 0;
					easy.erase(--easy.end());
					use.erase(mp(b[epos] - a[epos], epos));
					waste.insert(mp(b[epos], epos));
				} else break;
			}
			
		} 
	}
	rep(i, 1, n) printf("%d", ans[i]);
	return 0;
}