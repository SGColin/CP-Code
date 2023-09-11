#include <bits/stdc++.h>
using namespace std;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

typedef long long ll;
typedef long double ld;
typedef pair<int, int>  pii;
typedef tuple<int, int, int> tii;

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

#define N 107

bool A[N][N];

int ans[N];

int main() {
    int H = rd(), W = rd();
    rep(i, 1, H) rep(j, 1, W) {
        char c = getchar();
        while (c != '.' && c != '#') c = getchar();
        A[i][j] = (c == '#');
    }
    rep(x, 1, H) rep(y, 1, W) {
        if (A[x][y] && A[x - 1][y - 1] && A[x + 1][y + 1] && A[x - 1][y + 1] && A[x + 1][y - 1]) {
            int t = 2;
            while (A[x - t][y - t] && A[x + t][y + t] && A[x - t][y + t] && A[x + t][y - t]) ++t;
            --t;
            ++ans[t];
        }
    }
    rep(i, 1, min(H, W)) printf("%d ", ans[i]);
    return 0;
}