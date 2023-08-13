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

#define N 300007

int q, ans;

set<int> e[N];

void add(int u, int v) {
    if (e[u].empty()) --ans; e[u].insert(v);
    if (e[v].empty()) --ans; e[v].insert(u);
}

void del(int u) {
  	if (e[u].empty()) return;
    for (auto v : e[u]) {
        e[v].erase(u);
        if (e[v].empty()) ++ans;
    }
    e[u].clear(); ++ans;
}

int main() {
    ans = rd(); q = rd();
    for (int i = 1; i <= q; ++i) {
        int op = rd();
        op == 1 ? add(rd(), rd()) : del(rd());
        printf("%d\n", ans);
    }
    return 0;
}