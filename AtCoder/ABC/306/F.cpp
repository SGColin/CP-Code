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
#define all(x) (x).begin(), (x).end()
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

#define N 10007
#define M 1000007

vector<int> a[N], s;

int c[M];

inline void add(int p) {
    // printf("add %d\n", p);
    for (; p < M; p += lowbit(p)) ++c[p];
}

inline int sum(int p) {
    // printf("sum %d\n", p);
    int ans = 0;
    for (; p; p -= lowbit(p)) ans += c[p];
    return ans;
}

int main() {
    int n = rd(), m = rd();
    rep(i, 1, n)
        rep(j, 1, m) {int x = rd(); a[i].pb(x); s.pb(x); sort(all(a[i]));}
    sort(all(s));
    s.erase(unique(all(s)), s.end());
    auto trans = [&](int x) {
        return lower_bound(all(s), x) - s.begin() + 1;
    };
    ll ans = 0;
    per(i, n, 1) {
        for (auto x : a[i]) ans += sum(trans(x));
        int cnt = 0;
        for (auto x : a[i]) {
            add(trans(x)); ++cnt;
            ans += 1ll * (n - i) * cnt;
        }
        //printf("%lld\n", ans);
    }
    printf("%lld\n", ans);
    return 0;
}
