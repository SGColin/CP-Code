#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	string s;
	cin >> s >> n;
	reverse(s.begin(), s.end());
	int len = s.size();
	ll nw = 0;
	for (int i = 0; i < len; ++i)
		if (s[i] == '1') nw += (1ll << i);
	if (nw > n) {cout << "-1" << endl; return 0;}
	for (int i = len - 1; ~i; --i)
		if (s[i] == '?' && nw + (1ll << i) <= n) nw += (1ll << i); 
	cout << nw << endl;
 	return 0;
}