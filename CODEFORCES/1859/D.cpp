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

int ans[N];

struct node {int l, r, a, b;} c[N];

vector<pair<int, int> > s;

inline void work() {
    int n = rd();
    for (int i = 1; i <= n; ++i) {
        c[i].l = rd(); c[i].r = rd();
        c[i].a = rd(); c[i].b = rd();
    }
    sort(c + 1, c + 1 + n, [&](node &a, node &b){return a.b > b.b;});

    int q = rd();
    s.clear();
    for (int i = 1; i <= q; ++i) s.emplace_back(rd(), i);
    sort(s.begin(), s.end());
    int L = c[1].l, R = c[1].r, nwr = c[1].b;
    while (!s.empty() && s.back().first >= L) {
        auto [pos, id] = s.back(); s.pop_back();
        ans[id] = max(pos, nwr);
    }
    for (int i = 2; i <= n; ++i) {
        if (c[i].b < L) {
            L = c[i].l; R = c[i].r; nwr = c[i].b;
        } else L = min(L, c[i].l);
        while (!s.empty() && s.back().first >= L) {
            auto [pos, id] = s.back(); s.pop_back();
            ans[id] = max(pos, nwr);
        }
    }
    for (auto [pos, id] : s) ans[id] = pos;
    for (int i = 1; i <= q; ++i) printf("%d ", ans[i]);
    puts("");
}

int main() {
    for (int t = rd(); t; --t) work();
    return 0;
}