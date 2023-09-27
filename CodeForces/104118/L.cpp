#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define pb push_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

ll gcd(ll a,ll b) {return b?gcd(b,a%b):a;}

ll exgcd(ll a,ll b,ll &x,ll &y){
	if (!b) {x=1;y=0;return a;}
	ll r=exgcd(b,a%b,y,x);y-=a/b*x;
	return r;
}

ll Inv(ll A,ll C){ll x,y;exgcd(A,C,x,y);return (x%C+C)%C;}

struct Hashmap{
	static const int HA=99991,maxe=46341;
	int E,lnk[HA],nxt[maxe+5];ll to[maxe+5],w[maxe+5];
	int top,stk[maxe+5];
	inline void Add(int x,ll y) {stk[++top]=x;to[++E]=y;w[E]=0;nxt[E]=lnk[x];lnk[x]=E;}
	void clear() {E=0;while (top) lnk[stk[top--]]=0;}
	bool count(ll x){
		int ha=x%HA;
		for (int j=lnk[ha];j;j=nxt[j])
			if (to[j]==x) return true;
		return false;
	}
	ll& operator [] (ll x){
		int ha=x%HA;
		for (int j=lnk[ha];j;j=nxt[j])
			if (to[j]==x) return w[j];
		Add(ha,x);return w[E];
	}
};

ll BSGS(ll A,ll B,ll C){ // A^x=B(mod C)
	static Hashmap f;
	A%=C;B%=C;
	if (!A && B) return B==1?0:-1; // if 0^0=1
	ll m=sqrt(C)+1,pw=1,INV=Inv(A,C),ipw=1,w=1;
	f.clear();
	for (int i=0;i<m;i++){
		ll now=ipw*B%C;
		if (!f.count(now)) f[now]=i;
		pw=pw*A%C;ipw=ipw*INV%C;
	}
	for (int i=0;i<m;i++,w=w*pw%C) if (f.count(w)) return i*m+f[w];
	return -1;
}

inline int fpow(int x, int t, int mod) {
	int res = 1;
	for (; t; t >>= 1, x = 1ll * x * x % mod)
		if (t & 1) res = 1ll * res * x % mod;
	return res;
}

inline void work() {
	ll a = rd(), b = rd(), s = rd(), p = rd(), v = rd();
	if (a == 1) {
		ll w = (v - s + p) % p;
		ll n, k;
		ll g = exgcd(b, p, n, k);
		if (w % g != 0) {puts("IMPOSSIBLE"); return;}
		ll bs = p / g;
		printf("%lld\n", (n * w / g % bs + bs) % bs);
	} else {
		ll w = (v * (a - 1) + b) % p;
		if ((s * a - s + b) % p == 0) {
			puts(w == 0 ? "0" : "IMPOSSIBLE"); return;
		}
		w = w * fpow((s * a - s + b) % p, p - 2, p) % p;
		ll res = BSGS(a, w, p);	
		if (res < 0) puts("IMPOSSIBLE");
		else printf("%lld\n", res); 
	}
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}