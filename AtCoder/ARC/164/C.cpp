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

int main() {
    int n = rd();
    bool is0 = false;
    ll ans = 0;
    int mnpos = 2e9, mnneg = 2e9, cntneg = 0;
    for (int i = 1; i <= n; ++i) {
        int A = rd(), B = rd();
        if (A <= B) {
            ans += B;
            mnpos = min(mnpos, B - A);
        } else {
            ans += A; ++cntneg;
            mnneg = min(mnneg, A - B);
        }
    }
    if (cntneg & 1) ans -= min(mnpos, mnneg);
    printf("%lld\n", ans);
    return 0;
}