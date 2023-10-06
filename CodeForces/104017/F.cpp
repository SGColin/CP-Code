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

inline void work() {
	int n = rd(), m = rd();
	int a = 0, b = 0;
	rep(i, 1, m) {a = max(a, rd()); b = max(b, rd());}
	if (a + b > n) {puts("IMPOSSIBLE"); return;}
	rep(i, 1, a) putchar('R');
	rep(i, a + 1, n) putchar('W');
	puts("");
}

int main() {
	for (int t = rd(); t; --t) work();
	return 0;
}
