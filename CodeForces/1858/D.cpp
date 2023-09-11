#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define pb push_back
#define mp make_pair
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 3007
#define mod 998244353

char s[N];

int sum[N], suf[N][N], pre[N][N], mx[N];

void work() {
    int n = rd(), k = rd();
    scanf("%s", s + 1);
    rep(i, 1, n) sum[i] = sum[i - 1] + (s[i] == '1');
    auto sum1 = [&](int l, int r) {return sum[r] - sum[l - 1];};
    auto sum0 = [&](int l, int r) {return r - l + 1 - sum1(l, r);};
    // suf[i][j] : max connected 1s in suffix [i...n] using no more than j modifies.
    auto calcsuf1 = [&](int pos, int x) {
        int l = 0, r = n - pos + 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            sum0(pos, pos + mid - 1) <= x ? l = mid : r = mid - 1;
        }
        return l;
    };
    auto calcpre1 = [&](int pos, int x) {
        int l = 0, r = pos;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            sum0(pos - mid + 1, pos) <= x ? l = mid : r = mid - 1;
        }
        return l;
    };
    rep(i, 0, k) {
        suf[n][i] = (k ? 1 : (s[n] == '1'));
        per(j, n - 1, 1) suf[j][i] = max(suf[j + 1][i], calcsuf1(j, i));
        pre[1][i] = (k ? 1 : (s[1] == '1'));
        rep(j, 2, n) pre[j][i] = max(pre[j - 1][i], calcpre1(j, i));
    }
    rep(i, 0, n) mx[i] = -1;
    mx[0] = suf[1][k];
    rep(len, 1, n) {
        rep(i, 1, n - len + 1) {
            int need = sum1(i, i + len - 1);
            if (need > k) continue;
            int oth = 0;
            if (i > 1) oth = max(oth, pre[i - 1][k - need]);
            if (i + len - 1 < n) oth = max(oth, suf[i + len][k - need]);
            mx[len] = max(mx[len], oth);
        }
    }
    rep(a, 1, n) {
        int ans = 0;
        rep(i, 0, n) if (mx[i] != -1) ans = max(ans, a * i + mx[i]);
        printf("%d ", ans);
    }
    puts("");
}

int main() {
    for (int t = rd(); t; --t) work();
    return 0;
}