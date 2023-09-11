#include<bits/stdc++.h>
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

#define N 1000007
#define M 4194304

int a[N], f[M];

int main() {
    memset(f, -1, sizeof(f));
    int n = rd();
    for (int i = 1; i <= n; ++i) {a[i] = rd(); f[a[i]] = a[i];}
    for (int i = 1; i < M; ++i) 
        for (int j = 0; j < 22; ++j)
            if (i & (1 << j)) f[i] = max(f[i], f[i ^ (1 << j)]); 
    for (int i = 1; i <= n; ++i) printf("%d ", f[(M - 1) ^ a[i]]);
    return 0;
}