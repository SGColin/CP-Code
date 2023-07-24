#include <bits/stdc++.h>
using namespace std;

#define N 57

bool vis[N][N];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int lst = 0;
        for (int j = 1; j <= n; ++j) {
            int nw; cin >> nw;
            vis[lst][nw] = vis[nw][lst] = true;
            lst = nw;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j) ans += 1 - vis[i][j];
    printf("%d\n", ans);
  	return 0;
}