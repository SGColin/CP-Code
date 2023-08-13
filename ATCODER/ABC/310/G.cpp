#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll rd() {
	ll x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 200007
#define mod 998244353
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

inline int SUM(int a, int b) {return a + b >= mod ? a + b - mod : a + b;}
inline int PROD(int a, int b) {return 1ll * a * b % mod;}

inline int fpow(int x, int t = mod - 2) {
	int res = 1;
	for (; t; t >>= 1, x = 1ll * x * x % mod)
		if (t & 1) res = 1ll * res * x % mod;
	return res;
}

int a[N], b[N], tmp[N], ans[N];

int main() {
	int n = rd();
	ll k = rd();
	int inv = fpow(k % mod);
	rep(i, 1, n) a[i] = rd();
	rep(i, 1, n) b[i] = rd();
	
	// pass for the first time
	rep(i, 1, n) tmp[i] = 0;
	rep(i, 1, n) tmp[a[i]] = SUM(tmp[a[i]], b[i]);
	rep(i, 1, n) b[i] = tmp[i];

	for (; k; k >>= 1) {
		if (k & 1) {
			rep(i, 1, n) ans[i] = SUM(ans[i], b[i]);
			// pass to gap the first time
			rep(i, 1, n) tmp[i] = 0;
			rep(i, 1, n) tmp[a[i]] = SUM(tmp[a[i]], b[i]);
			rep(i, 1, n) b[i] = tmp[i];
		}
		// doubling
		rep(i, 1, n) tmp[i] = 0;
		rep(i, 1, n) tmp[a[i]] = SUM(tmp[a[i]], b[i]);
		rep(i, 1, n) b[i] = SUM(b[i], tmp[i]);
		
		rep(i, 1, n) tmp[i] = a[a[i]];
		rep(i, 1, n) a[i] = tmp[i];
	}
	for (int i = 1; i <= n; ++i) printf("%d ", PROD(ans[i], inv));
	return 0;
}

// we can also using difference and prefix sum on chains and circles to solve this problem 
/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

inline ll rd() {
	ll x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define fr first
#define sc second
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(s) s.begin(), s.end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007
#define mod 998244353

vector<int> e[N], ids[N], order;

int n, a[N], len[N], bel[N], cid[N], add[N], ccnt;

ll b[N], k;

int vis[N], deg[N], dep[N], top[N], f[N][19], cadd[N];

queue<int> q;

void dfs(int u) {
	vis[u] = 2; ++len[u]; 
	bel[u] = ccnt; cid[u] = len[u]; ids[ccnt].pb(u);
	if (!vis[a[u]]) {len[a[u]] = len[u]; dfs(a[u]); len[u] = len[a[u]];}
}

void dfs2(int u, int t, int d) {
	dep[u] = d; top[u] = t;
	for (auto v : e[u]) dfs2(v, t, d + 1);
}

int fpow(int x, int t) {
	int res = 1;
	for (; t; t >>= 1, x = 1ll * x * x % mod)
		if (t & 1) res = 1ll * res * x % mod;
	return res;
} 

int main() {
	n = rd(); k = rd();
	rep(i, 1, n) {e[a[i] = rd()].pb(i); ++deg[a[i]];}
	rep(i, 1, n) b[i] = rd();
	rep(i, 1, n) if (!deg[i]) q.push(i);	
	while (!q.empty()) {
		int u = q.front(); q.pop(); order.pb(u);
		vis[u] = 1; --deg[a[u]]; if (!deg[a[u]]) q.push(a[u]);
	}
	rep(i, 1, n) {
		if (!vis[i]) {++ccnt; vis[i] = 2; dfs(i);}
		if (vis[i] == 2) {
			for (auto v : e[i])
				if (vis[v] != 2) dfs2(v, v, 0);
		}
	}
	rep(i, 1, n) f[i][0] = a[i];
	rep(i, 1, 18)
		rep(u, 1, n) f[u][i] = f[f[u][i - 1]][i - 1];
	auto anc = [&](int u, int k) {
		per(i, 18, 0)
			if (k & (1 << i)) u = f[u][i];
		return u;
	};
	auto addcirc = [&](int st, ll times, int num) {
		cadd[bel[st]] = (cadd[bel[st]] + (times / len[st]) % mod * num) % mod;
		times %= len[st];
		if (times == 0) return;
		add[st] = (add[st] + num) % mod;
		if (cid[st] + times <= len[st]) {
			int deltar = ids[bel[st]][cid[st] + times - 1];
			add[deltar] = (add[deltar] + mod - num) % mod;
		} else {
			int bg = ids[bel[st]][0];
			add[bg] = (add[bg] + num) % mod;
			int deltar = ids[bel[st]][times - (len[st] - cid[st] + 1)];
			add[deltar] = (add[deltar] + mod - num) % mod;
		}
	};
	rep(i, 1, n) {
		if (vis[i] == 1) {
			if (k >= dep[i]) {
				// contribution on chains
				if (vis[a[i]] != 2) {
					add[a[i]] = (add[a[i]] + b[i]) % mod;
				}
				// contribution on circle
				addcirc(a[top[i]], k - dep[i], b[i]);
			} else {
				// only contribution on chains
				add[a[i]] = (add[a[i]] + b[i]) % mod;
				int taranc = anc(i, (int)k + 1);
				add[taranc] = (add[taranc] + mod - b[i]) % mod;
			}
		} else {
			addcirc(a[i], k, b[i]);
		}
	}
	//addchain
	for (auto x : order)
		if (vis[a[x]] == 1) add[a[x]] = (add[a[x]] + add[x]) % mod;
	//adcirc
	for (int i = 1; i <= ccnt; ++i)
		for (auto x : ids[i]) {
			if (cid[x] < cid[a[x]]) add[a[x]] = (add[a[x]] + add[x]) % mod; 
			add[x] = (add[x] + cadd[i]) % mod;
		}
	ll invk = fpow(k % mod, mod - 2);
	rep(i, 1, n) printf("%lld ", invk * add[i] % mod);
	return 0;
}
*/