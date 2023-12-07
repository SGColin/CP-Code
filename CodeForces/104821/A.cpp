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

#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

const int N = 1007;

map<pii, int> id;

char a[N][N];

bool vis[N][N], ok[N];

int sz[N];

queue<pii> q;

bitset<4 * N> S[N];

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

inline void work() {
    id.clear();
    int n = rd(), m = rd(), tot = 0;
    rep(i, 1 - n, n - 1)
        rep(j, 1 - m, m - 1) id[{i, j}] = tot++;
    rep(i, 1, n) rep(j, 1, m) {
        char c = getchar();
        while (c != '.' && c != 'O') c = getchar();
        a[i][j] = c;
    }
    int totid = 0;
    auto valid = [&](int x, int y) {
        if (x < 1 || y < 1 || x > n || y > m) return false;
        if (vis[x][y] || a[x][y] == 'O') return false;
        return true;
    };
    auto bfs = [&](int sx, int sy) {
        S[totid].reset();
        sz[totid] = 0; ok[totid] = true;
        rep(i, 1, n) rep(j, 1, m) vis[i][j] = 0;
        q.push({sx, sy}); vis[sx][sy] = 1;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            S[totid][id[{x - sx, y - sy}]] = true;
            //printf("%d %d -> %d %d, %d\n",sx, sy, x, y, id[{x - sx, y - sy}]);
            rep(i, 0, 3) {
                int tx = x + dx[i], ty = y + dy[i];
                if (valid(tx, ty)) {q.push({tx, ty}); vis[tx][ty] = true;}
            }
        }
        sz[totid] = S[totid].count();
        //rep(i, 0, tot - 1) printf("%d", (int)S[totid][i]); puts("");
    };
    rep(i, 1, n) rep(j, 1, m) {
        if (a[i][j] == 'O') continue;
        bfs(i, j); ++totid;
    }
    --totid;
    rep(i, 0, totid) rep(j, i + 1, totid) {
        int w = (S[i] & S[j]).count();
        if (w == sz[i]) ok[i] = false;
        if (w == sz[j]) ok[j] = false;
    }
    int ans = 0;
    rep(i, 0, totid) ans += ok[i];
    printf("%d\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}