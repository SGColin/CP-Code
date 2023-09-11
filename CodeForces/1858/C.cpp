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

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 100007

bool vis[N];

void work() {
    int n = rd();
    rep(i, 1, n) vis[i] = false;
    int ptr = 1;
    rep(ptr, 1, n) {
        if (vis[ptr]) continue;
        int nw = ptr;
        while (nw <= n) {
            printf("%d ", nw);
            vis[nw] = true;
            nw <<= 1;
        }
    }
    puts("");
}

int main() {
    for (int t = rd(); t; --t) work();
    return 0;
}