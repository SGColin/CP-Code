#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd() {
    int x = 0; 
    bool f = 0; 
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 50007

char s[N];

priority_queue<pii, vector<pii>, greater<pii>> q;

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    if (n & 1) {puts("-1"); return 0;}
    int cnt = 0;
    ll ans = 0;
    rep(i, 1, n) {
        if (s[i] == '(') ++cnt;
        else if (s[i] == ')') --cnt;
        else {
            int a = rd(), b = rd();
            s[i] = ')'; --cnt; ans += b; 
            q.push(make_pair(a - b, i));
        }
        while (cnt < 0) {
            if (q.empty()) {puts("-1"); return 0;}
            auto [w, pos] = q.top(); q.pop();
            cnt += 2; s[pos] = '('; ans += w; 
        } 
    }
    if (cnt) {puts("-1"); return 0;}
    printf("%lld\n", ans);
    puts(s + 1);
    return 0;
}