#include <bits/stdc++.h>
using namespace std;

#define N 107

int n;

string s, t;

int main() {
    cin >> n >> s >> t;
    for (int i = 0; i < n; ++i) {
        if (s[i] == t[i]) continue;
        if (s[i] == '0' && t[i] == 'o') continue;
        if (s[i] == 'o' && t[i] == '0') continue;
        if (s[i] == '1' && t[i] == 'l') continue;
        if (s[i] == 'l' && t[i] == '1') continue;
        puts("No"); return 0;
    }
    puts("Yes");
  	return 0;
}