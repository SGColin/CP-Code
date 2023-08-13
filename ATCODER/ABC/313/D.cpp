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

#define N 1007

int ans[N], a[N];

int main() {
	int n = rd(), k = rd();

	auto ask = [&](int p) {
		printf("?");
		for (int j = 0; j < k; ++j) printf(" %d", p + j > k + 1 ? p + j - k - 1 : p + j);
		puts("");
		fflush(stdout);
		ans[p] = rd();
	};

	auto ask2 = [&](int p) {
		printf("? %d", p);
		for (int j = 1; j < k; ++j) printf(" %d", j);
		puts("");
		fflush(stdout);
		ans[p] = rd();
	};

	auto answer = [&]() {
		printf("!");
		for (int i = 1; i <= n; ++i) printf(" %d", a[i]);
		puts("");
		fflush(stdout);
	};

	int sum = 0;
	for (int i = 1; i <= k + 1; ++i) {ask(i); sum ^= ans[i];}
	for (int i = 1; i <= k; ++i) a[i] = sum ^ ans[i + 1];
	a[k + 1] = sum ^ ans[1];
	
	sum = 0;
	for (int i = 1; i < k; ++i) sum ^= a[i];
	for (int i = k + 2; i <= n; ++i) {ask2(i); a[i] = ans[i] ^ sum;}

	answer();
	
	return 0;
}