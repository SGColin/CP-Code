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

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)

const int prime[200] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

struct num {
	int len, a[200];
	inline void reset() {
		memset(a, 0, sizeof(a));
		a[len = 1] = 1;
	}
	inline bool operator >= (const num &obj) const {
		if (len != obj.len) return len > obj.len;
		for (int i = len; i; --i)
			if (a[i] != obj.a[i]) return a[i] > obj.a[i];
		return true;
	}
	inline void read() {
		len = 0;
		char c = getchar();
		while (!isdigit(c)) c = getchar();
		while (isdigit(c)) {
			a[++len] = c - '0';
			c = getchar();
		}
		reverse(a + 1, a + 1 + len);
	}
	inline void mul(int x) {
		int rem = 0;
		for (int i = 1; i <= len; ++i) {
			a[i] = a[i] * x + rem;
			rem = a[i] / 10;
			a[i] = a[i] % 10;
		}
		while (rem) {
			a[++len] = rem % 10;
			rem /= 10;
		}
	}
	void print() {
		for (int i = len; i; --i) printf("%d", a[i]);
	}
} N, A, B;

inline void work() {
	N.read();
	A.reset();
	int ptr = 0;
	while (N >= A) A.mul(prime[++ptr]);
	--ptr;
	if (ptr == 0) {puts("1/1"); return;}
	vector<int> up, dn;
	rep(i, 1, ptr) {
		up.push_back(prime[i]);
		dn.push_back(prime[i] + 1);
	}
	A.reset();
	B.reset();
	for (auto x : up) {
		bool fl = false;
		for (auto &y : dn) 
			if (y % x == 0) {
				y /= x; fl = true; break;
			}
		if (!fl) A.mul(x);
	}
	for (auto x : dn) B.mul(x);
	A.print(); putchar('/'); B.print(); puts("");
}

int main() {
	int t = rd();
	while (t--) work();
	return 0;
}