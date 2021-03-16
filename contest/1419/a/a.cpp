#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int solve() {
	int n;
	std::string a;
	std::cin >> n >> a;
	int t = n % 2;
	for (int i = 1 - t; i < n; i += 2) {
		if ((a[i] - '0') % 2 == t) return 2 - t;
	}
	return t + 1;
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