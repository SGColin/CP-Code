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

vector<ll> a, b;

int main() {
    ll n = rd(), m = rd(), d = rd();
    for (int i = 1; i <= n; ++i) a.push_back(rd());
    for (int i = 1; i <= m; ++i) b.push_back(rd());
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ll j = 0, ans = -1;
    for (auto x : b) {
        while (j < n - 1 && a[j + 1] <= x + d) ++j;
        if (a[j] <= x + d && a[j] >= x - d) ans = max(ans, x + a[j]);
    }
    printf("%lld\n", ans);
    return 0;
}