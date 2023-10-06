#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd(){
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

map<int, int> f;

inline void work() {
	int n = rd(); f.clear();
	rep(i, 1, n) {
		int b = rd(), d = rd();
		f[d] = max(f[d], b);
	}
	int ans = 0;
	rep(i, 1, 10) {
		if (!f[i]) {puts("MOREPROBLEMS"); return;}
		ans += f[i];
	}
	printf("%d\n", ans);
}

int main() {
	for (int t = rd(); t; --t) work();
	return 0;
}
