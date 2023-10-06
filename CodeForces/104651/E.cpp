#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define pb push_back
#define eb emplace_back
#define all(s) (s).begin(), (s).end()

#define N 41

int vis[N][N], n;

string str;

vector<pii> s;

void dfs(int x, int y, int nw) {
	if (nw == n) {s.eb(x, y); return;}
	int tx = x, ty = y;
	if (str[nw] == 'L') --tx;
	if (str[nw] == 'R') ++tx;
	if (str[nw] == 'D') --ty;
	if (str[nw] == 'U') ++ty;
	if (vis[tx + 20][ty + 20]) {
		vis[tx + 20][ty + 20] == 1 ? dfs(tx, ty, nw + 1) : dfs(x, y, nw + 1); 
	} else {
		vis[tx + 20][ty + 20] = 1; dfs(tx, ty, nw + 1);
		vis[tx + 20][ty + 20] = 2; dfs(x, y, nw + 1);
		vis[tx + 20][ty + 20] = 0;
	}
}

int main() {
	cin >> n >> str;
	vis[20][20] = 1;
	dfs(0, 0, 0);
	sort(all(s));
	s.erase(unique(all(s)), s.end());
	printf("%d\n", (int)s.size());
	for (auto [x, y] : s) printf("%d %d\n", x, y);
	return 0;
}