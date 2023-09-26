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
#define pb push_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

// 0 : ll -> 2
// 1 : lw -> 1
// 2 : ww -> 0

int main() {
	int n = rd();
	bool old[3] = {0, 0, 0};
	int x = rd();
	if (x > 1) {puts("NO"); return 0;}
	if (x) old[1] = true;
	else old[0] = old[2] = true;
	rep(i, 2, n - 1) {
		x = rd();
		if (x > 2) {puts("NO"); return 0;}
		bool nw[3] = {0, 0, 0};
		if (x == 0) {
			if (old[0] || old[2]) nw[0] = nw[2] = true;
			if (old[1]) nw[1] = true;
		} else if (x == 1) {
			if (old[1]) nw[0] = nw[2] = true;
			if (old[0] || old[2]) nw[1] = true;
		} else {
			if (old[1]) nw[1] = true;
		}
		rep(j, 0, 2) old[j] = nw[j];
	}
	x = rd();
	if (x > 1) {puts("NO"); return 0;}
	if (x == 1){
		if (old[1]) puts("YES");
		else puts("NO");
	} else {
		if (old[0] || old[2]) puts("YES");
		else puts("NO");
	}
	return 0;
}
