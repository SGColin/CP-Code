#include <bits/stdc++.h>
using namespace std;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 107
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

char s[N][N];

int main() {
	int n = rd(), m = rd();
	vector<int> x, y;
	vector<pair<int, int>> pos;
	rep(i, 1, n) {
		scanf("%s", s[i] + 1);
		rep(j, 1, m) 
			if (s[i][j] == '#') {
				x.push_back(i);
				y.push_back(j);
				pos.emplace_back(i, j);
			}
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	int X = x[1], Y = y[1];
	for (auto [sx, sy] : pos) {
		while (sy > Y) {--sy; s[sx][sy] = '#';}
		while (sy < Y) {++sy; s[sx][sy] = '#';}
		while (sx > X) {--sx; s[sx][sy] = '#';}
		while (sx < X) {++sx; s[sx][sy] = '#';}
	}
	rep(i, 1, n) puts(s[i] + 1);
	return 0;
}