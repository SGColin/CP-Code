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

inline void work() {
    ll x = rd(), n = rd();
    ll lst = 0;
    while (x) {
        lst += x % 3;
        x = x / 3;
    }
    // printf("%lld\n", lst);
    if (n < lst) puts("No");
    else if ((n - lst) % 2 != 0) puts("No");
    else puts("Yes");
}

int main() {
    int t = rd();
    while (t--) work();
    return 0;
}