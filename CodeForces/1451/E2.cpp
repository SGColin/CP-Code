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

#define N 70001
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

int a[N], id[N];

int main() {
	int n = rd();
	bool fl = false;
	rep(i, 2, n) {
		printf("XOR %d %d\n", 1, i); fflush(stdout);
		a[i] = rd(); 
		if (id[a[i]] && !fl) {
			fl = true;
			printf("AND %d %d\n", i, id[a[i]]); fflush(stdout);
			a[1] = rd() ^ a[i];
		}
		id[a[i]] = i;
	}
	if (!fl) { 
		if (id[0]) {
			printf("AND %d %d\n", 1, id[0]); fflush(stdout); a[1] = rd();
		} else {
			printf("AND %d %d\n", 1, id[1]); fflush(stdout); a[1] |= rd();
			printf("AND %d %d\n", 1, id[n / 2]); fflush(stdout); a[1] |= rd();
		}
	}
	printf("! %d", a[1]);
	rep(i, 2, n) printf(" %d", a[1] ^ a[i]);
	puts(""); fflush(stdout); 
	return 0;
}