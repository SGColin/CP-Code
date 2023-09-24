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

#define N 100007
#define pb push_back

vector<int> e[N];

int rem[N];

void dfs(int u, int fa) {
	for (auto v : e[u]) 
		if (v != fa) {dfs(v, u); rem[u] += rem[v];}
	if (rem[u]) --rem[u];
	else ++rem[u];
}

int main() {
	int n = rd();
	for (int i = 1; i < n; ++i) {
		int u = rd(), v = rd();
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1, 1);
	puts(rem[1] == 0 ? "Bob" : "Alice");
	return 0;
}