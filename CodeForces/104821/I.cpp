#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

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

inline void work() {
    int n = rd(), m = rd();
    vector<pii> s;
    rep(i, 1, m) {int a = rd(), b = rd(); s.eb(a, b);}
    sort(all(s));
    int t = 0, v = 0;
    for (auto [_t, _v] : s) {
        int gap = _t - t;
        bool fl = false;
        if (v + gap == _v) fl = true;
        else if (gap > _v) fl = true;
        v = _v; t = _t;
        if (!fl) {puts("No"); return;}
    }
    puts("Yes");
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}