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

#define N 500007

set<pii> b, s;

int val[N];

ll sum;

int main() {
    int n = rd(), k = rd(), q = rd();
    if (k == n) {
        rep(i, 1, q) {
            int p = rd(), w = rd();
            sum = sum - val[p] + w;
            val[p] = w;
            printf("%lld\n", sum);
        }
        return 0;
    }
    rep(i, 1, k) b.insert(mp(0, n - i + 1));
    rep(i, k + 1, n) s.insert(mp(0, n - i + 1));
    rep(t, 1, q) {
        int p = rd(), w = rd();
        pii old = mp(val[p], p);
        pii now = mp(w, p);
        if (*b.lower_bound(old) == old) {
            b.erase(old); b.insert(now); sum = sum - val[p] + w;
        } else {s.erase(old); s.insert(now);}
        while (*b.begin() < *--s.end()) {
            auto bs = *b.begin(); b.erase(bs);
            auto sb = *--s.end(); s.erase(sb);
            b.insert(sb); s.insert(bs);
            sum = sum - bs.fr + sb.fr;
        }
        val[p] = w;
        printf("%lld\n", sum);
    }
    return 0;
}
