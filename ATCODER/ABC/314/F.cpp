#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define N 200007
#define mod 998244353

vector<int> s[N];

int pos[N], sz[N], bel[N], ans[N], inv[N], tag[N];

ll frac(int up, int dn) {return 1ll * up * inv[dn] % mod;}

int main() {
    int n = rd();
    inv[1] = 1; 
    for (int i = 2; i <= n; ++i) 
        inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    for (int i = 1; i <= n; ++i) {
        s[i].push_back(i);
        pos[i] = bel[i] = i; sz[i] = 1;
    }
    for (int i = 1; i < n; ++i) {
        int u = bel[rd()], v = bel[rd()];
        if (sz[u] < sz[v]) swap(u, v);
        auto &sequ = s[pos[u]], &seqv = s[pos[v]];
        int big = frac(sz[u], sz[u] + sz[v]);
        int small = frac(sz[v], sz[u] + sz[v]);
        tag[u] = (tag[u] + big) % mod;
        for (auto x : seqv) {
            sequ.push_back(x);
            bel[x] = pos[x] = u;
            ans[x] = (1ll * ans[x] + tag[v] + small + mod - tag[u]) % mod;
        }
        sz[u] += sz[v];
    }
    int rt = bel[1];
    for (int i = 1; i <= n; ++i)
        printf("%d ", (ans[i] + tag[rt]) % mod);
    return 0;
}