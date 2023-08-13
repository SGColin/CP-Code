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

#define N 107
#define mod 998244353

int a[N];

inline void work() {
    int n = rd();
    int mn = 2e9, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        a[i] = rd();
        if (a[i] == mn) ++cnt;
        else if (a[i] < mn) {mn = a[i]; cnt = 1;}
    }
    if (cnt == n) {puts("-1"); return;}
    printf("%d %d\n", cnt, n - cnt);
    for (int i = 1; i <= cnt; ++i) printf("%d ", mn); puts("");
    for (int i = 1; i <= n; ++i)
        if (a[i] != mn) printf("%d ", a[i]); puts("");
}

int main() {
    int t = rd();
    while (t--) work();
    return 0;
}