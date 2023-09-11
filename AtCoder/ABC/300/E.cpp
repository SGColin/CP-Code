#include <bits/stdc++.h>
using namespace std;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int>  pii;
typedef tuple<int, int, int> tii;

#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define lowbit(x)    ((x) & -(x))
#define all(x)       (x).begin(), (x).end()
#define rep(i, x, y) for (int i = (x); i <= (y); ++i)
#define per(i, x, y) for (int i = (x); i >= (y); --i)

#define mod 998244353

inline int fpow(int x, int t = mod - 2) {
    int res = 1;
    for (; t; t >>= 1, x = 1ll * x * x % mod) 
        if (t & 1) res = 1ll * res * x % mod;
    return res;
}

const int inv5 = fpow(5);

ll n;

int cnt[7], fac[100000];

int main() {
    fac[0] = fac[1] = 1;
    rep(i, 2, 99999) fac[i] = 1ll * fac[i - 1] * i % mod;
    cin >> n;
    per(i, 6, 2) while (n % i == 0) {++cnt[i]; n = n / i;}
    if (n > 1) {puts("0"); return 0;}

    int ans = 0, sum = 0;
    rep(i, 2, 6) sum += cnt[i];
    rep(a6, 0, cnt[6]) 
        rep(a4, 0, cnt[4] + (cnt[2] + cnt[6] - a6) / 2) {
            int a2 = cnt[2] + cnt[6] - a6 + (cnt[4] - a4) * 2;
            int a3 = cnt[3] + cnt[6] - a6;
            int tsum = a2 + a3 + a4 + cnt[5] + a6; 
            int res = 1ll * fac[tsum] * fpow(inv5, tsum) % mod;
            res = 1ll * res * fpow(fac[a2]) % mod;
            res = 1ll * res * fpow(fac[a3]) % mod;
            res = 1ll * res * fpow(fac[a4]) % mod;
            res = 1ll * res * fpow(fac[cnt[5]]) % mod;
            res = 1ll * res * fpow(fac[a6]) % mod;
            ans = (ans + res) % mod;
        }
    printf("%d\n", ans);
    return 0;
}