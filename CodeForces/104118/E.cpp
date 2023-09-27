#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef tuple<int, int, int> tiii;

inline ll rd() {
	ll x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 200007
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int st[N], ed[N];

map<pii, int> id;

vector<int> s[N];

vector<pii> e[N], fb[N];

bool vis[N];

ll dis[N];

priority_queue<pli, vector<pli>, greater<pli>> q;

int main() {
	int n = rd(), m = rd(), p = rd(), l = rd();
	rep(i, 1, m) {
		int u = rd(), v = rd();
		e[u].eb(v, i); e[v].eb(u, i);
		id[mp(u, v)] = id[mp(v, u)] = i;
		st[i] = ed[i] = -1e9;
	}
	rep(i, 1, p) rep(j, 1, l) s[i].pb(rd());
	rep(j, 0, l - 1) {
		rep(i, 1, p) {
			int nw = s[i][j], nxt = (j == l - 1 ? s[i][0] : s[i][j + 1]);
			int eid = id[mp(nw, nxt)];
			if (ed[eid] < j - 1) {
				if (ed[eid] >= 0) fb[eid].eb(ed[eid], st[eid]); 
				st[eid] = j;
			}
			ed[eid] = j;
		}
	}
	rep(i, 1, m) if (ed[i] >= 0) fb[i].eb(ed[i], st[i]);
	int s = rd(), t = rd();
	memset(dis, 0x3f, sizeof(dis));
	ll inf = dis[0];
	dis[s] = 0; q.push(mp(0, s));
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (vis[u]) continue; vis[u] = true;
		for (auto [v, eid] : e[u]) {
			if (!fb[eid].empty() && fb[eid][0] == mp(l - 1, 0)) continue;
			int nw = dis[u] % l;
			auto it = lower_bound(all(fb[eid]), mp(nw, 0));
			if (it == fb[eid].end() || it -> second > nw) {
				if (dis[v] > dis[u] + 1) {dis[v] = dis[u] + 1; q.push(mp(dis[v], v));}
			} else {
				int add = 0;
				if (it -> first != l - 1 || fb[eid][0].second > 0) add = (it -> first) - nw + 2;	 
				else add = fb[eid][0].first + l - nw + 1;
				if (dis[v] > dis[u] + add) {dis[v] = dis[u] + add; q.push(mp(dis[v], v));}
			}
		}
	}
	if (dis[t] == inf) puts("IMPOSSIBLE");
	else printf("%lld\n", dis[t]);
	return 0;
}