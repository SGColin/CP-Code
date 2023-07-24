// dp[i][0/1]:前i个字母，caps lock状态off/on，最小花费时间

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 300007
ll dp[N][2];

int main() {
	int x,y,z; string s;
	cin >> x >> y >> z >> s;
	int mn = min(x,y) + z, len = (int)s.length();
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0]=0;
	for (int i = 0; i < len; ++i) {
		if (s[i] == 'a') {
			dp[i + 1][0]=min(dp[i][0]+x,dp[i][1]+mn);
			dp[i + 1][1]=min(dp[i][1]+y,dp[i][0]+mn);
		} else {
			dp[i + 1][0]=min(dp[i][0]+y,dp[i][1]+mn);
			dp[i + 1][1]=min(dp[i][1]+x,dp[i][0]+mn);
		}
	}
	printf("%lld\n", min(dp[len][0],dp[len][1]));
}