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

#define N 200007

int a[N];

int main() {
	int n = rd();
	ll sum = 0;
	for (int i = 1; i <= n; ++i) sum += (a[i] = rd());
	sum /= n;
	ll add = 0, del = 0;
	for (int i = 1; i <= n; ++i)
		if (a[i] <= sum) add += sum - a[i];
		else del += a[i] - sum - 1;
	printf("%lld\n", max(add, del));
	return 0;
}