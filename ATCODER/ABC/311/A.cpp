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

bool vis[3];

int main() {
    int n = rd();
    for (int i = 1; i <= n; ++i) {
        char c = getchar();
        while (!isalpha(c)) c = getchar();
        vis[c - 'A'] = true;
        if (vis[0] && vis[1] && vis[2]) {
            printf("%d\n", i);
            return 0;
        }
    }
    return 0;
}