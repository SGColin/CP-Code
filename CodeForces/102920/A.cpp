#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tii;

inline int rd() {
    int x = 0;
    bool f = 0;
    char c = getchar();
    for (; !isdigit(c); c = getchar()) f |= (c == '-');
    for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
    return f ? -x : x;
}

#define N 507
#define mp make_pair
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

vector<int> pos;

map<int, set<int>> X, Y;

map<pair<int, int>, int> ty;

vector<tii> lv, lh;

int bx[N], by[N], ex[N], ey[N];

int main() {
    int n = rd(), t = rd();
    auto ins = [&](int x, int y, int tp = 2) {
        X[y].insert(x); Y[x].insert(y); ty[mp(x, y)] = tp;
    };
    rep(i, 1, n) {
        bx[i] = rd(); by[i] = rd(); ins(bx[i], by[i]); 
        ex[i] = rd(); ey[i] = rd(); ins(ex[i], ey[i]);
        if (bx[i] == ex[i]) lv.eb(bx[i], min(by[i], ey[i]), max(by[i], ey[i]));
        else lh.eb(by[i], min(bx[i], ex[i]), max(bx[i], ex[i]));
    }  
    for (auto [xx, yl, yr] : lv)
        for (auto [yy, xl, xr] : lh) 
            if (xx >= xl && xx <= xr && yy >= yl && yy <= yr) ins(xx, yy, 1);
    int x = bx[1], y = by[1], dir = 0;
    // 0 : >
    // 1 : ^
    // 2 : <
    // 3 : v
    if (bx[1] == ex[1]) dir = (by[1] > ey[1] ? 3 : 1);
    else dir = (bx[1] > ex[1] ? 2 : 0);
    int tot = 0;
    do {
        if (dir == 0) { // >
            int nx = *X[y].upper_bound(x);
            tot += nx - x;
            if (tot >= t) {printf("%d %d\n", nx - (tot - t), y); return 0;}
            x = nx; 
        } else if (dir == 2) { // <
            int nx = *--X[y].lower_bound(x);   
            tot += x - nx;
            if (tot >= t) {printf("%d %d\n", nx + (tot - t), y); return 0;}
            x = nx; 
        } else if (dir == 3) { // v
            int ny = *--Y[x].lower_bound(y);   
            tot += y - ny;
            if (tot >= t) {printf("%d %d\n", x, ny + (tot - t)); return 0;}
            y = ny; 
        } else { // ^
            int ny = *Y[x].upper_bound(y);   
            tot += ny - y;
            if (tot >= t) {printf("%d %d\n", x, ny - (tot - t)); return 0;}
            y = ny; 
        }
        dir = (dir + ty[mp(x, y)]) % 4;
    } while(x != bx[1] || y != by[1]);
    t %= tot; tot = 0;
    do {
        if (dir == 0) { // >
            int nx = *X[y].upper_bound(x);
            tot += nx - x;
            if (tot >= t) {printf("%d %d\n", nx - (tot - t), y); return 0;}
            x = nx; 
        } else if (dir == 2) { // <
            int nx = *--X[y].lower_bound(x);   
            tot += x - nx;
            if (tot >= t) {printf("%d %d\n", nx + (tot - t), y); return 0;}
            x = nx; 
        } else if (dir == 3) { // v
            int ny = *--Y[x].lower_bound(y);   
            tot += y - ny;
            if (tot >= t) {printf("%d %d\n", x, ny + (tot - t)); return 0;}
            y = ny; 
        } else { // ^
            int ny = *Y[x].upper_bound(y);   
            tot += ny - y;
            if (tot >= t) {printf("%d %d\n", x, ny - (tot - t)); return 0;}
            y = ny; 
        }
        dir = (dir + ty[mp(x, y)]) % 4;
    } while(t);
    return 0;
}