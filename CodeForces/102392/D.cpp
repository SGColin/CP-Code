#include <bits/stdc++.h>
using namespace std;

#define N 1000007
#define pb push_back

char s[N];

int cnt[26];

int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; ++i) ++cnt[s[i] - 'a'];
	int mx = 0, ptr = 0, cntt = 0;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] > mx) {mx = cnt[i]; ptr = i;}
		if (cnt[i] > 0) ++cntt;
	}
	
	if (mx <= n / 2) {
		puts("YES");
		for (int i = 0; i < 26; ++i)
			for (int j = 1; j <= cnt[i]; ++j) putchar('a' + i);
	} else {
		if (mx > n - 2) {puts("NO"); return 0;}
		if (cntt == 2 && mx > n - 3) {puts("NO"); return 0;}
		puts("YES");
		for (int j = 1; j <= n / 2; ++j) putchar('a' + ptr);
		cnt[ptr] -= n / 2;
		for (int i = 0; i < 26; ++i)
			if (i != ptr && cnt[i]) {
				putchar('a' + i); --cnt[i]; break;
			}
		for (int j = 1; j <= cnt[ptr]; ++j) putchar('a' + ptr);
		cnt[ptr] = 0;
		for (int i = 0; i < 26; ++i)
			for (int j = 1; j <= cnt[i]; ++j) putchar('a' + i);
	}
	return 0;
}