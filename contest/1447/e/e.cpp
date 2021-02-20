#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (auto &x : a) std::cin >> x;
	std::function<int(std::vector<int>, int)> dfs = [&](std::vector<int> a, int now) -> int {
		if (now < 0 || a.size() <= 2) return 0;
		std::vector<int> b, c;
		for (auto x : a) {
			if ((x >> now) & 1) b.emplace_back(x);
			else c.emplace_back(x);
		}
		return std::min(dfs(b, now - 1) + std::max(0, int(c.size() - 1)), dfs(c, now - 1) + std::max(0, int(b.size() - 1)));
	};
	std::cout << dfs(a, 29) << std::endl;
	return 0;
}