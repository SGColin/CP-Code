#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

#define M 230
#define N 50007

ll sum[M], tag[M], L[M], R[M], a[N];

int main() {
	int n = rd();
	int len = sqrt(n);
	rep(i, 0, n - 1) {
		sum[i / len] += (a[i] = rd());
		if (i % len == 0) L[i / len] = i;
		R[i / len] = i;
	}
	rep(q, 1, n) {
		int op = rd(), l = rd() - 1, r = rd() - 1;
		ll c = rd();
		int bell = l / len, belr = r / len;
		if (op) {
			++c;
			ll ans = 0;
			if (bell == belr) {
				rep(i, l, r) ans = (ans + a[i] + tag[bell]) % c;
			} else {
				per(i, R[bell], l) ans = (ans + a[i] + tag[bell]) % c;
				rep(i, L[belr], r) ans = (ans + a[i] + tag[belr]) % c;
				rep(i, bell + 1, belr - 1) ans = (ans + sum[i]) % c;
			}
			printf("%lld\n", ans);
		} else {
			if (bell == belr) {
				sum[bell] += c * (r - l + 1);
				rep(i, l, r) a[i] += c;
			} else {
				per(i, R[bell], l) {sum[bell] += c; a[i] += c;}
				rep(i, L[belr], r) {sum[belr] += c; a[i] += c;}
				rep(i, bell + 1, belr - 1) {sum[i] += len * c; tag[i] += c;}
			}
		}
	}
	return 0;
}