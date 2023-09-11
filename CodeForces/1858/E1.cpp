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

#define pb push_back
#define mp make_pair
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 1000007

int cnt[N], ANS = 0;

void add(int x) {++cnt[x]; ANS += (cnt[x] == 1);}
void del(int x) {--cnt[x]; ANS -= (cnt[x] == 0);}

vector<int> query[N];
vector<pair<int, int>> son[N];

int fa[N][20], ans[N], tot, totq, pos[N], pre[N];

void dfs(int u) {
    for (auto id : query[u]) ans[id] = ANS;
    for (auto [v, w] : son[u]) {
        add(w);
        dfs(v);
        del(w);
    }
}

int main() {
    int n = rd();
    int nw = (tot = 1); pos[0] = 1;
    for (int i = 1; i <= n; ++i) {
        char c = getchar();
        while (c != '+' && c != '-' && c != '?' && c != '!') c = getchar();
        if (c == '+') {
            son[nw].pb(mp(++tot, rd()));
            fa[tot][0] = nw;
            rep(d, 1, 19) fa[tot][d] = fa[fa[tot][d - 1]][d - 1];
            pre[i] = i - 1;
            nw = tot;
        } else if (c == '-') {
            int len = rd();
            per(d, 19, 0) if (len & (1 << d)) nw = fa[nw][d];
            pre[i] = i - 1;
        } else if (c == '?') {
            query[nw].push_back(++totq);
            pre[i] = pre[i - 1];
        } else {
            nw = pos[pre[i - 1]];
            pre[i] = pre[pre[i - 1]];
        }
        pos[i] = nw;
    }
    dfs(1);
    rep(i, 1, totq) printf("%d\n", ans[i]);
    return 0;
}