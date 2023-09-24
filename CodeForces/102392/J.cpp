#include <bits/stdc++.h>
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

#define N 1001
#define pb push_back

vector<int> s[N];

int main() {
	int n = rd();
	int m = n * (n - 1) / 2;
	for (int i = 1; i <= m; ++i) {
		int u = rd(), v = rd(), w = rd();
		s[u].push_back(w);
		s[v].push_back(w);
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		sort(s[i].begin(), s[i].end());
		for (int j = 1; j < n - 1; j += 2) ans += s[i][j]; 
	}
	printf("%lld\n", ans);
	return 0;
}