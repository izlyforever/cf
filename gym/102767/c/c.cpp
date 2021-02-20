#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (auto &x : a) std::cin >> x;
		int r = 0;
		for (int i = 0; i + 1 < n; ++i) {
			r = std::max(r, std::__gcd(a[i], a[i + 1]));
		}
		int len = 0, now = 0;
		while (now + 1 < n) {
			while (now + 1 < n && std::__gcd(a[now], a[now + 1]) != r) ++now;
			int tmp = now;
			while (now + 1 < n && std::__gcd(a[now], a[now + 1]) == r) ++now;
			len = std::max(len, now - tmp + 1);
		}
		std::cout << r << " " << len << std::endl;
	}
	return 0;
}