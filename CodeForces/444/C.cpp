#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline char rdc(){
    static char buf[1 << 16], *l = buf, *r = buf;
    return l == r && (r = (l = buf) + fread(buf, 1, 1 << 16, stdin), l == r) ? EOF : *l++;
}

inline int rd() {
    int x = 0; 
    bool f = 0; 
    char c = rdc();
    for (; !isdigit(c); c = rdc()) f |= (c == '-');
    for (; isdigit(c); c = rdc()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 150007

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) >> 1)

int col[N << 2];

ll sum[N << 2], sig[N << 2];

void pushup(int rt) {
    sum[rt] = sum[ls] + sum[rs];
    col[rt] = (col[ls] == col[rs] ? col[ls] : -1);
}

void build(int rt, int l, int r) {
    if (l == r) {col[rt] = l; return;}
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(rt);
}

void pushdown(int rt, int l, int r) {
    if (sig[rt] != 0) {
        sig[ls] += sig[rt];
        sum[ls] += sig[rt] * (mid - l + 1);
        col[ls] = col[rt];
        
        sig[rs] += sig[rt];
        sum[rs] += sig[rt] * (r - mid);
        col[rs] = col[rt];

        sig[rt] = 0;
    }
}

void upd(int rt, int l, int r, int L, int R, int x) {
    if (L <= l && r <= R && col[rt] != -1) {
        sig[rt] += abs(x - col[rt]);
        sum[rt] += 1ll * abs(x - col[rt]) * (r - l + 1);
        col[rt] = x;
        return;
    }
    pushdown(rt, l, r);
    if (L <= mid) upd(ls, l, mid, L, R, x);
    if (R > mid) upd(rs, mid + 1, r, L, R, x);
    pushup(rt);
}

ll query(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) return sum[rt];
    pushdown(rt, l, r);
    ll ret = 0;
    if (L <= mid) ret += query(ls, l, mid, L, R);
    if (R > mid) ret += query(rs, mid + 1, r, L, R);
    return ret;
}

int main() {
    int n = rd(), m = rd();
    build(1, 1, n);
    rep(i, 1, m) {
        int op = rd(), l = rd(), r = rd();
        if (op == 1) upd(1, 1, n, l, r, rd());
        else printf("%lld\n", query(1, 1, n, l, r));
    }
    return 0;
}  