#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define N 2007
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

struct draw{
    char ch;
    int ty, x1, x2, y1, y2;
    ll sqr(int x) {return 1ll * x * x;}
    bool in(int x, int y) {
        if (ty == 1) return sqr(x - x1) + sqr(y - y1) <= sqr(x2);
        else if (ty == 2) return (x >= x1 && x <= x2 && y >= y1 && y <= y2); 
        else return false;
    }
} d[N];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    rep(i, 1, n) {
        string s; cin >> s;
        if (s == "Circle") {
            d[i].ty = 1; cin >> d[i].x1 >> d[i].y1 >> d[i].x2 >> d[i].ch;
        } else if (s == "Rectangle") {
            d[i].ty = 2; cin >> d[i].x1 >> d[i].y1 >> d[i].x2 >> d[i].y2 >> d[i].ch;
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            per(y, y2, y1) {
                rep(x, x1, x2) {
                    bool fl = false;
                    per(j, i - 1, 1) 
                        if (d[j].in(x, y)) {putchar(d[j].ch); fl = true; break;}
                    if (!fl) putchar('.');
                }
                puts("");
            }
        }
    }
    return 0;
}
