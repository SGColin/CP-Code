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

#define N 200007

char s[N], ans[N];

vector<int> pos[N];

int main() {
    int n = rd(), m = rd();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) pos[rd()].push_back(i);
    for (int i = 1; i <= m; ++i) {
        int lst = pos[i].back();
        for (auto x : pos[i]) {ans[x] = s[lst]; lst = x;}
    }
    puts(ans + 1);
    return 0;
}