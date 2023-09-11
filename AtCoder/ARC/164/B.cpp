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

int f[N], c[N];

vector<pair<int, int>> e;

int find(int x) {return f[x] == x ? x : f[x] = find(f[x]);}

int main() {
    int n = rd(), m = rd();
    for (int i = 1; i <= m; ++i) {
        e.push_back(make_pair(rd(), rd()));
    }
    for (int i = 1; i <= n; ++i) c[i] = rd(), f[i] = i;
    for (auto [u, v] : e) {
        if (c[u] != c[v]) {
            u = find(u); v = find(v); f[u] = v;
        }
    }
    for (auto [u, v] : e) {
        if (c[u] == c[v] && u != v) {
            if (find(u) == find(v)) {puts("Yes"); return 0;}
        }
    }
    puts("No");
    return 0;
}