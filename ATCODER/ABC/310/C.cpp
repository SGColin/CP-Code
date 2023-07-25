#include <bits/stdc++.h>
using namespace std;

set<string> s;

int main() {
    int n, ans = 0; cin >> n;
    for (int i = 1; i <= n; ++i) {
        string t; cin >> t;
        if (s.find(t) == s.end()) ++ans;
        s.insert(t);
        reverse(t.begin(), t.end());
        s.insert(t);
    }
    cout << ans << endl;
    return 0;
}