#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

std::string NO("Impossible");
std::vector<std::pair<int, int>> dir{{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
std::string invf("UDLR");
int f(char x) {
	if (x == 'U') return 0;
	if (x == 'D') return 1;
	if (x == 'L') return 2;
	if (x == 'R') return 3;
	return 4;
}

std::string solve() {
	int mx, my;
	std::string s;
	std::cin >> mx >> my >> s;
	if (mx == 0 && my == 0) return NO;
	std::vector<int> cnt(4);
	for (auto c : s) ++cnt[f(c)];
	auto g = [&](std::string a) {
		int x = 0, y = 0;
		for (auto c : a) {
			auto [xi, yi] = dir[f(c)];
			x += xi; y += yi;
			if (x == mx && y == my) return false;
		}
		return true;
	};
	std::vector<int> p{0, 1, 2, 3};
	do {
		std::string ans;
		for (auto i : p) ans += std::string(cnt[i], invf[i]);
		if (g(ans)) return ans;
	} while (std::next_permutation(p.begin(), p.end()));
	return NO;
}

int main() {
	// freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::cout << solve() << "\n";
	}
	return 0;
}