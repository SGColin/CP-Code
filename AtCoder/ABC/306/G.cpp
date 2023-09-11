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

int gcd(int a, int b) {return b ? gcd(b, a % b) : a;}

#define N 200007

vector<int> e[N], re[N];

int dis[N];

bool vis[N];

void dfs(int u) {
	for (auto v : e[u])
		if (dis[v] == -1) {
			dis[v] = dis[u] + 1;
			dfs(v);
		}
}

void rdfs(int u) {
	vis[u] = true;
	for (auto v : re[u]) 
		if (!vis[v]) rdfs(v);
}

inline void work() {
	int n = rd(), m = rd(), ans = 0;
	for (int i = 1; i <= n; ++i) {
		dis[i] = -1;
		vis[i] = false;
		e[i].clear();
		re[i].clear();
	}
	for (int i = 1; i <= m; ++i) {
		int u = rd(), v = rd();
		e[u].push_back(v); 
		re[v].push_back(u);
	}
	dis[1] = 0; dfs(1); rdfs(1);
	for (int i = 1; i <= n; ++i) 
		if (!vis[i]) dis[i] = -1;
	for (int u = 1; u <= n; ++u)
		if (~dis[u]) for (auto v : e[u])
			if (~dis[v]) ans = gcd(ans, abs(dis[u] + 1 - dis[v]));
	if (ans == 0) {puts("No"); return;}
	while (ans % 2 == 0) ans /= 2;
	while (ans % 5 == 0) ans /= 5;
	puts(ans == 1 ? "Yes" : "No");
}

int main() {
	for (int t = rd(); t; --t) work();
	return 0;
}