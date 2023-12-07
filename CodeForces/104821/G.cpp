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

const int N = 10007;

ll f[N];

vector<pii> g;

multiset<int> s, b;

inline void work() {
    int n = rd(), W = rd(), k = rd();
    rep(i, 1, n) {int w = rd(), v = rd(); g.eb(w, v);}
    ll ans = 0, sumk = 0;
    sort(all(g));
    for (auto [w, v] : g) s.insert(v);
    while (b.size() < k) {
        int v = (*(--s.end()));
        sumk += v; b.insert(v); s.erase(--s.end());
    }
    ans = sumk;
    if (k == n) {printf("%lld\n", ans); return;}
    for (auto [w, v] : g) {
        per(i, W, w) f[i] = max(f[i], f[i - w] + v);
        if (s.find(v) != s.end()) s.erase(s.find(v));
        else {
            b.erase(b.find(v)); sumk -= v;
            int v = (*(--s.end()));
            b.insert(v); sumk += v; s.erase(--s.end());
        }
        ans = max(ans, sumk + f[W]);
        if (s.empty()) break;
    }
    printf("%lld\n", ans);
}

int main() {
    work();
    //per(t, rd(), 1) work();
    return 0;
}