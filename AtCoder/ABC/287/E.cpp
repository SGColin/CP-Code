#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define T int 
typedef pair<T, T> pii;
typedef tuple<T, T, T> tii;

#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back

#define lowbit(x)    ((x) & -(x))
#define all(x)       (x).begin(), (x).end()
#define rep(i, x, y) for (int i = (x); i <= (y); ++i)
#define per(i, x, y) for (int i = (x); i >= (y); --i)

inline T rd() {
    T x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define N 300007

struct node {
    int cnt, son[26];
} c[500007];

int tot;

inline void insert(string &s) {
    int rt = 0;
    for (auto x : s) {
        x -= 'a';
        if (!c[rt].son[x]) c[rt].son[x] = ++tot;
        rt = c[rt].son[x];
        ++c[rt].cnt;
    }
}

inline int calc(string &s) {
    int ans = 0, rt = 0;
    for (auto x : s) {
        x -= 'a';
        rt = c[rt].son[x];
        if (c[rt].cnt == 1) return ans;
        ++ans;
    }
    return ans;
}

string str;

vector<string> s;

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> str; s.pb(str); insert(str);
    }
    for (auto &st : s) {
        printf("%d\n", calc(st));
    }
    return 0;
}