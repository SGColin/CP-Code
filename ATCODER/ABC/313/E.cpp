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

#define N 1000007
#define mod 998244353

char s[N];

int main() {
	int n = rd();
	scanf("%s", s + 1);
	for (int i = 2; i <= n; ++i) 
		if (s[i] != '1' && s[i - 1] != '1') {puts("-1"); return 0;}
	int ans = 0, nw = 0;
	for (int i = n; i; --i) 
		if (s[i] == '1') nw = (nw + 1) % mod; 
		else {
			ans = (ans + nw + 1) % mod;
			nw = 1ll * ans * (s[i] - '1') % mod;
		}
	if (s[1] == '1') ans = (ans + nw) % mod;
	ans = (ans + mod - 1) % mod;
	printf("%d\n", ans);
	return 0;
}