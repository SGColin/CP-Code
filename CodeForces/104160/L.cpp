#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 10

int a[N], ra[N], b[N], rb[N], n, m;

double pa, pb, pt;

inline int geta(int x) {
	if (x > n) x -= n;
	for (int i = 1; i <= n; ++i) {
		if (ra[x] > 0) return x;
		++x; if (x > n) x -= n;
	}
	return -1;
}

inline int getb(int x) {
	if (x > m) x -= m;
	for (int i = 1; i <= m; ++i) {
		if (rb[x] > 0) return x;
		++x; if (x > m) x -= m;
	}
	return -1;
}

void dfs(int ptra, int ptrb, double p, int turn) {
	if (ptra == -1 && ptrb == -1) {pt += p; return;}
	if (ptra == -1) {pb += p; return;}
	if (ptrb == -1) {pa += p; return;}
	if (turn == 1) { // alice
		double cnt = 0;
		for (int i = 1; i <= m; ++i) if (rb[i] > 0) cnt += 1;
		cnt = 1.0 / cnt;
		for (int i = 1; i <= m; ++i) if (rb[i] > 0) {
			ra[ptra] -= b[i]; 
			rb[i] -= a[ptra];
			dfs(geta(ptra + 1), getb(ptrb), p * cnt, turn ^ 1);
			rb[i] += a[ptra];
			ra[ptra] += b[i];
		}
	} else { // bob
		double cnt = 0;
		for (int i = 1; i <= n; ++i) if (ra[i] > 0) cnt += 1;
		cnt = 1.0 / cnt;
		for (int i = 1; i <= n; ++i) if (ra[i] > 0) {
			rb[ptrb] -= a[i]; 
			ra[i] -= b[ptrb];
			dfs(geta(ptra), getb(ptrb + 1), p * cnt, turn ^ 1);
			ra[i] += b[ptrb];
			rb[ptrb] += a[i];
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {cin >> a[i]; ra[i] = a[i];}
	for (int i = 1; i <= m; ++i) {cin >> b[i]; rb[i] = b[i];}
	if (n != m) dfs(1, 1, 1, (n > m));
	else {dfs(1, 1, 0.5, 1); dfs(1, 1, 0.5, 0);}
	printf("%.12lf\n%.12lf\n%.12lf\n", pa, pb, pt);
	return 0;
}