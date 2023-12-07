#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

const int N = 100007;

ll a[N], prec[N], sufc[N];

set<pll> pre, suf;

inline void work() {
    int n = rd();
    ll MAXA = 0, SUMA = 0, PRE = 0, SUF = 0;
    rep(i, 1, n) {
        a[i] = rd(); prec[i] = sufc[i] = 0;
        SUMA += a[i]; MAXA = max(MAXA, a[i]);
    }
    a[0] = a[n + 1] = 1e18;
    
    // init pre
    ll mx = 0, lst = 0; 
    pre.clear(); pre.insert({0, 0});
    rep(i, 1, n + 1) if (a[i] > mx) {
        PRE += (prec[lst] = mx * (i - lst));
        pre.insert({a[i], i}); mx = a[i]; lst = i;
    } 

    // init suf
    mx = 0; lst = n + 1;
    suf.clear(); suf.insert({0, n + 1}); 
    per(i, n, 0) if (a[i] > mx) {
        SUF += (sufc[lst] = mx * (lst - i));
        suf.insert({a[i], i}); mx = a[i]; lst = i;
    }

    auto updpre = [&](pll cur) {
        auto [w, pos] = cur;
        auto it = prev(pre.upper_bound(cur));
        for (; (it -> second) >= pos; it = prev(pre.erase(it))) {
            PRE -= prec[it -> second]; prec[it -> second] = 0;
        } 
        auto [wp, posp] = *it;
        PRE -= prec[posp]; 
        prec[posp] = wp * (pos - posp); 
        PRE += prec[posp];

        it = pre.upper_bound(cur);
        prec[pos] = w * ((it -> second) - pos);
        PRE += prec[pos];

        pre.insert(cur);
    };

    auto updsuf = [&](pll cur) {
        auto [w, pos] = cur;
        auto it = prev(suf.upper_bound(cur));
        for (; (it -> second) <= pos; it = prev(suf.erase(it))) {
            SUF -= sufc[it -> second]; sufc[it -> second] = 0;
        }
        auto [wp, posp] = *it;
        SUF -= sufc[posp]; 
        sufc[posp] = wp * (posp - pos); 
        SUF += sufc[posp];

        it = suf.upper_bound(cur);
        sufc[pos] = w * (pos - (it -> second));
        SUF += sufc[pos];

        suf.insert(cur);
    };

    per(q, rd(), 1) {
        int x = rd(), v = rd();
        a[x] += v; SUMA += v; MAXA = max(MAXA, a[x]);
        if (x < (pre.lower_bound({a[x], 0}) -> second)) updpre({a[x], x});
        if (x > (suf.lower_bound({a[x], 0}) -> second)) updsuf({a[x], x});
        printf("%lld\n", PRE + SUF - SUMA - MAXA * n);
    }
}

