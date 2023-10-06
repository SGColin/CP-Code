#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

inline int rd(){
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 7301

bool wall[21][361], circ[21][361];

int f[N], id[21][361], tot, out;

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}

inline void merge(int u, int v) {f[find(u)] = find(v);}

inline void work() {
	rep(i, 1, N - 1) f[i] = i;
	memset(wall, 0, sizeof(wall));
	memset(circ, 0, sizeof(circ));
	#define nxt(x) (x == 359 ? 0 : x + 1)
	int n = rd();
	rep(i, 1, n) {
		char c = getchar();
		while (!isalpha(c)) c = getchar();
		if (c == 'C') {
			int r = rd(), t1 = rd(), t2 = rd();
			for (; t1 != t2; t1 = nxt(t1)) circ[r][t1] = true; 
		} else {
			int r1 = rd(), r2 = rd(), t = rd();
			rep(i, r1 + 1, r2) wall[i][t] = true;
		}
	}
	rep(r, 1, 20)
		rep(t, 0, 359) {
			if (!wall[r][nxt(t)]) merge(id[r][t], id[r][nxt(t)]);
			if (!circ[r][t]) merge(id[r][t], (r == 20 ? out : id[r + 1][t])); 
		}
	puts(find(out) == find(id[1][0]) ? "YES" : "NO");
}

int main() {
	rep(r, 1, 20) rep(t, 0, 359) id[r][t] = ++tot; out = ++tot;
	per(t, rd(), 1) work();
	return 0;
}