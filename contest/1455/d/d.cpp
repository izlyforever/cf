#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int solve() {
	int n, x;
	std::cin >> n >> x;
	std::vector<int> a(n);
	for (auto &t : a) std::cin >> t;
	--n;
	while (n && a[n - 1] <= a[n]) --n;
	if (n == 0) return 0;
	int now = 0, r = 0;
	while (now < n) {
		while (now < n && a[now] <= x) ++now;
		if (now < n) {
			std::swap(a[now], x);
			++r;
		}
	}
	return std::is_sorted(a.begin(), a.end()) ? r : -1;
}
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::cout << solve() << std::endl;
	}
	return 0;
}