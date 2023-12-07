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

#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

#define N 200007

int a[N];

inline void work() {
	int n = rd(), k = rd(), m = rd();
	rep(i, 1, m) a[i] = rd();
	if ((n - m) % (k - 1)) {puts("NO"); return;}
	rep(i, 1, m) {
		int pre = a[i] - i;
		int suf = n - a[i] - (m - i);
		if (pre >= k / 2 && suf >= k / 2) {puts("YES"); return;}
	}
	puts("NO");
}

int main() {
	int t = rd();
	while(t--) work();
	return 0;
}