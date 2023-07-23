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

#define N 207

int vis[N][N];

bool mp[N][N];

void dfs(int x, int y) {
    vis[x][y] = 2;
    // up
    int tx = x, ty = y;
    while (mp[tx][ty - 1]) {
        vis[tx][ty - 1] = max(vis[tx][ty - 1], 1);
        --ty;
    }
    if (vis[tx][ty] != 2) dfs(tx, ty);
    // dn
    tx = x, ty = y;
    while (mp[tx][ty + 1]) {
        vis[tx][ty + 1] = max(vis[tx][ty + 1], 1);
        ++ty;
    }
    if (vis[tx][ty] != 2) dfs(tx, ty);
    // left 
    tx = x, ty = y;
    while (mp[tx - 1][ty]) {
        vis[tx - 1][ty] = max(vis[tx - 1][ty], 1);
        --tx;
    }
    if (vis[tx][ty] != 2) dfs(tx, ty);
    // right 
    tx = x, ty = y;
    while (mp[tx + 1][ty]) {
        vis[tx + 1][ty] = max(vis[tx + 1][ty], 1);
        ++tx;
    }
    if (vis[tx][ty] != 2) dfs(tx, ty);
}

int main() {
    int n = rd(), m = rd();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c = getchar();
            while (c != '.' && c != '#') c = getchar();
            mp[i][j] = (c == '.');
        }
    }
    dfs(2, 2);
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            ans += (vis[i][j] > 0);
        }
    printf("%d\n", ans);
    return 0;
}