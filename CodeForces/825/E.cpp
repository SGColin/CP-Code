#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 100007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

vector<int> e[N];

int deg[N], lab[N];

priority_queue<int> q;


int main() {
	int n = rd(), m = rd();
	rep(i, 1, m) {
		int v = rd(), u = rd();
		e[u].push_back(v); ++deg[v];
	}
	
	int tot = n;
	rep(i, 1, n) if (!deg[i]) q.push(i);
	while (!q.empty()) {
		int u = q.top(); q.pop();
		lab[u] = tot--;
		for (auto v : e[u]) {
			--deg[v];
			if (!deg[v]) q.push(v);
		}
	}
	rep(i, 1, n) printf("%d ", lab[i]);
	return 0;
}