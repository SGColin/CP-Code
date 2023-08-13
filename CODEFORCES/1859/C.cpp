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

#define N 251
#define mod 998244353

int a[N];

inline void work() {
    int n = rd();
    ll ans = 0;
    for (int p = 1; p <= n; ++p) {
        for (int i = 1; i < p; ++i) a[i] = i;
        for (int i = p; i <= n; ++i) a[i] = n - (i - p);
        ll score = 0, mx = 0;
        for (int i = 1; i <= n; ++i) {
            score += 1ll * a[i] * i;
            mx = max(mx, 1ll * a[i] * i);
        }
        ans = max(ans, score - mx);
    }
    printf("%lld\n", ans);
}

int main() {
    for (int t = rd(); t; --t) work();
    return 0;
}