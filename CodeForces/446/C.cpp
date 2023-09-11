#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

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

#define N 530007
#define mod 1000000009

inline int mo(int x) {return x >= mod ? x - mod : x;}

int fib[N];

int qval(int a, int b, int p) {
    if (p == 1) return a;
    return (1ll * fib[p - 2] * a + 1ll * fib[p - 1] * b) % mod;
}

int qsum(int a, int b, int p) {return mo(qval(a, b, p + 2) + mod - b);}

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) >> 1)

int sum[N << 2], taga[N << 2], tagb[N << 2];

void pushup(int rt) {sum[rt] = mo(sum[ls] + sum[rs]);}

void pushdown(int rt, int l, int r) {
    if (taga[rt] || tagb[rt]) {
        int &a = taga[rt], &b = tagb[rt];
        taga[ls] = mo(taga[ls] + a);
        tagb[ls] = mo(tagb[ls] + b);
        sum[ls] = mo(sum[ls] + qsum(a, b, mid - l + 1));
        int _a = qval(a, b, mid + 2 - l);
        int _b = qval(a, b, mid + 3 - l);
        taga[rs] = mo(taga[rs] + _a);
        tagb[rs] = mo(tagb[rs] + _b);
        sum[rs] = mo(sum[rs] + qsum(_a, _b, r - mid));
        a = b = 0;
    }
}

void build(int rt, int l, int r) {
    if (l == r) {sum[rt] = rd(); return;}
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(rt);
}

void upd(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) {
        int a = fib[l - L + 1], b = fib[l - L + 2];
        taga[rt] = mo(taga[rt] + a);
        tagb[rt] = mo(tagb[rt] + b);
        sum[rt] = mo(sum[rt] + qsum(a, b, r - l + 1));
        return;
    }
    pushdown(rt, l, r);
    if (L <= mid) upd(ls, l, mid, L, R);
    if (R > mid) upd(rs, mid + 1, r, L, R);
    pushup(rt);
}

int query(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) return sum[rt];
    pushdown(rt, l, r);
    int ret = 0;
    if (L <= mid) ret = mo(ret + query(ls, l, mid, L, R));
    if (R > mid) ret = mo(ret + query(rs, mid + 1, r, L, R));
    return ret;
}

int main() {
    int n = rd(), m = rd();
    fib[1] = fib[2] = 1;
    rep(i, 3, N - 1) fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    build(1, 1, n);
    rep(i, 1, m) {
        int op = rd(), l = rd(), r = rd();
        if (op == 1) upd(1, 1, n, l, r);
        else printf("%d\n", query(1, 1, n, l, r));
    }
    return 0;
}  