/*

Solution 2: Segtree

struct segmx {
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    #define mid ((l + r) / 2)
    ll mx[N << 2];

    void pushup(int rt) {mx[rt] = max(mx[ls], mx[rs]);}

    void build(int rt, int l, int r) {
        if (l == r) {mx[rt] = a[l]; return;}
        build(ls, l, mid); build(rs, mid + 1, r);
        pushup(rt);
    }

    void upd(int rt, int l, int r, int p, ll x) {
        if (l == r) {mx[rt] = x; return;}
        p <= mid ? upd(ls, l, mid, p, x) : upd(rs, mid + 1, r, p, x);
        pushup(rt);
    }

    ll qmax(int rt, int l, int r, int L, int R) {
        if (L <= l && r <= R) return mx[rt];
        ll ans = 0;
        if (L <= mid) ans = max(ans, qmax(ls, l, mid, L, R));
        if (R > mid) ans = max(ans, qmax(rs, mid + 1, r, L, R));
        return ans;
    }

    int nxtr(int rt, int l, int r, int L, ll w) {
        if (l == r) return l;
        if (L <= mid && mx[ls] >= w) {
            int res = nxtr(ls, l, mid, L, w);
            if (res > 0) return res;
        }
        if (mx[rs] < w) return -1;
        return nxtr(rs, mid + 1, r, L, w);
    }

    int nxtl(int rt, int l, int r, int L, ll w) {
        if (l == r) return l;
        if (L > mid && mx[rs] >= w) {
            int res = nxtl(rs, mid + 1, r, L, w);
            if (res > 0) return res;
        }
        if (mx[ls] < w) return -1;
        return nxtl(ls, l, mid, L, w);
    }

} smx;

struct segsum {
    #define ls (rt << 1)
    #define rs (rt << 1 | 1)
    #define mid ((l + r) / 2)
    ll sum[N << 2];
    bool tag[N << 2];
    void pushup(int rt) {sum[rt] = sum[ls] + sum[rs];}
    void pushdown(int rt) {
        if (tag[rt]) {
            tag[ls] = 1; sum[ls] = 0;
            tag[rs] = 1; sum[rs] = 0;
            tag[rt] = 0;
        }
    }
    void reset(int rt, int l, int r, int L, int R) {
        if (L <= l && r <= R) {tag[rt] = 1; sum[rt] = 0; return;}
        pushdown(rt);
        if (L <= mid) reset(ls, l, mid, L, R);
        if (R > mid) reset(rs, mid + 1, r, L, R);
        pushup(rt);
    }
    void upd(int rt, int l, int r, int pos, ll x) {
        if (l == r) {sum[rt] = x; return;}
        pushdown(rt);
        pos <= mid ? upd(ls, l, mid, pos, x) : upd(rs, mid + 1, r, pos, x);
        pushup(rt);
    }
    int nxtl(int rt, int l, int r, int L) {
        if (l == r) return l;
        pushdown(rt);
        if (L > mid && sum[rs] > 0) {
            int res = nxtl(rs, mid + 1, r, L);
            if (res > 0) return res;
        }
        if (sum[ls] == 0) return -1;
        return nxtl(ls, l, mid, L);
    }
    int nxtr(int rt, int l, int r, int L) {
        if (l == r) return l;
        pushdown(rt);
        if (L <= mid && sum[ls] > 0) {
            int res = nxtr(ls, l, mid, L);
            if (res > 0) return res;
        }
        if (sum[rs] == 0) return -1;
        return nxtr(rs, mid + 1, r, L);
    }
    void print(int rt, int l, int r) {
        if (l == r) {printf("%lld ", sum[rt]); return;}
        pushdown(rt);
        print(ls, l, mid); print(rs, mid + 1, r);
    }
} pre, suf;

inline void work() {
    ans = 0;
    int n = rd();
    rep(i, 1, n) a[i] = rd();
    smx.build(1, 1, n);
    pre.reset(1, 1, n, 1, n);
    suf.reset(1, 1, n, 1, n);
    rep(p, 1, n) {
        ans -= a[p];
        if (a[p] == smx.qmax(1, 1, n, 1, p)) { //premax
            if (p == n) pre.upd(1, 1, n, p, a[p]);
            else {
                int pos = smx.nxtr(1, 1, n, p + 1, a[p]);
                if (pos == -1) pos = n + 1;
                pre.upd(1, 1, n, p, 1ll * a[p] * (pos - p));
            }
        }
        if (a[p] == smx.qmax(1, 1, n, p, n)) { // sufmax
            if (p == 1) suf.upd(1, 1, n, p, a[p]);
            else {
                int pos = smx.nxtl(1, 1, n, p - 1, a[p]);
                if (pos == -1) pos = 0;
                suf.upd(1, 1, n, p, 1ll * a[p] * (p - pos));
            }
        }
    }

    auto calc = [&](int p) {
        smx.upd(1, 1, n, p, a[p]);
        if (a[p] == smx.qmax(1, 1, n, 1, p)) { //premax
            if (p == n) pre.upd(1, 1, n, p, a[p]);
            else {
                int pos = smx.nxtr(1, 1, n, p + 1, a[p]);
                if (pos == -1) pos = n + 1;
                pre.upd(1, 1, n, p, 1ll * a[p] * (pos - p));
                pre.reset(1, 1, n, p + 1, pos - 1);
            }
            if (p > 1) {
                int pos = pre.nxtl(1, 1, n, p - 1);
                if (pos > 0) pre.upd(1, 1, n, pos, 1ll * a[pos] * (p - pos));
            }
        } else pre.upd(1, 1, n, p, 0);
        if (a[p] == smx.qmax(1, 1, n, p, n)) { // sufmax
            if (p == 1) suf.upd(1, 1, n, p, a[p]);
            else {
                int pos = smx.nxtl(1, 1, n, p - 1, a[p]);
                if (pos == -1) pos = 0;
                suf.upd(1, 1, n, p, 1ll * a[p] * (p - pos));
                suf.reset(1, 1, n, pos + 1, p - 1);
            }
            if (p < n) {
                int pos = suf.nxtr(1, 1, n, p + 1);
                if (pos > 0) suf.upd(1, 1, n, pos, 1ll * a[pos] * (pos - p));
            }
        } else suf.upd(1, 1, n, p, 0);
    };

    //pre.print(1, 1, n); puts("");
    //suf.print(1, 1, n); puts("");

    int q = rd();
    rep(i, 1, q) {
        int p = rd(), w = rd();
        a[p] += w; ans -= w; calc(p);
        //pre.print(1, 1, n); puts("");
        //suf.print(1, 1, n); puts("");
        printf("%lld\n", ans + pre.sum[1] + suf.sum[1] - 1ll * n * smx.mx[1]);
    }
}

*/

int main() {
    per(t, rd(), 1) work();
    return 0;
}