#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> h(n);
	for (auto &x : h) std::cin >> x;
	int l = h[0], r = h[0];
	for (int i = 1; i + 1 < n; ++i) {
		l = std::max(l - k + 1 , h[i]);
		r = std::min(r + k - 1, h[i] + k - 1);
		if (l > r) return 0;
	}
	return h.back() >= l - k + 1 && h.back() <= r + k - 1;
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::cout << (solve() ? "YES" : "NO") << "\n";
	}
	return 0;
}