#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

vector<int> ans;

inline void work() {
	ans.clear();
	int n = rd();
	ans.push_back(rd());
	rep(i, 2, n) {
		int x = rd();
		if (x < ans.back()) ans.push_back(1);
		ans.push_back(x);
	}
	printf("%d\n", (int)ans.size());
	for (auto x : ans) printf("%d ", x);
	puts("");
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}