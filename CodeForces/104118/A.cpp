#include <bits/stdc++.h>
using namespace std;

int main() {
	auto f = [&](int x) {
		if (x <= -3) return -1 * (x + 4) * (x + 4) + 8;
		if (x <= 2) return -2 * x + 1;
		return x * x * x - 14 * x + 17;
	}; 
	int x; cin >> x; cout << f(x) << endl;
	return 0;
}