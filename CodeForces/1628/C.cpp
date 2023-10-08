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

#define N 1007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

bool vis[N][N];

inline void work() {
	int n = rd(), ans = 0;
	rep(i, 1, n) rep(j, 1, n) vis[i][j] = 0;
	rep(i, 1, n) rep(j, 1, n) {
		int w = rd();
		if (i > 1 && !vis[i - 1][j]) {
			ans ^= w;
			vis[i][j - 1] ^= 1;
			vis[i][j + 1] ^= 1;
			vis[i - 1][j] ^= 1;
			vis[i + 1][j] ^= 1;
		}
	}
	printf("%d\n", ans);
}

int main() {
	int t = rd();
	while (t--) work();
	return 0;
}