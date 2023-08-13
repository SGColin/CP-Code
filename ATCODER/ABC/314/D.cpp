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

#define N 500007

char s[N];

int tim[N], low = -1, up = -1;

char toup(char c) {return isupper(c) ? c : c - 'a' + 'A';}
char tolow(char c) {return islower(c) ? c : c - 'A' + 'a';}

int main() {
    int n = rd();
    scanf("%s", s + 1);
    int q = rd();
    for (int i = 1; i <= q; ++i) {
        int op = rd(), x = rd();
        char c = getchar();
        while (!isalpha(c)) c = getchar();
        if (op == 1) {s[x] = c; tim[x] = i;}
        if (op == 2) {low = i; up = -1;}
        if (op == 3) {up = i; low = -1;}
    }
    for (int i = 1; i <= n; ++i) {
        if (tim[i] > up && tim[i] > low) putchar(s[i]);
        else putchar(up > low ? toup(s[i]) : tolow(s[i]));
    }
    return 0;
}