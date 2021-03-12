#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int f(char x) {
	if (x == 'U') return 0;
	if (x == 'D') return 1;
	if (x == 'L') return 2;
	return 3;
}
std::string NO("Impossible");
std::string solve() {
	int x, y;
	std::string s;
	std::cin >> x >> y >> s;
	if (x == 0 && y == 0) return NO;
	std::string invf("UDLR");
	std::vector<std::pair<int, int>> dir{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
	int cnt[4]{};
	for (auto &x : s) ++cnt[f(x)];
	auto g = [&](std::vector<int> &a) {
		int rx = 0, ry = 0;
		for (auto i : a) {
			auto [xi, yi] = dir[i];
			rx += xi;
			ry += yi;
			if (rx == x && ry == y) return false;
		}
		return true;
	};
	std::vector<int> p{0, 1, 2, 3};
	do {
		std::vector<int> a;
		std::string ans;
		for (int i = 0; i < 4; ++i) {
			ans += std::string(cnt[i], invf[i]);
			auto tmp = std::vector<int>(cnt[i], i);
			a.insert(a.end(), tmp.begin(), tmp.end());
		}
		if (g(a)) return ans;
	} while (std::next_permutation(p.begin(), p.end()));
	return NO;
}

int main() {
	freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::cout << solve() << "\n";
	}
	return 0;
}

// 4
// 0 5
// UUU
// 0 3
// UUU
// 0 2
// UUU
// 0 0
// UUU