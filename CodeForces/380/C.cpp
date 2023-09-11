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

#define N 1100007

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) >> 1)

char s[N];

struct node {
    int cnt, l, r;
    inline node operator + (const node &obj) const {
        node ret;
        int add = min(r, obj.l);
        ret.cnt = cnt + obj.cnt + add;
        ret.l = l + obj.l - add;
        ret.r = obj.r + r - add;
        return ret;
    }
} c[N << 2];

void build(int rt, int l, int r) {
    if (l == r) {c[rt] = {0, (s[l] == ')'), (s[l] == '(')}; return;}
    build(ls, l, mid);
    build(rs, mid + 1, r);
    c[rt] = c[ls] + c[rs];
}

node query(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) return c[rt];
    node ret = {0, 0, 0};
    if (L <= mid) ret = ret + query(ls, l, mid, L, R);
    if (R > mid) ret = ret + query(rs, mid + 1, r, L, R);
    return ret;
}

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    build(1, 1, n);
    for (int q = rd(); q; --q) {
        int l = rd(), r = rd();
        printf("%d\n", query(1, 1, n, l, r).cnt * 2);
    }
    return 0;
}  