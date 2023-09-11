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

#define N 1000007

int cnt[N], id[N], pos[N];

int main() {
    int n = rd(); 
    int m = n * 3;
    rep(i, 1, m) {
        int x = rd();
        ++cnt[x];
        if (cnt[x] == 2) pos[x] = i;
    }
    rep(i, 1, n) id[i] = i;
    sort(id + 1, id + 1 + n, [&](int a, int b) {return pos[a] < pos[b];});
    rep(i, 1, n) printf("%d ", id[i]);
    return 0;
}
