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

#define N 300007
#define lowbit(x) ((x) & (-(x)))
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

int c[N], col[N];

vector<int> S, s[N];

void add(int p) {for (; p < N; p += lowbit(p)) ++c[p];}
void del(int p) {for (; p < N; p += lowbit(p)) --c[p];}
int sum(int p) {int ans = 0; for (; p; p -= lowbit(p)) ans += c[p]; return ans;}

int main() {
	int n = rd();
	rep(i, 1, n) col[i] = rd();
	rep(i, 1, n) {
		int x = rd();
		S.push_back(x);
		s[col[i]].push_back(x);
	}
	long long ans = 0;
	reverse(all(S));
	for (auto x : S) {ans += sum(x - 1); add(x);}
	for (auto x : S) del(x);
	rep(i, 1, n) {
		reverse(all(s[i]));
		for (auto x : s[i]) {ans -= sum(x - 1); add(x);}
		for (auto x : s[i]) del(x);
	}
	printf("%lld\n", ans);
	return 0;
}