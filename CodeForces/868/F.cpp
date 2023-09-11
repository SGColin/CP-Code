#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline char rdc(){
	static char buf[1<<16],*l=buf,*r=buf;
	return l==r && (r=(l=buf)+fread(buf,1,1<<16,stdin),l==r)?EOF:*l++;
}

inline int rd(){
    int x = 0; 
    bool f = 0; 
    char c = rdc();
    for (; !isdigit(c); c = rdc()) f |= (c == '-');
    for (; isdigit(c); c = rdc()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define N 100007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

ll res, f[N], lst[N];

int a[N], cnt[N], nwl = 1, nwr = 0;

inline void add(int x) {res += cnt[x]++;}
inline void del(int x) {res -= --cnt[x];}

ll cost(int ql, int qr) {
    while (nwl < ql) del(a[nwl++]);
    while (nwl > ql) add(a[--nwl]);
    while (nwr > qr) del(a[nwr--]);
    while (nwr < qr) add(a[++nwr]);
    return res;
}

void divide(int l, int r, int L, int R) {
	if (l > r) return;
	ll mn = 1e18;
	int mid = (l + r) / 2, opt = L;
	per(i, min(R, mid - 1), L) {
		ll nw = lst[i] + cost(i + 1, mid);
		if (nw < mn) {mn = nw; opt = i;}
	}
	f[mid] = mn;
	divide(l, mid - 1, L, opt);
	divide(mid + 1, r, opt, R);
}

int main() {
	int n = rd(), k = rd();
	rep(i, 1, n) a[i] = rd();
	memset(lst, 0x3f, sizeof(lst));
	lst[0] = 0;
	rep(i, 1, k) {
		divide(1, n, 0, n - 1);
		rep(j, 1, n) lst[j] = f[j]; 
	}
	printf("%lld\n", f[n]); 
	return 0;
}