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

#define N 2007
#define mod 998244353

int dp[N][N], sum[N][N], h[N];

int main() {  
    int n = rd(), m = rd();
    for (int i = 0; i <= m; ++i) h[i] = n + 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            char c = getchar();
            while (c != '.' && c != '#') c = getchar();
            if (c == '#') h[j] = min(h[j], i);
        }
    sum[0][n + 1] = 1; 
    for (int i = 1; i <= m; ++i) {
        h[i] = min(h[i], h[i - 1] + 1);
        for (int j = 1; j <= h[i]; ++j) 
            dp[i][j] = (sum[i - 1][n + 1] + mod - (j > 1 ? sum[i - 1][j - 2] : 0)) % mod;
        for (int j = 1; j <= n + 1; ++j) sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
    }
    printf("%d\n", sum[m][n + 1]);
    return 0;
}