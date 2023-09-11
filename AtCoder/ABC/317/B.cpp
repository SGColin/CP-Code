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

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 1007
#define mp make_pair
#define eb emplace_back
#define lb lower_bound
#define all(s) (s).begin(), (s).end()

int a[N];

int main() {
	int n = rd();
	rep(i, 1, n) a[i] = rd();
	sort(a + 1, a + 1 + n);
	rep(i, 2, n)
		if (a[i] != a[i - 1] + 1) {
			printf("%d\n", a[i - 1] + 1);
			return 0;
		}
	return 0;
}