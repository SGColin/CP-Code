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

int main() {
	int n = rd(), h = rd(), x = rd();
	rep(i, 1, n) {
		if (h + rd() >= x) {
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}