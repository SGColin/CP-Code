#include <bits/stdc++.h>
using namespace std;

map<char, int> cnt;

int main() {
	string s; cin >> s;
	for (auto x : s) ++cnt[x];
	puts(cnt['D'] > 2 ? "DRX" : "T1");
	return 0;
}