#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 200007
#define mod 1000000007

int n, m, a[N], lc[N], rc[N];

vector<int> s, dp[N];

void dfs(int u) {
	if (lc[u]) dfs(lc[u]);
	if (rc[u]) dfs(rc[u]);
	rep(i, 1, m) 
		dp[u][i] = (dp[u][i - 1] + 1ll * dp[lc[u]][i - 1] * dp[rc[u]][i]) % mod;
}

inline void work() {
	cin >> n >> m;
	dp[0].resize(m + 1, 1);
	rep(i, 1, n) {
		cin >> a[i]; 
		dp[i].resize(m + 1, 0);
		lc[i] = rc[i] = 0;
		while (!s.empty() && a[i] > a[s.back()]) {lc[i] = s.back(); s.pop_back();}
		if (!s.empty()) rc[s.back()] = i;
		s.push_back(i);
	}
	dfs(s.front());
	printf("%d\n", dp[s.front()][m]);
	while (!s.empty()) s.pop_back();
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) work();
	return 0;
}