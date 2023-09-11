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

#define pb push_back
#define mp make_pair
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007
#define mod 998244353

void work() {
    int a = rd(), b = rd(), c = rd();
    a += c - c / 2;
    b += c / 2;
    puts(a > b ? "First" : "Second");
}

int main() {
    for (int t = rd(); t; --t) work();
    return 0;
}