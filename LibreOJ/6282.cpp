#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline char rdc(){
	static char buf[1 << 16], *l = buf, *r = buf;
	return l == r && (r = (l = buf) + fread(buf, 1, 1 << 16, stdin), l == r) ? EOF : *l++;
}

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = rdc();
	for (; !isdigit(c); c = rdc()) f |= (c == '-');
	for (; isdigit(c); c = rdc()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define pb push_back
#define eb emplace_back

vector<int> s, _s;

vector<pii> tmp;

int main() {
	int n = rd();
	int lim = sqrt(n);
	rep(i, 1, n) s.pb(rd());

	auto kth = [&](int k) {
		int cnt = 0;
		for (auto [pos, w] : tmp) {
			if (pos == k) return w;
			if (pos < k) ++cnt;
		}
		return s[k - cnt - 1];
	};

	auto rebuild = [&]() {
		int cnt = 1, ptr = 0;
		swap(s, _s); s.clear();
		sort(tmp.begin(), tmp.end());
		for (auto [pos, w] : tmp) {
			for (; cnt < pos; ++cnt) s.pb(_s[ptr++]);
			s.pb(w); ++cnt;
		}
		while (ptr < _s.size()) s.pb(_s[ptr++]);
		tmp.clear();
	};

	rep(i, 1, n) {
		int op = rd(), l = rd(), r = rd(), c = rd();
		if (op) printf("%d\n", kth(r));
		else {
			for (auto &[pos, w] : tmp) if (pos >= l) ++pos;
			tmp.eb(l, r);
			if (tmp.size() >= lim) rebuild();
		}
	}
	return 0;
}