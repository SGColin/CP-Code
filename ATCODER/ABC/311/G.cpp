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

#define N 307
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i) 

ll ans = 0;

int a[N][N], mn[N], sum[N], l[N], r[N], psum[N];

int main() { 
    int n = rd(), m = rd();
    rep(i, 1, n) rep(j, 1, m) a[i][j] = rd();
    rep(u, 1, n) {
    	rep(i, 1, m) sum[i] = 0, mn[i] = N;
    	rep(d, u, n) {
    		rep(i, 1, m) {
    			sum[i] += a[d][i];
    			psum[i] = psum[i - 1] + sum[i];
    			mn[i] = min(mn[i], a[d][i]);
    		}
    		stack<int> s;
    		rep(i, 1, m) {
    			while (!s.empty() && mn[s.top()] > mn[i]) {r[s.top()] = i - 1; s.pop();}
    			l[i] = (s.empty() ? 1 : s.top() + 1);
    			s.push(i); 
    		}
    		while (!s.empty()) {r[s.top()] = m; s.pop();}
    		rep(i, 1, m) ans = max(ans, 1ll * mn[i] * (psum[r[i]] - psum[l[i] - 1]));
    	}
    }
    printf("%lld\n", ans);
    return 0;
}