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

#define N 107

double f[N];

int c[N], sz[N], cnt0[N];

vector<int> w[N];

int main() {
    int n = rd(), tar = rd();
    for (int i = 1; i <= n; ++i) {
        c[i] = rd(); sz[i] = rd();
        for (int j = 1; j <= sz[i]; ++j) {
            int x = rd();
            if (x == 0) ++cnt0[i];
            else w[i].push_back(x);
        }
    }
    for (int i = 1; i <= tar; ++i) {
        f[i] = 1e20; 
        for (int j = 1; j <= n; ++j) {
            double nw = c[j] * sz[j];
            for (auto x : w[j]) nw += f[max(0, i - x)];
            nw = nw / (sz[j] - cnt0[j]);
            f[i] = min(f[i], nw);
        }
    }
    printf("%.15lf\n", f[tar]);
    return 0;
}