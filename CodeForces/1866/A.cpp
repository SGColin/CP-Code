#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int main() {
	int n, ans = 1e9; 
	cin >> n;
	rep(i, 1, n) {
		int x; cin >> x;
		ans = min(ans, abs(x));
	}
	cout << ans;
	return 0;
}