#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll rd() {
    ll x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

bool vis[107];

int main() {
    int n = rd(), m = rd();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c = getchar();
            while (!isalpha(c)) c = getchar();
            if (c == 'x') vis[j] = true;
        }
    }
    int ans = 0, len = 0;
    for (int i = 1; i <= m; ++i) {
        if (!vis[i]) ++len;
        else len = 0;
        ans = max(ans, len);
    }
    printf("%d\n", ans);
    return 0;
}