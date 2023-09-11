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

vector<pii> S;

int a[4][4], b[4][4];

int main() {
	rep(i, 1, 3) rep(j, 1, 3) {a[i][j] = rd(); S.eb(i, j);}
	int cnt = 0, cor = 0;
	auto test = [&]() {
		vector<pii> s;
		rep(i, 1, 3) {
			s.clear();
			rep(j, 1, 3) s.eb(b[i][j], a[i][j]);
			sort(all(s));
			if (s[0].sc == s[1].sc) return true;
		}
		rep(j, 1, 3) {
			s.clear();
			rep(i, 1, 3) s.eb(b[i][j], a[i][j]);
			sort(all(s));
			if (s[0].sc == s[1].sc) return true;
		}
		s.clear(); 
		rep(i, 1, 3) s.eb(b[i][i], a[i][i]);
		sort(all(s));
		if (s[0].sc == s[1].sc) return true;

		s.clear(); 
		rep(i, 1, 3) s.eb(b[4 - i][i], a[4 - i][i]);
		sort(all(s));
		if (s[0].sc == s[1].sc) return true;
		return false;
	};
	do {
		++cnt; ++cor;
		int tot = 0;
		for (auto [x, y] : S) b[x][y] = ++tot;
		cor -= test();
	} while (next_permutation(all(S)));
	printf("%.10lf\n", 1.0 * cor / cnt);
	return 0;
}