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

char A[N][N], B[N][N];

int main() {
    int H = rd(), W = rd();
    rep(i, 1, H) rep(j, 1, W) {
        char c = getchar();
        while (c != '.' && c != '#') c = getchar();
        A[i][j] = c;
    }
    rep(i, 1, H) rep(j, 1, W) {
        char c = getchar();
        while (c != '.' && c != '#') c = getchar();
        B[i][j] = B[i][j + W] = B[i + H][j] = B[i + H][j + W] = c;
    }
    rep(x, 0, H - 1) rep(y, 0, W - 1) {
        bool fl = true;
        rep(i, 1, H) rep(j, 1, W) if (A[i][j] != B[i + x][j + y]) fl = false;
        if (fl) {puts("Yes"); return 0;}
    }
    puts("No");
    return 0;
}