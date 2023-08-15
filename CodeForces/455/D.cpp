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

#define M 321
#define N 100007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int bel[N], cnt[M][N];

deque<int> s[M], tmp;

int main() {
    int n = rd();
    int m = sqrt(n);
    rep(i, 0, n - 1) {
        int x = rd();
        bel[i] = i / m;
        ++cnt[bel[i]][x];
        s[bel[i]].push_back(x);
    }

	auto pop_back = [&](int id) {
        int x = s[id].back(); s[id].pop_back(); 
        --cnt[id][x]; return x;
    };
    auto push_front = [&](int id, int x) {
    	s[id].push_front(x); ++cnt[id][x];
    };

    int q = rd(), ans = 0;
    while (q--) {
        int op = rd();
        int l = (rd() + ans - 1) % n;
        int r = (rd() + ans - 1) % n;
        if (l > r) swap(l, r);
        int lid = bel[l], rid = bel[r];
       	fflush(stdout);
        if (op == 1) {
            if (lid == rid) {
                int x = s[lid][r % m];
                s[lid].erase(s[lid].begin() + r % m);
                s[lid].insert(s[lid].begin() + l % m, x);
            } else {
                int pas = s[rid][r % m]; 
                --cnt[rid][pas]; s[rid].erase(s[rid].begin() + r % m);
                ++cnt[lid][pas]; s[lid].insert(s[lid].begin() + l % m, pas); 
                pas = pop_back(lid);
                rep(i, lid + 1, rid - 1) {push_front(i, pas); pas = pop_back(i);}
                push_front(rid, pas);
            }
        } else {
            int x = (rd() + ans - 1) % n + 1;
            ans = 0; l %= m; r %= m;
            if (lid == rid) {
                rep(i, l, r) ans += (s[lid][i] == x);
            } else {
                rep(i, l, m - 1) ans += (s[lid][i] == x);
                rep(i, 0, r) ans += (s[rid][i] == x);
                rep(i, lid + 1, rid - 1) ans += cnt[i][x];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}