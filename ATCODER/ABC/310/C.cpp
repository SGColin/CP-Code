#include <bits/stdc++.h>
using namespace std;

map<string, bool> vis;

int main() {
	int n; cin >> n;
	int ans = 0;
	string s;
	for (int i = 1; i <= n; ++i) {
		cin >> s;
		bool fl = true;
		if (vis[s]) fl = false;
		reverse(s.begin(), s.end());
		if (vis[s]) fl = false;
		vis[s] = true;
		reverse(s.begin(), s.end());
		vis[s] = true;
		ans += fl;
	}
	printf("%d\n", ans);
	return 0;
}