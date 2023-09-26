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

#define N 1000007
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int a[N];

pii A[N], B[N];

ll ans = 0;

void divide(int l, int r, int ql, int qr) {
	if (l > r) return;
	int mid = (l + r) / 2;
	ll tmp = 0, ptr = ql;
	for (int i = ql; i <= qr && A[i].first < B[mid].first; ++i){
		ll nw = 1ll * (A[i].second + B[mid].second) * (B[mid].first - A[i].first);
		if (nw > tmp) {tmp = nw; ptr = i;}
	}
	ans = max(ans, tmp);
	divide(l, mid - 1, ql, ptr);
	divide(mid + 1, r, ptr, qr);
}

int main() {
	int n = rd(), tota, totb;
	rep(i, 1, n) a[i] = rd();
	A[tota = 1] = mp(1, a[1]);
	rep(i, 2, n) 
		if (a[i] > A[tota].second) A[++tota] = mp(i, a[i]);
	B[totb = 1] = mp(n, a[n]);
	per(i, n - 1, 1) 
		if (a[i] > B[totb].second) B[++totb] = mp(i, a[i]);
	reverse(B + 1, B + 1 + totb);
	divide(1, totb, 1, tota);
	printf("%lld\n", ans);
	return 0;
}