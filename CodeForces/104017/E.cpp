#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

inline int rd(){
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

string a, b;

int main() {
	auto deal = [&](string s) {
		int cntb = 0;
		vector<char> res; 
		for (auto x : s)
			if (x == 'B') ++cntb;
			else {
				if (!res.empty() && res.back() == x) res.pop_back();
				else res.push_back(x);
			}
		return make_pair(cntb % 2, res);
	};
	per(t, rd(), 1) {
		cin >> a >> b;
		puts(deal(a) == deal(b) ? "YES" : "NO");
	}
	return 0;
}