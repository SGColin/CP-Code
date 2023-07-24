#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll rd() {
    ll x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define N 300007

struct node {int t, d;} s[N];

int n, mxt, mxd[N];

ll H, mx, mxp[N];

inline bool valid(ll T) {
    auto sum = [&](ll L, ll R) {return (R - L + 1) * (L + R) / 2;};
    auto mul = [&](ll a, ll b) {return 2e18 / a <= b ? (ll)1e18 : a * b;};
    
    ll nw = 0;
    if (T > mxt) {nw += mul(T - mxt, mx); T = mxt;}
    if (nw >= H) return true;
    for (int i = 1; i <= n; ++i) {
        // t in [s[i - 1].t + 1, min(s[i].t, T)]
        if (s[i].t == s[i - 1].t) continue;
        ll L = s[i - 1].t + 1, R = min(1ll * s[i].t, T);
        if (L > R) break;
        // choose max(t * mxd[i], mxp[i - 1]) for t
        // the time t * mxd[i] > mxp[i - 1]
        ll key = (mxp[i - 1] + mxd[i] - 1) / mxd[i];
        if (key > R) nw += (R - L + 1) * mxp[i - 1];
        else if (key <= L) nw += mul(sum(L, R), mxd[i]);
        else nw += mul(sum(key, R), mxd[i]) + mul((key - L), mxp[i - 1]);
        if (nw >= H) return true;
    }
    return nw >= H;
}

int main() {
    n = rd(); H = rd();
    for (int i = 1; i <= n; ++i) {
        s[i].t = rd(); s[i].d = rd();
        if (1ll * s[i].t * s[i].d > mx) {
            mx = 1ll * s[i].t * s[i].d;
            mxt = s[i].t;
        }
    }
    sort(s + 1, s + 1 + n, [&](node &a, node &b){return a.t < b.t;});
    for (int i = n; i; --i) mxd[i] = max(mxd[i + 1], s[i].d);
    for (int i = 1; i <= n; ++i) mxp[i] = max(mxp[i - 1], 1ll * s[i].t * s[i].d);
    ll l = 1, r = max(1ll * mxt, H / mx) * 2;
    while (l < r) {
        ll mid = (l + r) / 2;
        valid(mid) ? r = mid : l = mid + 1;
    }
    printf("%lld\n", l);
    return 0;
}