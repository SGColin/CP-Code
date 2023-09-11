#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define T int 
typedef pair<T, T> pii;
typedef tuple<T, T, T> tii;

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

inline T rd() {
    T x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define N 300007

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) >> 1)

vector<int> w;

int a[N], b[N];

vector<tii> work;

int cnt[N << 2];

ll sum[N << 2];

inline void pushup(int rt) {
    cnt[rt] = cnt[ls] + cnt[rs];
    sum[rt] = sum[ls] + sum[rs]; 
}

void upd(int rt, int l, int r, int p, int dlt) {
    if (l == r) {
        cnt[rt] += dlt;
        sum[rt] += 1ll * dlt * w[l];
        return;
    }
    p <= mid ? upd(ls, l, mid, p, dlt) : upd(rs, mid + 1, r, p, dlt);
    pushup(rt);
}

ll query(int rt, int l, int r, int tot) {
    if (cnt[rt] < tot) return -1;
    if (l == r) return 1ll * tot * w[l];
    if (cnt[rs] >= tot) return query(rs, mid + 1, r, tot);
    else return query(ls, l, mid, tot - cnt[rs]) + sum[rs];
}

int main() {
    int n = rd(); 
    rep(i, 1, n) {a[i] = rd(); b[i] = rd(); w.pb(a[i]);}
    int q = rd();
    rep(i, 1, q) {
        int op = rd(), x = rd();
        if (op == 1) {int y = rd(); w.pb(y); work.eb(op, x, y);}
        else if (op == 2) work.eb(op, x, rd());
        else work.eb(op, x, 0);
    }
    
    w.pb(-1); sort(all(w)); w.erase(unique(all(w)), w.end());
    auto getw = [&](int x) {return lower_bound(all(w), x) - w.begin();};
    
    int m = w.size();
    rep(i, 1, n) {a[i] = getw(a[i]); upd(1, 1, m, a[i], b[i]);}
    for (auto [op, x, y] : work) 
        if (op == 3) printf("%lld\n", query(1, 1, m, x));
        else {
            upd(1, 1, m, a[x], -b[x]);
            op == 1 ? a[x] = getw(y) : b[x] = y;
            upd(1, 1, m, a[x], b[x]);
        } 
    return 0;
}