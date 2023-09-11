#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

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

#define N 2007
#define mp make_pair
#define eb emplace_back
#define lb lower_bound
#define all(s) (s).begin(), (s).end()

char a[N][N];

bool ob[N][N];

queue<pii> q;

int dis[N][N];

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int main() {
	int h = rd(), w = rd();
	rep(i, 1, h) scanf("%s", a[i] + 1);
	int sx, sy, tx, ty;
	rep(i, 1, h) {
		rep(j, 1, w) {
			if (a[i][j] == '#') ob[i][j] = true;
			else if (a[i][j] == '>') {
				ob[i][j] = true;
				int ptr = j;
				while (a[i][ptr + 1] == '.') {++ptr; ob[i][ptr] = true;}
			} else if (a[i][j] == '<') {
				ob[i][j] = true;
				int ptr = j;
				while (a[i][ptr - 1] == '.') {--ptr; ob[i][ptr] = true;}
			} else if (a[i][j] == '^') {
				ob[i][j] = true;
				int ptr = i;
				while (a[ptr - 1][j] == '.') {--ptr; ob[ptr][j] = true;}
			} else if (a[i][j] == 'v') {
				ob[i][j] = true;
				int ptr = i;
				while (a[ptr + 1][j] == '.') {++ptr; ob[ptr][j] = true;}
			} else if (a[i][j] == 'S') {sx = i; sy = j;}
			else if (a[i][j] == 'G') {tx = i; ty = j;}
		} 
	}
	memset(dis, 0x3f, sizeof(dis));
	q.push(mp(sx, sy));
	dis[sx][sy] = 0;
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		// printf("%d %d\n", x, y);
		rep(i, 0, 3) {
			int xx = x + dx[i], yy = y + dy[i];
			if (xx > 0 && xx <= h && yy > 0 && yy <= w && !ob[xx][yy]) {
				if (dis[xx][yy] > dis[x][y] + 1) {
					dis[xx][yy] = dis[x][y] + 1;
					q.push(make_pair(xx, yy));
				}
			}
		}
	}	
	printf("%d\n", dis[tx][ty] <= N * N ? dis[tx][ty] : -1);
	return 0;
}