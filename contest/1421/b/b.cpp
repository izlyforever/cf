#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<std::string> s(n);
		for (auto &x : s) std::cin >> x;
		auto f = [](char c) {return c - '0';};
		int t = f(s[0][1]) + f(s[1][0]) + f(s[n - 1][n - 2]) + f(s[n - 2][n - 1]);
		std::vector<std::pair<int, int>> r;
		if (t == 0 || t == 4) {
			r.push_back({0, 1});
			r.push_back({1, 0});
		} else if (t == 1 || t == 3) {
			if (f(s[0][1]) == (4 - t) / 2) r.push_back({1, 0});
			if (f(s[1][0]) == (4 - t) / 2) r.push_back({0, 1});
			if (f(s[n - 1][n - 2]) == (4 - t) / 2) r.push_back({n - 2, n - 1});
			if (f(s[n - 2][n - 1]) == (4 - t) / 2) r.push_back({n - 1, n - 2});
		} else if (t == 2) {
			if (s[0][1] != s[1][0]) {
				if (f(s[0][1]) == 1) r.push_back({1, 0});
				if (f(s[1][0]) == 1) r.push_back({0, 1});
				if (f(s[n - 1][n - 2]) == 0) r.push_back({n - 2, n - 1});
				if (f(s[n - 2][n - 1]) == 0) r.push_back({n - 1, n - 2});
			}
		}
		print(r.size());
		for (auto [x, y] : r) std::cout << 1 + x << " " << 1 + y << std::endl;
	}
	return 0;
}