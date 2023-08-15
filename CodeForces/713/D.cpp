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

#define N 1007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

int lg[N] = {-1}, f[N][N], mx[10][10][N][N];

int main() {
	int n = rd(), m = rd(); 
	rep(i, 1, max(n, m)) lg[i] = lg[i >> 1] + 1;
	rep(i, 1, n) rep(j, 1, m) {
		f[i][j] = rd();
		if (f[i][j]) f[i][j] = min({f[i - 1][j], f[i][j - 1], f[i - 1][j - 1]}) + 1;
	}
	rep(i, 0, lg[n]) 
		rep(j, 0, lg[m]) 
			rep(x, 1, n - (1 << i) + 1)
				rep(y, 1, m - (1 << j) + 1) {
					if (i == 0 && j == 0) mx[i][j][x][y] = f[x][y]; 
					else if (i == 0) mx[i][j][x][y] = max(mx[i][j - 1][x][y], mx[i][j - 1][x][y + (1 << j - 1)]);
					else if (j == 0) mx[i][j][x][y] = max(mx[i - 1][j][x][y], mx[i - 1][j][x + (1 << i - 1)][y]);
					else mx[i][j][x][y] = max({mx[i - 1][j - 1][x][y], mx[i - 1][j - 1][x + (1 << i - 1)][y],
							mx[i - 1][j - 1][x][y + (1 << j - 1)], mx[i - 1][j - 1][x + (1 << i - 1)][y + (1 << j - 1)]});
				}
				
	auto qmx = [&](int x1, int y1, int x2, int y2) {
		int kx = lg[x2 - x1 + 1], ky = lg[y2 - y1 + 1];
		return max({mx[kx][ky][x1][y1], mx[kx][ky][x2 - (1 << kx) + 1][y1], 
		 			mx[kx][ky][x1][y2 - (1 << ky) + 1], mx[kx][ky][x2 - (1 << kx) + 1][y2 - (1 << ky) + 1]});
	};
	int q = rd();
	rep(i, 1, q) {
		int x1 = rd(), y1 = rd(), x2 = rd(), y2 = rd();
		int l = 0, r = min(x2 - x1 + 1, y2 - y1 + 1);
		while (l < r) {
			int mid = (l + r + 1) / 2;
			qmx(x1 + mid - 1, y1 + mid - 1, x2, y2) >= mid ? l = mid : r = mid - 1;
		}
		printf("%d\n", l);
	}
	return 0;
}
