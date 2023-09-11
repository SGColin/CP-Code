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
#define inf 1000000000

int a[N], lst[N], ans[N];

struct Q {int l, r, id;} s[N];

pii mn[N << 2];

#define ls (rt << 1)
#define rs (rt << 1 | 1)
#define mid ((l + r) / 2)

void pushup(int rt) {mn[rt] = min(mn[ls], mn[rs]);}

void upd(int rt, int l, int r, int p, int x) {
    if (l == r) {mn[rt] = make_pair(x, p); return;}
    p <= mid ? upd(ls, l, mid, p, x) : upd(rs, mid + 1, r, p, x);
    pushup(rt);
}

pii query(int rt, int l, int r, int L, int R) {
    if (L <= l && r <= R) return mn[rt];
    pii res = make_pair(inf, inf);
    if (L <= mid) res = min(res, query(ls, l, mid, L, R));
    if (R > mid) res = min(res, query(rs, mid + 1, r, L, R));
    return res;
} 

int main() {
    int n = rd();
    rep(i, 1, n) a[i] = rd();
    int q = rd();
    rep(i, 1, q) {s[i].l = rd(); s[i].r = rd(); s[i].id = i;}
    sort(s + 1, s + 1 + q, [&](Q &a, Q &b){return a.r < b.r;});
    int ptr = 1;
    rep(i, 1, n) {
        if (lst[a[i]]) upd(1, 1, n, lst[a[i]], inf);
        upd(1, 1, n, i, lst[a[i]]); lst[a[i]] = i;
        while (ptr <= q && s[ptr].r == i) {
            auto [mn, pos] = query(1, 1, n, s[ptr].l, s[ptr].r);
            if (mn < s[ptr].l) ans[s[ptr].id] = a[pos];
            ++ptr;
        }
    }
    rep(i, 1, q) printf("%d\n", ans[i]);
    return 0;
}  

/*
O(n*sqrt(n)) solution: Mo's Algorithm + Stack

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline char rdc(){
    static char buf[1<<16],*l=buf,*r=buf;
    return l==r && (r=(l=buf)+fread(buf,1,1<<16,stdin),l==r)?EOF:*l++;
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

#define N 500007

bool vis[N];

int tot, a[N], id[N], cnt[N], res[N];

stack<int> S;

inline void add(int x) {
    ++cnt[x];
    if (!vis[x] && cnt[x] == 1) {vis[x] = true; S.push(x);}
    while (!S.empty() && cnt[S.top()] != 1) {vis[S.top()] = false; S.pop();}
}

inline void del(int x) {
    --cnt[x];
    if (!vis[x] && cnt[x] == 1) {vis[x] = true; S.push(x);}
    while (!S.empty() && cnt[S.top()] != 1) {vis[S.top()] = false; S.pop();}
}

struct node {int l, r, id;} s[N];

inline bool cmp(const node &a, const node &b) {
    return id[a.l] == id[b.l] ? ((id[a.l] & 1) ? a.r < b.r : a.r > b.r) : id[a.l] < id[b.l];
}

int main() {
    int n = rd();
    rep(i, 1, n) a[i] = rd();
    for (int i = 1, lim = sqrt(n); i <= n; i += lim) id[i] = ++tot;
    rep(i, 1, n) if (!id[i]) id[i] = id[i - 1];
    int q = rd();
    rep(i, 1, q) {s[i].l = rd(); s[i].r = rd(); s[i].id = i;}
    sort(s + 1, s + 1 + q, cmp);
    int l = 1, r = 0;
    for (int i = 1; i <= q; ++i) {
        while (l < s[i].l) del(a[l++]);
        while (l > s[i].l) add(a[--l]);
        while (r > s[i].r) del(a[r--]);
        while (r < s[i].r) add(a[++r]);
        res[s[i].id] = S.empty() ? 0 : S.top();
    }
    for (int i = 1; i <= q; ++i) printf("%d\n", res[i]);
    return 0;
}  
*/