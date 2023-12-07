#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

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

inline void work() {
    ll p = rd(), m = rd();
    if (p == 2) {printf("%lld\n", (ll)m / 2 + 1); return;}
    if (m < p) {printf("%d\n", (((p - 1) ^ (p + 1)) <= m)); return;}
    auto check = [&](ll k) {return ((k * p + 1) ^ (p - 1)) <= m;};
    ll k = m / p;
    printf("%lld\n", k + check(k) + check(k + 1));
}

int main() {
    per(t, rd(), 1) work();
    return 0;
}