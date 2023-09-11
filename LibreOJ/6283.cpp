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

#define M 321
#define N 100007
#define mod 10007

inline int mo(int x) {return x >= mod ? x - mod : x;}

int mul[M], add[M], L[M], R[M], a[N];

int main() {
	int n = rd();
	int len = sqrt(n);
	rep(i, 0, n - 1) {
		a[i] = rd();
		if (i % len == 0) L[i / len] = i;
		R[i / len] = i;
	}
	per(i, n / len, 0) mul[i] = 1;
	rep(q, 1, n) {
		int op = rd(), l = rd() - 1, r = rd() - 1, c = rd() % mod;
		int idl = l / len, idr = r / len;

		auto rebuild = [&](int x) {
			rep(i, L[x], R[x]) a[i] = (a[i] * mul[x] + add[x]) % mod;
			mul[x] = 1; add[x] = 0;
		};

		auto Add = [&](int l, int r, int c) {
			if (idl == idr) {
				rebuild(idl);
				rep(i, l, r) a[i] = mo(a[i] + c);
			} else {
				rebuild(idl); rebuild(idr);
				per(i, R[idl], l) a[i] = mo(a[i] + c);
				rep(i, L[idr], r) a[i] = mo(a[i] + c);
				rep(i, idl + 1, idr - 1) add[i] = mo(add[i] + c);
			}
		};

		auto Mul = [&](int l, int r, int c) {
			if (idl == idr) {
				rebuild(idl);
				rep(i, l, r) a[i] = a[i] * c % mod;
			} else {
				rebuild(idl); rebuild(idr);
				per(i, R[idl], l) a[i] = a[i] * c % mod;
				rep(i, L[idr], r) a[i] = a[i] * c % mod;
				rep(i, idl + 1, idr - 1) {
					mul[i] = mul[i] * c % mod;
					add[i] = add[i] * c % mod;
				}
			}
		};

		if (op == 0) Add(l, r, c);
		else if (op == 1) Mul(l, r, c);
		else printf("%d\n", (a[r] * mul[idr] + add[idr]) % mod);
	}
	return 0;
}