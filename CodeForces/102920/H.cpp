#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> PN;

const int maxn=120007,maxt=1<<18,MOD=998244353;

int wn[maxt+5],temA[maxt+5],temB[maxt+5];

inline int ADD(int x,int y) {return x+y>=MOD?x+y-MOD:x+y;}
inline int MUL(int x,int y) {return (LL)x*y%MOD;}
int Pow(int w,int b) {int s;for (s=1;b;b>>=1,w=MUL(w,w)) if (b&1) s=MUL(s,w);return s;}
__attribute__((constructor)) void NTTPre(){
    int x=Pow(3,(MOD-1)/maxt);
    wn[maxt>>1]=1;
    for (int i=(maxt>>1)+1;i<maxt;i++) wn[i]=MUL(wn[i-1],x);
    for (int i=(maxt>>1)-1;i;i--) wn[i]=wn[i<<1];
}
void NTT(int *a,int n,int f){
    if (f>0){
        for (int k=n>>1;k;k>>=1)
            for (int i=0;i<n;i+=k<<1)
                for (int j=0;j<k;j++){
                    int x=a[i+j],y=a[i+j+k];
                    a[i+j+k]=MUL(x+MOD-y,wn[k+j]);
                    a[i+j]=ADD(x,y);
                }
    } else {
        for (int k=1;k<n;k<<=1)
            for (int i=0;i<n;i+=k<<1)
                for (int j=0;j<k;j++){
                    int x=a[i+j],y=MUL(a[i+j+k],wn[k+j]);
                    a[i+j+k]=ADD(x,MOD-y);
                    a[i+j]=ADD(x,y);
                }
        for (int i=0,INV=MOD-(MOD-1)/n;i<n;i++) a[i]=MUL(a[i],INV);
        reverse(a+1,a+n);
    }
}
PN operator * (const PN &a,const PN &b){
    static PN c;
    int n=a.size(),m=b.size(),t;
    for (t=1;t<n+m-1;t<<=1);
    for (int i=0;i<n;i++) temA[i]=a[i];
    for (int i=n;i<t;i++) temA[i]=0;
    for (int i=0;i<m;i++) temB[i]=b[i];
    for (int i=m;i<t;i++) temB[i]=0;
    NTT(temA,t,1);NTT(temB,t,1);
    for (int i=0;i<t;i++) temA[i]=MUL(temA[i],temB[i]);
    NTT(temA,t,-1);
    c.resize(n+m-1);for (int i=0;i<n+m-1;i++) c[i]=temA[i];
    return c;
}

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

vector<int> pos;

int main() {
    int buf = 30000;
    PN A(maxn, 0), B(maxn, 0);
    int n = rd();
    rep(i, 1, n) A[rd() + buf] = 1;
    int m = rd();
    rep(i, 1, m) pos.push_back(rd() * 2 + buf + buf);
    n = rd();
    rep(i, 1, n) B[rd() + buf] = 1;
    A = A * B;
    long long ans = 0;
    for (auto x : pos) ans += A[x];
    printf("%lld\n", ans);
    return 0;
}