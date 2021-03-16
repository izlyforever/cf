#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int solve() {
	LL x;
	std::cin >> x;
	int n = 1;
	auto f = [](int n) {
		return ((1LL << 2 * n) - 1) / 3 * 2 - (1LL << n) + 1;
	};
	while (f(n) <= x) ++n;
	return --n;
}

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::cout << solve() << '\n';
	}
	return 0;
}