#include <bits/stdc++.h>
using namespace std;

string s[3] = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};

map<char, bool> f, vis;

int main() {
	int cnt = 0;
	string st;
	for (int i = 0; i < 3; ++i) {
		cin >> st;
		for (int j = 0; j < st.size(); ++j)
			if (s[i][j] != st[j]) {f[s[i][j]] = true; ++cnt;}
	}
	int n; cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> st;
		vis.clear();
		bool fl = false;
		for (auto x : st) {
			if (!f[x]) {puts("IMPOSSIBLE"); fl = true; break;}
			vis[x] = true;
		}
		if (!fl) puts(vis.size() == cnt ? "POSSIBLE" : "IMPOSSIBLE");
	}
	return 0;
}