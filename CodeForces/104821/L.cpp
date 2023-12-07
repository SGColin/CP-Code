#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;

inline ll rd() {
    ll x = 0;
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

vector<tiii> s;

inline void work() {
    s.clear();
    int n = rd();
    ll k = rd();
    rep(i, 1, n) {
        int c = rd(), w = rd(), f = rd();
        s.eb(f, c, w);
    }   
    sort(all(s));
    reverse(all(s));
    ll rem = 0, ans = 0, cnt1 = 0;
    for (auto [f, c, w] : s) {
        if (w == 1 && cnt1) {
            if (c <= cnt1) {cnt1 -= w; continue;}
            c -= cnt1; cnt1 = 0;
        }
        if (rem == 0) {rem = k; ans += f;}
        ll cnt = min(1ll * c, rem / w);
        c -= cnt; rem -= cnt * w;
        if (c) {
            cnt1 += (rem > 0); rem = 0;
            cnt = c / (k / w); ans += cnt * f;
            c %= (k / w);
            if (c) {
                ans += f;
                rem = k - c * w;
            }
        }
    }
    printf("%lld\n", ans);
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}