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

#define N 200007
#define mod 998244353

inline int mo(int x) {return x >= mod ? x - mod : x;}

set<int> e[N], s;

vector<int> a[N];

int d[N], cnt[N];

queue<int> q;

int main() {
	int n = rd(), m = rd();
	rep(i, 1, n) {d[i] = -1; s.insert(i);}
	rep(i, 1, m) {
		int u = rd(), v = rd();
		e[u].insert(v); e[v].insert(u);
	}
	a[d[1] = 0].pb(1); 
	s.erase(1); q.push(1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto it = s.begin(); it != s.end(); ){
			int v = *it; it++;
			if (e[u].find(v) == e[u].end()) {
				a[d[v] = d[u] + 1].push_back(v); 
				q.push(v); s.erase(v);
			}
		} 
	}
	if (d[n] == -1) {puts("-1"); return 0;}
	int sum = 1;
	rep(i, 0, n) {
		for (auto u : a[i]) cnt[u] = mo(cnt[u] + sum);
		sum = 0; 
		for(auto u : a[i]) {
			sum = mo(sum + cnt[u]);
			for (auto v : e[u]) 
				if (d[v] == d[u] + 1) cnt[v] = mo(cnt[v] + mod - cnt[u]);
		}
	}
	printf("%d\n", cnt[n]);
	return 0;
}