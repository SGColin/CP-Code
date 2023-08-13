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

int c[101];

vector<int> id[101], ans;

int main() {
    int n = rd();
    for (int i = 1; i <= n; ++i) {
        c[i] = rd();
        for (int j = 1; j <= c[i]; ++j) id[rd()].push_back(i);
    } 
    int x = rd();
    if (id[x].empty()) {puts("0"); return 0;}
    int mn = c[id[x][0]];
    for (auto x : id[x]) {
        if (c[x] < mn) {mn = c[x]; ans.clear(); ans.push_back(x);}
        else if (c[x] == mn) ans.push_back(x);
    }
    printf("%d\n", (int)ans.size());
    for (auto x : ans) printf("%d ", x);
    return 0;
}