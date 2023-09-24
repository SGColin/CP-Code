#include <bits/stdc++.h>
using namespace std;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define N 1000007
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define per(i, a, b) for(int i = (a); i >= (b); --i)

char s[N], t[N];

int nxt[N];

int main() {
	scanf("%s", s + 1); int n = strlen(s + 1);
	scanf("%s", t + 1); int m = strlen(t + 1);
	nxt[1] = 0;
	rep(i, 2, m) {
		
	}

	return 0;
}