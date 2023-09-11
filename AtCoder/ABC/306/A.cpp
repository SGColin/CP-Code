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

int main() {
    int n; cin >> n;
    string s; cin >> s;
    for (auto x : s) {
        putchar(x); putchar(x);
    }
    return 0;
}
