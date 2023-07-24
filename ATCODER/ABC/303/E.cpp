#include <bits/stdc++.h>
using namespace std;

#define N 200007

vector<int> e[N], ans;

int d[N];

bool vis[N];

int dfs(int u) {
    vis[u] = true;
    for (auto v : e[u])
        if (!vis[v]) return dfs(v) + 1;
    return 1;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i < n; ++i) {
        int u, v; cin >> u >> v;
        ++d[u]; ++d[v]; 
        e[u].push_back(v); e[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (d[i] > 2) {
            vis[i] = true;
            ans.push_back(e[i].size());
            for (auto u : e[i]) {
                vis[u] = true;
                for (auto v : e[u]) --d[v];
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        if (d[i] == 1 && !vis[i]) 
            for (int j = dfs(i) / 3; j; --j) ans.push_back(2);
    sort(ans.begin(), ans.end());
    for (auto x : ans) printf("%d ", x);
  	return 0;
}