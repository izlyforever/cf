#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, k;
		std::cin >> n >> k;
		std::vector<int> a;
		for (int i = n; i > k; --i) a.emplace_back(i);
		for (int i = k - 1; i * 2 >= k; --i) a.emplace_back(i);
		std::cout << a.size() << "\n";
		for (auto &x : a) std::cout << x << " ";
		std::cout << "\n";
	}
	return 0;
}