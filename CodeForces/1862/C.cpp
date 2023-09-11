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

#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 200007

int a[N];

inline void work() {
	int n = rd();
	rep(i, 1, n) a[i] = rd();
	int ptr = n;
	rep(i, 1, n) {
		while (ptr && a[ptr] < i) --ptr;
		if (a[i] != ptr) {puts("NO"); return;}
	}
	puts("YES");
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}