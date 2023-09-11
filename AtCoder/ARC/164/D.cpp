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

#define N 6007
#define mod 998244353

char s[N];

ll f[N][3007], cnt[N][3007], suf[N][2], pre[N][2];

bool vis[N][3007];

int main() {
    int n = rd();
    int m = n * 2;
    scanf("%s", s + 1);
    for (int i = m; i; --i) {
        suf[i][0] = suf[i + 1][0] + (s[i] == '+');
        suf[i][1] = suf[i + 1][1] + (s[i] == '-');
    } 
    for (int i = 1; i <= m; ++i) {
        pre[i][0] = pre[i - 1][0] + (s[i] == '+');
        pre[i][1] = pre[i - 1][1] + (s[i] == '-');
    }
    vis[0][0] = true;
    cnt[0][0] = 1;
    for (int i = 1; i <= m; ++i) 
        for (int j = 0; j <= n; ++j) 
            if (vis[i - 1][j]) {
                // printf("%d %d %d\n", i - 1, j, f[i - 1][j]);
                if (s[i] == '+' || (s[i] == '?' && j + suf[i][0] < n)) {
                    // '+'
                    f[i][j + 1] = ((f[i][j + 1] + f[i - 1][j] + (j >= i - 1 - j ? -1 : 1) * i * cnt[i - 1][j]) % mod + mod) % mod;
                    cnt[i][j + 1] = (cnt[i][j + 1] + cnt[i - 1][j]) % mod;
                    vis[i][j + 1] = 1;
                }
                if (s[i] == '-' || (s[i] == '?' && i - 1 - j + suf[i][1] < n)) {
                    f[i][j] = ((f[i][j] + f[i - 1][j] + (j > i - 1 - j ? 1 : -1) * i * cnt[i - 1][j]) % mod + mod) % mod;
                    cnt[i][j] = (cnt[i][j] + cnt[i - 1][j]) % mod;
                    vis[i][j] = 1;
                }
            }
    printf("%lld\n", f[m][n]);
    return 0;
}