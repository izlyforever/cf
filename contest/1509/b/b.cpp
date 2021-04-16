#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
	int n;
	std::string s;
	std::cin >> n >> s;
	int now = 0;
	for (auto x : s) {
		if (x == 'T') ++now;
		else if (--now < 0) return false;
	}
	if (now * 3 != n) return false;
	now = 0;
	std::reverse(s.begin(), s.end());
		for (auto x : s) {
		if (x == 'T') ++now;
		else if (--now < 0) return false;
	}
	return true;
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::cout << (solve() ? "YES" : "NO") << '\n';
	}
	return 0;
}