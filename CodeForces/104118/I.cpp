#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 200007
#define pb push_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int need[N][10], raw, hav[10], tmp[10], op[N];

vector<int> s[N];

int main() {
	int n = rd(), m = rd();
	rep(i, 1, m) {
		op[i] = rd();
		if (!op[i]) {
			hav[raw] = rd();
			need[i][raw] = 1;
			++raw;
		} else rep(j, 1, op[i]) s[i].pb(rd());
	}	
	per(i, m, 1) 
		if (op[i]) {
			for (auto x : s[i])
				rep(j, 0, raw - 1) 
					need[i][j] = min(need[i][j] + need[x][j], 100000001);
		}
	int ans = 0;
	per(s, (1 << n) - 1, 0) {
		rep(i, 0, raw - 1) tmp[i] = 0;
		rep(i, 0, n - 1)
			if (s & (1 << i))
				rep(j, 0, raw - 1) 
					tmp[j] = min(tmp[j] + need[i + 1][j], 100000001);
		bool fl = true;
		rep(i, 0, raw - 1) if (tmp[i] > hav[i]) fl = false;
		if (fl) ans = max(ans, (int)__builtin_popcount(s));
	}
	printf("%d\n", ans);
	return 0;
}