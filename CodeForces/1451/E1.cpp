#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

vector<int> ans;

int main() {
	int n = rd();
	
	int x12, a12, x23, a23, a13, x13;
	puts("XOR 1 2"); fflush(stdout); x12 = rd();
	puts("AND 1 2"); fflush(stdout); a12 = rd();
	puts("XOR 2 3"); fflush(stdout); x23 = rd();
	puts("AND 2 3"); fflush(stdout); a23 = rd();
	puts("AND 1 3"); fflush(stdout); a13 = rd();
	x13 = x12 ^ x23;
	int s12 = x12 + a12 * 2;
	int s23 = x23 + a23 * 2;
	int s13 = x13 + a13 * 2;
	int tot = (s12 + s23 + s13) / 2;
	ans.push_back(tot - s23);
	ans.push_back(tot - s13);
	ans.push_back(tot - s12);
	int nw = tot - s12;
	rep(i, 4, n) {
		printf("XOR %d %d\n", i - 1, i); fflush(stdout);
		nw = nw ^ rd(); ans.push_back(nw);
	}
	printf("!");
	for (auto x : ans) printf(" %d", x);
	puts(""); fflush(stdout);
	return 0;
}