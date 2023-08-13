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

#define N 5001

bool vis[N];

vector<int> s;

int main() {
	int n = rd(), m = rd();
	for (int i = 1; i <= m; ++i) {
		rd(); vis[rd()] = true;
	}
	for (int i = 1; i <= n; ++i) if (!vis[i]) s.push_back(i);
	if (s.size() != 1) puts("-1");
	else printf("%d", s[0]);
	return 0;
}