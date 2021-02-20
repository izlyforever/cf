#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
using tp = std::tuple<int, int, int>;
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<tp> a(n);
		for (int i = 0, x, y; i < n; ++i) {
			std::cin >> x >> y;
			if (x > y) std::swap(x, y);
			a[i] = {x, y, i};
		}
		std::sort(a.begin(), a.end(), [](const tp &A, const tp &B) {
			return std::get<0>(A) < std::get<0>(B) || (std::get<0>(A) == std::get<0>(B) && std::get<1>(A) > std::get<1>(B));
		});
		std::map<int, int> mp;
		std::vector<int> r(n);
		for (int i = 0; i < n; ++i) {
			auto [x, y, id] = a[i];
			if (auto it = mp.begin(); it != mp.end() && it->first < y) {
				r[id] = it->second;
			} else {
				r[id] = -1;
				mp[y] = id + 1;
			}
		}
		for (int i = 0; i < n; ++i) std::cout << r[i] << " \n"[i == n - 1];
	}
	return 0;
}