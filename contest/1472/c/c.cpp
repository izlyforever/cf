#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (auto &x : a) std::cin >> x;
		auto b = a;
		for (int i = n - 1; i >= 0; --i) {
			if (a[i] + i < n) b[i] += b[i + a[i]];
		}
		std::cout << *std::max_element(b.begin(), b.end()) << std::endl;
	}
	return 0;
}