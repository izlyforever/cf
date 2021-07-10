#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::cin >> n;
	LL sm = 0;
	int cur = 0;
	for (int i = 0, x; i < n; ++i) {
		std::cin >> x;
		cur ^= x;
		sm += x;
	}
	std::cout << sm - cur << '\n';
	return 0;
}