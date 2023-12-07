#include <bits/stdc++.h>
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

#define N 500007
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

stack<int> s;

vector<int> q[N];

int f[N], a[N], c[N];

inline int lowbit(int x) {return x & (-x);}
 
inline void add(int p, int w) {
	for (; p < N; p += lowbit(p)) c[p] = max(c[p], w);
}
 
inline int qmx(int p) {
	int res = 0;
	for (; p; p -= lowbit(p)) res = max(res, c[p]);
	return res;
}

inline void work() {
	int n = rd();
	rep(i, 1, n) {
		a[i] = rd(); f[i] = c[i] = 0; q[i].clear();
		while (!s.empty() && a[s.top()] <= a[i]) s.pop();
		if (!s.empty()) q[s.top()].pb(i);
		s.push(i);
	}
	while (!s.empty()) s.pop();
	int ans = 0;
	rep(i, 1, n) {
		f[i] = max(f[i], qmx(a[i]) + 1);
		add(a[i], f[i]); ans = max(ans, f[i]);
		for (auto x : q[i]) f[x] = max(f[x], qmx(a[x]) + 2);
	}
	printf("%d\n", ans);
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}