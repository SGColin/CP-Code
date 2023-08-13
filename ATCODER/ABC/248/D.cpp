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
#define all(s) (s).begin(), (s).end()

vector<int> s[N];

int main() {
    int n = rd();
    for (int i = 1; i <= n; ++i) s[rd()].push_back(i);
    int q = rd();
    for (int i = 1; i <= q; ++i) {
        int l = rd(), r = rd(), x = rd();
        printf("%d\n", (int)(upper_bound(all(s[x]), r) - lower_bound(all(s[x]), l)));
    }
    return 0;
}