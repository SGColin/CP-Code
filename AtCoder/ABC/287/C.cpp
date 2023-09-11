#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define T int 
typedef pair<T, T> pii;
typedef tuple<T, T, T> tii;

#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define lowbit(x)    ((x) & -(x))
#define all(x)       (x).begin(), (x).end()
#define rep(i, x, y) for (int i = (x); i <= (y); ++i)
#define per(i, x, y) for (int i = (x); i >= (y); --i)

inline T rd() {
    T x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define N 200007

vector<int> e[N];

bool vis[N];

inline void dfs(int u) {
    vis[u] = true;
    for (auto v : e[u])
        if (!vis[v]) {dfs(v); return;}
}

int main() {
    int n = rd(), m = rd();
    if (n != m + 1) {puts("No"); return 0;}
    for (int i = 1; i <= m; ++i) {
        int u = rd(), v = rd();
        e[u].pb(v); e[v].pb(u);
    }
    int s;
    for (int u = 1; u <= n; ++u)
        if (e[u].empty() || e[u].size() > 2) {puts("No"); return 0;}
        else if (e[u].size() == 1) s = u;
    dfs(s);
    for (int i = 1; i <= n; ++i)
        if (!vis[i]) {puts("No"); return 0;}
    puts("Yes");
    return 0;
}