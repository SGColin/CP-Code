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

void print(__int128 x, bool fl = false) {
    if (!x) {
        if (fl) putchar('0');
        return;
    }
    print(x / 10);
    putchar('0' + x % 10);
}

int main() {
    __int128 ans = 0, bs = 1;
    for (int i = 0; i < 64; ++i) {
        ans += bs * rd();
        bs = bs * 2;
    }
    print(ans, true);
    return 0;
}
