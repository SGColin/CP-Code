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

#define N 400007
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

inline void work() {
	int ha = rd(), hb = rd(), a = rd(), b = rd();
	// A B
	ll wab = 0, tab = 0, sum = 0, dltab = -1;
	for (int i = 1; ; ++i) {
		if (sum < ha) wab += a;
		else if (dltab < 0) dltab = sum - ha;
		if (sum < ha + hb) wab += b;
		sum += i;
		if (sum >= ha + hb) {tab = i; break;}
	}
	ll dltab2 = sum - ha - hb;
	// B A
	ll wba = 0, tba = 0, dltba = -1; sum = 0;
	for (int i = 1; ; ++i) {
		if (sum < hb) wba += b;
		else if (dltba < 0) dltba = sum - hb;
		if (sum < ha + hb) wba += a;
		sum += i;
		if (sum >= ha + hb) {tba = i; break;}
	}
	ll dltba2 = sum - ha - hb;

	string s1 = "", s2 = "";
	int tmpa = ha, tmpb = hb;
	if (dltab <= dltab2) {
		for (int i = 1; hb > 0; ++i) {
			if (ha > 0) {s1 += 'A'; ha -= i;}
			else {s1 += 'B'; hb -= i;}
		}
	} else {
		for (int i = 1; hb > 0; ++i) {
			if (ha > 0 && i != dltab) {s1 += 'A'; ha -= i;}
			else {s1 += 'B'; hb -= i;}
		}
	}
	ha = tmpa; hb = tmpb;
	ll L = dltba - dltba2, R = dltba, nw = 0;
	for (int i = 1; ha > 0; ++i) {
		if (nw + i <= R && (nw + i >= L || nw + i + i + 1 <= R)) {
			s2 += 'A'; ha -= i; nw += i;
		} else if (hb > 0) {s2 += 'B'; hb -= i;}
		else {s2 += 'A'; ha -= i;}
	}
	cout << min(wab, wba) << " ";
	if (wab == wba) cout << min(s1, s2) << endl;
	else cout << (wab < wba ? s1 : s2) << endl;
}

int main() {
	int t = rd();
	while (t--) work();
	return 0;
}