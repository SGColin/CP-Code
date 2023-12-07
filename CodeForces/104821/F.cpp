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

#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

const int N = 100007;

bool nxt[N];

int ans[N];

vector<int> s[N];

inline void work() {
    int n = rd(), m = rd();
    rep(i, 1, m) s[i].clear();
    rep(i, 1, n) {
        nxt[i] = false; ans[i] = i;
        per(j, rd(), 1) s[rd()].eb(i);
    }
    rep(i, 1, m) if (!s[i].empty()){
        int sink = s[i].back();
        for (auto u : s[i]) if (sink == u + 1) nxt[u] = true;
    }
    rep(i, 1, n - 1) if (!nxt[i]) {
        puts("Yes");
        swap(ans[i], ans[i + 1]);
        printf("%d", ans[1]);
        rep(i, 2, n) printf(" %d", ans[i]);
        puts("");
        return;
    }
    puts("No");
}

/* 

//Solution 2: Largest Topological Order

vector<int> s[N], e[N];

int deg[N], seq[N];

priority_queue<int> q;

inline void work() {
    int n = rd(), m = rd();
    rep(i, 1, m) s[i].clear();
    rep(i, 1, n) {
        int k = rd();
        rep(j, 1, k) s[rd()].eb(i);
        deg[i] = 0; e[i].clear();
    }
    auto add = [&](int u, int v) {++deg[v]; e[u].eb(v);};
    rep(i, 1, m) if (!s[i].empty()){
        int sink = s[i].back(); s[i].pop_back();
        for (auto u : s[i]) add(u, sink);
    }
    while (!q.empty()) q.pop();
    rep(i, 1, n) if (!deg[i]) q.push(i);
    seq[0] = 0;
    while (!q.empty()) {
        int u = q.top(); q.pop();
        seq[++seq[0]] = u;
        for (auto v : e[u]) {--deg[v]; if (!deg[v]) q.push(v);}
    }
    bool fl = false;
    rep(i, 1, n) if (seq[i] != i) fl = true;
    if (!fl) {puts("No"); return;}
    puts("Yes");
    printf("%d", seq[1]);
    rep(i, 2, n) printf(" %d", seq[i]);
    puts("");
}

*/

int main() {
    per(t, rd(), 1) work();
    return 0;
}