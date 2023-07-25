#include <bits/stdc++.h>
using namespace std;

char s[1000007];

int main() {
	int n; 
	scanf("%d", &n);
	long long ans = 0;
	scanf("%s", s + 1);
	for (int i = 1, len = 0; i <= n; ++i) {
		if (s[i] == '0') {ans += i - 1; len = 0;}
		else {
			++len;
			if (len == i) ans += (len + 1) / 2;
			else if (len & 1) ans += 1 + (len + 1) / 2;
			else ans += i - len - 1 + len / 2;
		}
	}
	printf("%lld\n", ans);
	return 0;
}