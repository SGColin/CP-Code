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

#define N 6007
#define M 3000007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

string s[N];

int id[N][N], d[M];

vector<int> e[M];

const int dx[6] = {-2, -2, 0, 0, 2, 2};
const int dy[6] = {-2, 2, -4, 4, -2, 2};

const int DX[6] = {-4, 4, 2, -2, 2, -2};
const int DY[6] = {0, 0, 6, 6, -6, -6};

const int dX[6] = {-2, 2, 1, -1, 1, -1};
const int dY[6] = {0, 0, 3, 3, -3, -3};

queue<int> q;

inline void work() {
	int tot = 0;
	int r, c; 
	cin >> r >> c;
	r = 4 * r + 3;
	c = 6 * c + 3;
	rep(i, 0, r) {
		getline(cin, s[i]);
		//cout << i << " " << s[i] << endl;
	}
	--c;

	auto v = [&](int x, int y) {
		if (s[x][y] != ' ' && s[x][y] != 'S' && s[x][y] != 'T') return false;
		if (!(x > 1 && x < r && y > 3 && y < c - 2)) return false;
		rep(i, 0, 5) if (s[x + dx[i]][y + dy[i]] != '+') return false;
		//rep(i, 0, 7) printf("? %d %d '%c'\n", x + dx[i], y + dy[i], s[x + dx[i]][y + dy[i]]); 
		return true;
	};

	int S, T;
	rep(i, 1, r) rep(j, 0, c) {
		id[i][j] = 0;
		if (v(i, j)) {
			//printf("%d %d\n", i, j); fflush(stdout);
			id[i][j] = ++tot;
			if (s[i][j] == 'S') S = tot;
			if (s[i][j] == 'T') T = tot;
		}
	}
	rep(i, 1, r) rep(j, 0, c) if (id[i][j]) {
		rep(k, 0, 5) {
			int tx = i + DX[k];
			int ty = j + DY[k]; 
			if (tx > 0 && ty > 0 && id[tx][ty] && s[i + dX[k]][j + dY[k]] == ' ') 
				e[id[i][j]].push_back(id[tx][ty]);
		}
	}
	rep(i, 1, tot) d[i] = 1e9;
	d[S] = 0; q.push(S);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto v : e[u])
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
	cout << (d[T] > 10000000 ? -1 : d[T] + 1) << endl;
	rep(i, 1, tot) e[i].clear();
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	while (t--) work();
	return 0;
}