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

#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007

int a[N];

set<pii> s;

multiset<int> gap;

inline void work() {
	int n = rd();
	s.clear(); gap.clear();
	rep(i, 1, n) s.insert(make_pair(a[i] = rd(), i));
	ll sum = 0, lst = s.begin() -> first;
	for (auto [x, i] : s) {gap.insert(x - lst); sum += x - lst; lst = x;}

	auto modify = [&](int p, int x) {
		auto lst = make_pair(a[p], p);
		auto nw = make_pair(a[p] = x, p);
		if (lst == *s.begin()) {
			s.erase(s.begin());
			int len = (s.begin() -> first) - lst.first;
			sum -= len; gap.erase(gap.find(len));
		} else if (lst == *--s.end()) {
			s.erase(--s.end());
			int len = lst.first - ((--s.end()) -> first);
			sum -= len; gap.erase(gap.find(len));
		} else {
			auto [prex, pre] = *--s.find(lst);
			auto [nxtx, nxt] = *++s.find(lst);
			gap.erase(gap.find(lst.first - prex));
			gap.erase(gap.find(nxtx - lst.first));
			gap.insert(nxtx - prex);
			s.erase(lst);
		}

		if (nw < *s.begin()) {
			int len = (s.begin() -> first) - nw.first;
			sum += len; gap.insert(len); s.insert(nw);
		} else if (nw > *--s.end()) {
			int len = nw.first - ((--s.end()) -> first);
			sum += len; gap.insert(len); s.insert(nw);
		} else {
			s.insert(nw);
			auto [prex, pre] = *--s.find(nw);
			auto [nxtx, nxt] = *++s.find(nw);
			gap.insert(nw.first - prex);
			gap.insert(nxtx - nw.first);
			gap.erase(gap.find(nxtx - prex));
		}
	};
	int q = rd();
	rep(i, 1, q) {
		int p = rd(), x = rd();
		if (n == 1) {printf("%d ", x); continue;}
		modify(p, x);
		printf("%lld ", (s.begin() -> first) + sum + (*--gap.end()));
	}
	puts("");
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}