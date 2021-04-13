#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 1e9 + 7;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::map<LL, LL> mp{{0, 1}};
		// -key 是水位，sm 是所有元素之和。
		LL key = 0, sm = 1;
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			LL a = mp[key];
			mp[key] = sm;
			key -= x;
			sm = (sm * 2 - a + M) % M;
		}
		std::cout << sm << "\n";
	}
	return 0;
}