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

#define mod 998244353

vector<int> s;

inline void work() {
    int n = rd();
    ll ans = 0;
    int mn = 2e9, smn = 2e9;
    for (int i = 1; i <= n; ++i) {
        s.clear();
        int len = rd();
        while (len--) s.push_back(rd());
        sort(s.begin(), s.end());
        ans += s[1];
        mn = min(mn, s[0]);
        smn = min(smn, s[1]);
    }
    ans -= smn - mn;
    printf("%lld\n", ans);
}

int main() {
    int t = rd();
    while (t--) work();
    return 0;
}