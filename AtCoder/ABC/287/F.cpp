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

#define N 5007
#define mod 998244353

inline int add(int x, int y) {return (x + y >= mod ? x + y - mod : x + y);}
inline int mul(int x, int y) {return 1ll * x * y % mod;}

int f[N][N][2], sz[N], n, g[N][2];

vector<int> e[N];

void dfs(int u, int fa) {
    f[u][0][0] = f[u][1][1] = 1; sz[u] = 1;
    for (auto v : e[u])
        if (v != fa) {
            dfs(v, u);
            for (int j = 0; j <= sz[u] + sz[v]; ++j) {
                g[j][0] = f[u][j][0]; g[j][1] = f[u][j][1];
                f[u][j][0] = f[u][j][1] = 0;
            }
            for (int j = sz[u] + sz[v]; j >= 0; --j) 
                // 上界就是该儿子的子树的最大体积和在他前面的子树的最大体积的和
                for (int k = max(0, j - sz[u]); k <= min(j, sz[v]); ++k) {
                    // 上界时不超过该儿子的子树的最大体积，下界表示能给当前子树的最小体积，就是前面的子树都塞满
                    f[u][j][0] = add(f[u][j][0], mul(g[j - k][0], add(f[v][k][0], f[v][k][1])));
                    f[u][j][1] = add(f[u][j][1], add(mul(g[j - k][1], f[v][k][0]), mul(g[j - k][1], f[v][k + 1][1])));
                }
            sz[u] += sz[v];
        }
}

int main() {
    n = rd();
    for (int i = 1; i < n; ++i) {
        int u = rd(), v = rd(); e[u].pb(v); e[v].pb(u);
    }
    dfs(1, 1);
    for (int i = 1; i <= n; ++i)
        printf("%d\n", add(f[1][i][0], f[1][i][1]));
    return 0;
}