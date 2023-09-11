#include <bits/stdc++.h>
using namespace std;

inline char rdc(){
	static char buf[1 << 16], *l = buf, *r = buf;
	return l == r && (r = (l = buf) + fread(buf, 1, 1 << 16, stdin), l == r) ? EOF : *l++;
}

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = rdc();
	for (; !isdigit(c); c = rdc()) f |= (c == '-');
	for (; isdigit(c); c = rdc()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 507

int dp[N][N], pre[N][N];

int main() {
	vector<int> A, B;
	int n = rd(); A.push_back(0);
	rep(i, 1, n) A.push_back(rd());
	int m = rd(); B.push_back(0);
	rep(i, 1, m) B.push_back(rd());
	rep(i, 1, n) {
		int mx = 0, pos = 0;
		rep(j, 1, m) {
			if (A[i] == B[j]) {dp[i][j] = mx + 1; pre[i][j] = pos;}
			else {dp[i][j] = dp[i - 1][j]; pre[i][j] = j;}
			if (B[j] < A[i] && mx < dp[i - 1][j]) {mx = dp[i - 1][j]; pos = j;}
		}
	}
	int mxp = 0;
	rep(j, 1, m) if (dp[n][j] > dp[n][mxp]) mxp = j;
	vector<int> ans;
	for (int nw = n; nw; --nw) {
		int nxtp = pre[nw][mxp];
		if (dp[nw][mxp] > dp[nw - 1][nxtp]) ans.push_back(B[mxp]);
		mxp = nxtp;
	}
	reverse(ans.begin(), ans.end());
	printf("%d\n", (int)ans.size());
	for (auto x : ans) printf("%d ", x);
	return 0;
}