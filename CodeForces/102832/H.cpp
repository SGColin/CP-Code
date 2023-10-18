#include <bits/stdc++.h>
using namespace std;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

inline void getmin(int &a, int b) {a = (a < b ? a : b);}

template <const int V, const int inf = 1000000000>
struct BG { // index from 1 !!!
    bool vis[V];
    vector<int> e[V];
    int nl, nr, ml[V], mr[V], dl[V], dr[V]; // m for match, d for distance
    void init(int _nl, int _nr) {
        nl = _nl; nr = _nr;
        memset(ml, 0, sizeof(ml));
        memset(mr, 0, sizeof(mr));
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < V; ++i) e[i].clear();
    }
    inline bool bfs() {
        static int q[V], hd, tl, dT; 
        hd = 1; tl = 0; dT = inf;
        memset(dl, -1, sizeof(int) * (nl + 1)); 
        memset(dr, -1, sizeof(int) * (nr + 1));
        for (int i = 1; i <= nl; ++i) if (!ml[i]) {dl[i] = 0; q[++tl] = i;}
        for (int u; hd <= tl;) {
            if (dl[u = q[hd++]] >= dT) break;
            for (auto v : e[u])
                if (dr[v] == -1) {
                    dr[v] = dl[u] + 1;
                    if (!mr[v]) getmin(dT, dr[v] + 1);
                    else {dl[mr[v]] = dr[v] + 1; q[++tl] = mr[v];}
                }
        }
        return dT != inf;
    }
    bool dfs(int u) {
        for (auto v : e[u]) {
            if (vis[v] || dl[u] + 1 != dr[v]) continue;
            vis[v] = true;
            if (!mr[v] || dfs(mr[v])) {mr[v] = u; ml[u] = v; return true;}
        }
        return false;
    }
    inline void add(int u, int v) {e[u + 1].push_back(v + 1);}
    inline int max_matching() {
        int ans = 0;
        while(bfs()) {
            memset(vis, 0, sizeof(bool) * (nr + 1));
            for (int i = 1; i <= nl; ++i) if (!ml[i]) ans += dfs(i);
        }
        return ans;
    }
};

#define N 100007

BG<N> g;

bool vis[N];

inline void work() {
    memset(vis, 0, sizeof(vis));
    int m = rd(), k = rd(), st = rd(), n = 1;
    rep(i, 1, k) vis[rd()] = true;
    rep(i, 1, m) n = n * 10; --n;
    g.init(n + 1, n + 1);
    rep(nw, 0, n) if (!vis[nw]) {
        vector<int> a;
        int tmp = nw, sum = 0;
        rep(i, 1, m) {sum += tmp % 10; a.pb(tmp % 10); tmp /= 10;}
        if (sum & 1) continue;
        auto calc = [&](){int w = 0; per(i, m - 1, 0) w = w * 10 + a[i]; return w;};
        rep(i, 0, m - 1) {
            int x = a[i];
            a[i] = (x + 1) % 10;
            int w = calc(); if (!vis[w]) g.add(nw, w);
            a[i] = (x + 9) % 10;
            w = calc(); if (!vis[w]) g.add(nw, w);
            a[i] = x;
        }
    }
    int ans = g.max_matching();
    g.init(n + 1, n + 1); vis[st] = true;
    rep(nw, 0, n) if (!vis[nw]) {
        vector<int> a;
        int tmp = nw, sum = 0;
        rep(i, 1, m) {sum += tmp % 10; a.pb(tmp % 10); tmp /= 10;}
        if (sum & 1) continue;
        auto calc = [&](){int w = 0; per(i, m - 1, 0) w = w * 10 + a[i]; return w;};
        rep(i, 0, m - 1) {
            int x = a[i];
            a[i] = (x + 1) % 10;
            int w = calc(); if (!vis[w]) g.add(nw, w);
            a[i] = (x + 9) % 10;
            w = calc(); if (!vis[w]) g.add(nw, w);
            a[i] = x;
        }
    }
    puts(g.max_matching() == ans ? "Bob" : "Alice");

}

int main() {
    int t = rd();
    while (t--) work();
    return 0;
}