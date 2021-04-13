#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
	std::string s;
	std::cin >> s;
	int n = s.size(), now = 1;
	for (int i = 1; i < n; ++i) if (s[i] == s[i - 1]) {
		if (s[i] - '0' == now) {
			if (now == 0) return false;
			--now;
		}
	}
	return true;
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::cout << (solve() ? "YES\n" : "NO\n");
	}
	return 0;
}