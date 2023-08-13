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

#define N 3007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

/*
0 : --
1 : -+
2 : +-
3 : ++
4 : not choose
*/

int a[N], b[N];

ll f[N][5];

inline void work() {
    
    int n = rd(), m = rd();
    
    rep(i, 0, n) rep(j, 0, 4) f[i][j] = -1e18;
    f[0][4] = 0;
    
    rep(i, 1, n) a[i] = rd();
    rep(i, 1, n) b[i] = rd();

    rep(i, 1, n) {
        per(k, i, 1) {
            int w[4] = {- a[i] - b[i], - a[i] + b[i], a[i] - b[i], a[i] + b[i]};
            for (int j = 0; j < 4; ++j) {
                f[k][j] = max(f[k - 1][j], f[k - 1][4] + w[j]);
                f[k][4] = max(f[k][4], f[k - 1][j] + w[j ^ 3]);   
            }
            f[k][4] = max(f[k][4], f[k - 1][4] + abs(a[i] - b[i]) * 2ll);
        }
    }
    printf("%lld\n", f[m][4]);
}

int main() {
    for (int t = rd(); t; --t) work();
    return 0;
}