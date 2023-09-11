//新卡一瓶药如果是1的话，要等于号也允许否则就寄了 会自动忽略
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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 501

vector<int> son[N], id;

int n, fa[N], t[N], a[N], b[N];

const int inf = 1000000000;

struct sta {
	ll pw;
	bool vis[N];
	sta() {pw = 1; memset(vis, 0, sizeof(vis)); vis[1] = true;}
	void add(int p) {
		vis[p] = true;
		pw = pw * b[p];
		if (pw > inf) pw = inf;
	}
	void extend() {
		set<pii> s; s.clear();
		rep(u, 1, n) 
			if (vis[u]) for (auto v : son[u]) 
				if (!vis[v] && t[v] == 1) s.insert(mp(a[v], v));
		while (!s.empty() && pw >= s.begin() -> fr) {
			int cur = s.begin() -> sc; s.erase(s.begin());
			pw += b[cur]; 
			if (pw > inf) pw = inf;
			vis[cur] = true;
			for (auto v : son[cur])
				if (!vis[v] && t[v] == 1) s.insert(mp(a[v], v));
		}
	}
	inline bool operator > (const sta &obj) {
		if (pw != obj.pw) return pw > obj.pw;
		rep(i, 1, n) if (vis[i] != obj.vis[i]) return vis[i] > obj.vis[i];
		return true;
	}
} f[1024];

int main() {
	n = rd();
	rep(i, 2, n) {
		son[fa[i] = rd()].pb(i); 
		t[i] = rd(); a[i] = rd(); b[i] = rd();
		if (t[i] == 2) id.pb(i);
	}
	int k = id.size() - 1;
	int S = (1 << id.size()) - 1;
	f[0].extend();
	rep(s, 0, S) {
		rep(i, 0, k) 
			if ((s & (1 << i)) == 0 && f[s].vis[fa[id[i]]]) {
				sta tmp = f[s];
				tmp.add(id[i]);
				tmp.extend();
				if (tmp > f[s | (1 << i)]) f[s | (1 << i)] = tmp;
			}
	}
	// or make decision like this : puts(f[S].pw >= mx ? "Yes" : "No");
	rep(i, 1, n) if (f[S].vis[i] == false) {puts("No"); return 0;}
	puts("Yes");
	return 0;
}