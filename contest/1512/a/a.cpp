#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		std::map<int, int> mp;
		for (auto &x : a) std::cin >> x, ++mp[x];
		for (int i = 0; i < n; ++i) if (mp[a[i]] == 1) {
			std::cout << i + 1 << '\n';
		}
	}
	return 0;
}