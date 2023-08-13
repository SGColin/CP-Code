#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	int x; cin >> x;
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		int w; cin >> w;
		if (w >= x) ans = max(ans, w - x + 1);
	}
	printf("%d\n", ans);
	return 0;
}