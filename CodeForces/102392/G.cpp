#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef tuple<int, int, int> tii;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

inline void getmin(ll &x, ll y) {x = (x > y ? y : x);}

#define N 1001
#define pb push_back
#define eb emplace_back
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

vector<tii> mx, mn;

vector<int> A, B;

string a[101], b[101];

int main() {
	int n, m, h;
	cin >> n >> m >> h;
	--n; --m; --h;
	rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) cin >> b[i];
	rep(i, 0, n) {
		A.clear(); B.clear();
		rep(j, 0, m) 
			if (a[i][j] == '1') A.push_back(j);
		rep(k, 0, h)
			if (b[i][k] == '1') B.push_back(k);
		if ((A.size() == 0 && B.size() > 0) || (A.size() > 0 && B.size() == 0)) {puts("-1"); return 0;}
		for (auto y : A) for (auto z : B) mx.eb(i, y, z);
		while (A.size() < B.size()) A.pb(A.front());
		while (A.size() > B.size()) B.pb(B.front());
		sort(A.begin(), A.end());
		sort(B.begin(), B.end());
		for (size_t p = 0; p < A.size(); ++p) mn.eb(i, A[p], B[p]);
	}
	sort(mx.begin(), mx.end());
	sort(mn.begin(), mn.end());
	printf("%d\n", (int)mx.size());
	for (auto [x, y, z] : mx) printf("%d %d %d\n", x, y, z);
	printf("%d\n", (int)mn.size());
	for (auto [x, y, z] : mn) printf("%d %d %d\n", x, y, z);
	return 0;
}