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

#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

#define N 27

char s[N][N];

inline void work() {
	int n = rd(), m = rd();
	rep(i, 1, n) rep(j, 1, m) {
		char c = getchar();
		while (!isalpha(c)) c = getchar();
		s[i][j] = c;
	}
	string tar = "vika";
	int pos = 0;
	rep(j, 1, m) {
		rep(i, 1, n) if (s[i][j] == tar[pos]) {++pos; break;}
		if (pos == 4) {puts("YES"); return;}
	}
	puts("NO");
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}