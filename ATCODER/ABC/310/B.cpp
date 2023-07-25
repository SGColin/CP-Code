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

#define N 110

map<int, bool> vis[N];

int p[N];

int main() {
	int n = rd(), m = rd();
	for (int i = 1; i <= n; ++i) {
		p[i] = rd();
		int tot = rd();
		for (int j = 1; j <= tot; ++j) vis[i][rd()] = true;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j) {
				if (p[i] < p[j]) continue;
				bool fl = true;
				for (auto [x, y] : vis[i])
					if (y && vis[j][x] != true) fl = false;
				if (!fl) continue;
				if (p[i] > p[j]) {puts("Yes"); return 0;}
				fl = false;
				for (auto [x, y] : vis[j])
					if (y && vis[i][x] != true) fl = true;
				if (fl) {puts("Yes"); return 0;}
			}
	puts("No");
	return 0;
}