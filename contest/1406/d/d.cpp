#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
 
LL floor(LL a, LL n) { // n > 0
	return a < 0 ? (a - n + 1) / n : a / n;
}
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	LL a[n], ret = 0;
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	for (int i = n - 1; i; --i) a[i] -= a[i - 1];
	for (int i = 1; i < n; ++i) ret += std::max(0LL, a[i]);
 
	std::cout << floor(a[0] + ret + 1, 2) << std::endl;
	int q;
	std::cin >> q;
	while (q--) {
		int l, r, x;
		std::cin >> l >> r >> x;
		if (r != n) {
			ret -= std::max(0LL, a[r]);
			a[r] -= x;
			ret += std::max(0LL, a[r]);
		}
		if (l != 1) ret -= std::max(0LL, a[l - 1]);
		a[l - 1] += x;
		if (l != 1) ret += std::max(0LL, a[l - 1]);
		std::cout << floor(a[0] + ret + 1, 2) << std::endl;
	}
	return 0;
}