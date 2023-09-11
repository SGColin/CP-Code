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

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 1007
#define mp make_pair
#define eb emplace_back
#define lb lower_bound
#define all(s) (s).begin(), (s).end()

int a[N], pos[N];

vector<pii> s;

int main() {
	int n = rd();
	rep(i, 1, n) s.eb(a[i] = rd(), i);
	sort(all(s));
	s.erase(unique(all(s)), s.end());
	rep(i, 1, n) pos[a[i] = lb(all(s), mp(a[i], i)) - s.begin() + 1] = i;

	s.clear();
	auto work = [&](int pa, int pb) {
		s.eb(pa, pb);
		swap(a[pa], a[pb]);
		swap(pos[a[pa]], pos[a[pb]]);
	};
	rep(i, 1, n) for (int v = a[i]; v != i; --v) work(i, pos[v - 1]);
	printf("%d\n", (int) s.size());
	for (auto [pa, pb] : s) printf("%d %d\n", pa, pb);
	return 0;
}