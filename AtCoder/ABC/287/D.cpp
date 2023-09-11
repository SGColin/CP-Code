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

string s, t;

bool match[N];

int main() {
    cin >> s >> t;
    int n = s.length(), m = t.length();
    auto check = [&](char a, char b) {
        return a == b || a == '?' || b == '?';
    };
    match[n - 1] = check(s[n - 1], t[m - 1]);
    for (int i = n - 2; i; --i) {
        int p = m - (n - i);
        if (p < 0) break;
        match[i] = (match[i + 1] & check(s[i], t[p]));
    }
    if (match[n - m]) {puts("Yes");}
    else puts("No");
    bool flg = true;
    for (int i = 0; i < m; ++i) {
        flg &= check(s[i], t[i]);
        if (!flg) {puts("No"); continue;}
        if (i == m - 1) {puts("Yes"); return 0;}
        if (match[n - (m - i - 1)]) puts("Yes");
        else puts("No");
    }
    return 0;
}