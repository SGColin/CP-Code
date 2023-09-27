#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;


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
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

set<pii> _s, s;

ll w[N], sum;

int pre[N], nxt[N];

int main() {
	int n = rd();
	rep(i, 1, n) {
		w[i] = rd(); sum += w[i];
		s.insert(mp(w[i], i));
		_s.insert(mp(w[i], -i));
		pre[i] = i - 1; nxt[i] = i + 1;
	}
	auto del = [&](int pos) {
		sum -= w[pos];
		s.erase(mp(w[pos], pos));
		_s.erase(mp(w[pos], -pos));
	};
	auto add = [&](int pos, ll val) {
		sum -= w[pos];
		s.erase(mp(w[pos], pos));
		_s.erase(mp(w[pos], -pos));
		w[pos] += val;
		sum += w[pos];
		s.insert(mp(w[pos], pos));
		_s.insert(mp(w[pos], -pos));
	};
	nxt[n] = 0;
	rep(i, 1, n) {
		ll mx = (--_s.end()) -> first;
		if (mx <= sum - mx) {
			int pos = (--_s.end()) -> second; 
			pos = -pos; del(pos);
			printf("%d %lld\n", pos, mx);
			if (pre[pos]) {add(pre[pos], mx / 2); nxt[pre[pos]] = nxt[pos];} 
			if (nxt[pos]) {add(nxt[pos], mx / 2); pre[nxt[pos]] = pre[pos];}
		} else {
			auto [mn, pos] = *s.begin(); del(pos);
			printf("%d %lld\n", pos, mn);
			if (pre[pos]) {add(pre[pos], mn / 2); nxt[pre[pos]] = nxt[pos];} 
			if (nxt[pos]) {add(nxt[pos], mn / 2); pre[nxt[pos]] = pre[pos];}
		}
	}
	return 0;
}