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

#define N 17
#define mp make_pair
#define eb emplace_back
#define lb lower_bound
#define all(s) (s).begin(), (s).end()

bool vis[N];

int ans = 0;

vector<pii> e[N];

void dfs(int u, int d) {
	ans = max(ans, d);
	for (auto [v, w] : e[u]) 
		if (!vis[v]) {
			vis[v] = true;
			dfs(v, d + w);
			vis[v] = false;
		}
}

int main() {
	int n = rd(), m = rd();
	rep(i, 1, m) {
		int u = rd(), v = rd(), w = rd();
		e[u].eb(v, w); e[v].eb(u, w);
	}
	rep(i, 1, n) {
		vis[i] = true;
		dfs(i, 0);
		vis[i] = false;
	}
	printf("%d\n", ans);
	return 0;
}