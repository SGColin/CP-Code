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

#define mp make_pair
#define pb push_back
#define mt make_tuple
#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

map<string, int> f;

int main() {
	f["tourist"] = 3858;
	f["ksun48"] = 3679;
	f["Benq"] = 3658;
	f["Um_nik"] = 3648;
	f["apiad"] = 3638;
	f["Stonefeang"] = 3630;
	f["ecnerwala"] = 3613;
	f["mnbvmar"] = 3555;
	f["newbiedmy"] = 3516;
	f["semiexp"] = 3481;
	string s; cin >> s; cout << f[s] << endl;

	return 0;
}