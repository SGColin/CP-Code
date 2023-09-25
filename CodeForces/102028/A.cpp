#include <bits/stdc++.h>
using namespace std;

inline void work() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int ans = (a > 0) + (b > 0) + (c > 0) + (d > 0);
	if (ans == 0) cout << "Typically Otaku" << endl;
	if (ans == 1) cout << "Eye-opener" << endl;
	if (ans == 2) cout << "Young Traveller" << endl;
	if (ans == 3) cout << "Excellent Traveller" << endl;
	if (ans == 4) cout << "Contemporary Xu Xiake" << endl;
}

int main() {
	int t; cin >> t;
	while (t--) work();
	return 0;
}