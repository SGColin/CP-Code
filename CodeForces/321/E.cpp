#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline char readc(){
	static char buf[1<<16],*l=buf,*r=buf;
	return l==r && (r=(l=buf)+fread(buf,1,1<<16,stdin),l==r)?EOF:*l++;
}

inline int rd(){
	char ch = readc();
	while (!isdigit(ch)) ch = readc();
	return ch - '0';
}

#define K 807
#define N 4007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

int f[K][N], sum[N][N], w[N][N];

void divide(int k, int l, int r, int L, int R) {
	if (l > r) return;
	int mid = (l + r) / 2, opt = L, mn = 2e9;
	per(i, min(R, mid - 1), L) {
		int nw = f[k - 1][i] + w[i + 1][mid];
		if (nw < mn) {mn = nw; opt = i;}
	}
	f[k][mid] = mn;
	divide(k, l, mid - 1, L, opt);
	divide(k, mid + 1, r, opt, R);
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	rep(i, 1, n) {
		rep(j, 1, n) sum[i][j] = sum[i][j - 1] + rd();
		rep(j, 1, n) sum[i][j] += sum[i - 1][j];
	}
	rep(l, 1, n) rep(r, l, n) 
		w[l][r] = sum[r][r] - sum[r][l - 1] - sum[l - 1][r] + sum[l - 1][l - 1];
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	rep(i, 1, k) divide(i, 1, n, 0, n - 1);
	printf("%d\n", f[k][n] / 2); 
	return 0;
}