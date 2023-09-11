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

#define pb push_back
#define mp make_pair
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 100007
#define mod 998244353

int a[N];

void work() {
    int n = rd(), m = rd(), d = rd();
    rep(i, 1, m) a[i] = rd();
    a[0] = 1 - d;
    a[++m] = n + 1;
    int ans = m - 1, mx = 0, cnt = 0;
    rep(i, 1, m) ans += (a[i] - a[i - 1] - 1) / d;
    rep(i, 1, m - 1) {
        int del = (a[i] - a[i - 1] - 1) / d + (a[i + 1] - a[i] - 1) / d + 1 - (a[i + 1] - a[i - 1] - 1) / d;
        if (del > mx) {mx = del; cnt = 1;}
        else if (del == mx) ++cnt;
    }   
    printf("%d %d\n", ans - mx, cnt);
}

int main() {
    for (int t = rd(); t; --t) work();
    return 0;
}