#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define lowbit(x) ((x) & -(x))
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define N 300007

ll f[N][2];

int main() {
    int n = rd();
    rep(i, 1, n) {
        int x = rd(), y = rd();
        f[i][0] = f[i - 1][0];
        f[i][1] = f[i - 1][1];
        if (x) f[i][1] = max({f[i][1], f[i - 1][0] + y});
        else f[i][0] = max({f[i][0], f[i - 1][0] + y, f[i - 1][1] + y});
    }
    printf("%lld\n", max(f[n][0], f[n][1]));
    return 0;
}
