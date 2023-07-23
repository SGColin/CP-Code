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

#define N 3007

int a[N][N], dp[N][N];

ll ans;

int main() {   
    int h = rd(), w = rd(), n = rd();
    for (int i = 1; i <= n; ++i) {
        int x = rd(), y = rd(); a[x][y] = 1;
    }
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j) 
            if (!a[i][j]) {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                ans += dp[i][j];
            }
    printf("%lld\n", ans);
    return 0;
}