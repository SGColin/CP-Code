#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
typedef tuple<ll, int, int> tlii;
typedef tuple<ll, int, int, int> tliii;

inline ll rd() {
    ll x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define N 2107
#define mp make_pair
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

vector<pli> s;

int a[N], n, q;

ll c[N][N];

inline int lowbit(int x) {return x & (-x);}

inline void add(int x, int y, ll w) {
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= n; j += lowbit(j)) if (w > c[i][j]) c[i][j] = w;
}

inline ll qmx(int x, int y) {
    ll w = -8e18;
    for (int i = x; i; i -= lowbit(i))
        for (int j = y; j; j -= lowbit(j)) if (c[i][j] > w) w = c[i][j];
    return w;
}

vector<tlii> S;

vector<tliii> Q;

ll ans[200007];

int main() {
    n = rd(), q = rd();
    rep(i, 1, n) {
        a[i] = rd();
        ll sum = 0;
        per(j, i, 1) {sum += a[j]; S.eb(sum, j, i);}
    }
    sort(S.begin(), S.end());
   
    rep(i, 1, q) {
        ll l = rd(), r = rd(), u = rd();
        Q.eb(u, l, r, i);
    }
    sort(Q.begin(), Q.end());

    memset(c, 0xcf, sizeof(c));
    ll mnf = c[0][0];
    int ptr = 0;
    for (auto [u, L, R, id] : Q) {
        while (ptr < S.size() && get<0>(S[ptr]) <= u) {
            auto [w, l, r] = S[ptr];
            add(n + 1 - l, r, w); ++ptr;
        }
        ans[id] = qmx(n + 1 - L, R);
    }
    rep(i, 1, q) {
        if (ans[i] > mnf) printf("%lld\n", ans[i]);
        else puts("NONE");
    }
    return 0;
}