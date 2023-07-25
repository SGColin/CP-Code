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

typedef vector<set<int>> Alo;

map<int, bool> f[11];

int n, t, m;

Alo s;

map<Alo, bool> vis[12];

void dfs(int nw) {
	if (nw == n + 1) {
		for (auto x : s) 
			if (x.empty()) return;
		vis[nw][s] = true;
		return;		
	}
	if (vis[nw][s]) return;
	vis[nw][s] = true;
	for (int i = 0; i < t; ++i) {
		bool fl = false;
		if (s[i].empty()) {
			s[i].insert(nw);
			dfs(nw + 1);
			s[i].erase(nw);
			break;
		}
		for (auto x : s[i])
			if (f[x][nw]) {fl = true; break;}
		if (fl) continue;
		s[i].insert(nw);
		dfs(nw + 1);
		s[i].erase(nw);
	}
}

int main() {
	n = rd(); t = rd(); m = rd();
	s.resize(t);
	for (int i = 1; i <= m; ++i) {
		int a = rd(), b = rd();
		f[a][b] = f[b][a] = true;
	}
	dfs(1);
	printf("%d\n", (int)vis[n + 1].size());
	return 0;
}