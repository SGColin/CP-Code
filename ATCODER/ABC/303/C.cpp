#include <bits/stdc++.h>
using namespace std;

#define N 200007

char s[N];

set<pair<int, int>> pos;

int main() {
	int n, m, h, k; 
	cin >> n >> m >> h >> k;
	scanf("%s", s + 1);
	for (int i = 1; i <= m; ++i) {
		int x, y; cin >> x >> y; 
		pos.insert(make_pair(x, y));
	}
	int x = 0, y = 0;
	for (int i = 1; i <= n; ++i) {
		--h;
		if (h < 0) {puts("No"); return 0;}
		if (s[i] == 'L') --x;
		if (s[i] == 'R') ++x;
		if (s[i] == 'U') ++y;
		if (s[i] == 'D') --y;
		if (h < k) {
			if (pos.find(make_pair(x, y)) != pos.end()) {
				h = k; pos.erase(make_pair(x, y));
			} 
		}
	}
	puts("Yes");
	return 0;
}