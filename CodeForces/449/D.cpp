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

#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 1048576
#define mod 1000000007

int f[N], pw[N] = {1}, cnt[N];

inline int mo(int x) {return x >= mod ? x - mod : x;}

int main() {
	int n = rd();
	rep(i, 1, n) ++f[rd()];
	rep(i, 1, N - 1) pw[i] = mo(pw[i - 1] << 1);
	rep(i, 0, 19) 
		rep(s, 0, N - 1) 
			if ((s & (1 << i)) == 0) 
				f[s] = mo(f[s] + f[s ^ (1 << i)]);
	int ans = 0;
	rep(s, 0, N - 1) {
		cnt[s] = cnt[s >> 1] + (s & 1);
		int w = mo(pw[f[s]] + mod - 1);
		if (cnt[s] & 1) w = mo(mod - w);
		ans = mo(ans + w);
	}
	printf("%d\n", ans);
	return 0;
}