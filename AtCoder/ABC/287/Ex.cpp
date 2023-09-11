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

#define N 2007
#define M 10007

int ans[M], s[M], t[M];

bitset<N> adj[N];

int main() {
    int n = rd(), m = rd();
    rep(u, 1, n) adj[u][u] = true;
    rep(i, 1, m) {int u = rd(), v = rd(); adj[u][v] = true;}
    int q = rd();
    rep(i, 1, q) {s[i] = rd(); t[i] = rd(); ans[i] = -1;}
    rep(v, 1, n) {
        rep(u, 1, n) if (adj[u][v]) adj[u] |= adj[v]; 
        rep(i, 1, q) if (ans[i] == -1 && adj[s[i]][t[i]]) ans[i] = v;
    }
    rep(i, 1, q) printf("%d\n", ans[i] == -1 ? -1 : max({ans[i], s[i], t[i]}));
    return 0;
}