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

#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

map<string, int> f;

int main() {
	int n = rd();
	rep(i, 0, n) {
		int ans = -1;
		rep(j, 1, 9)
			if (n % j == 0 && i % (n / j) == 0) {ans = j; break;}
		putchar(ans > 0 ? ans + '0' : '-');
	}

	return 0;
}