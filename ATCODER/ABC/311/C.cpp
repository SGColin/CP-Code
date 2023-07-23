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

#define N 200007

bool vis[N];

int a[N];

int main() {
    int n = rd();
    for (int i = 1; i <= n; ++i) a[i] = rd();
    int nw = 1;
    while (!vis[nw]) {vis[nw] = true; nw = a[nw];}
    vector<int> ans;
    ans.push_back(nw);
    int st = a[nw];
    while (st != nw) {
        ans.push_back(st);
        st = a[st];
    }
    printf("%d\n", (int)ans.size());
    for (auto x : ans) printf("%d ", x);
    return 0;
}