#include<bits/stdc++.h>
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

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 16777216

char s[10];

int f[N];

int main() {
    int n = rd();
    rep(i, 1, n) {
        scanf("%s", s + 1);
        int v = 0;
        rep(j, 1, 3) v |= (1 << (s[j] - 'a')); 
        ++f[v];
    }
    rep(i, 0, 23) rep(s, 0, N - 1) 
        if (s & (1 << i)) f[s] += f[s ^ (1 << i)];
    int ans = 0;
    rep(s, 0, N - 1) ans ^= ((n - f[s]) * (n - f[s]));
    printf("%d\n", ans);
    return 0;
}