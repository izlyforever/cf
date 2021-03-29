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
		int n, w;
		std::cin >> n >> w;
		std::vector<int> a(n);
		for (auto &x : a) std::cin >> x;
		std::sort(a.rbegin(), a.rend());
		std::multiset<int> S{w};
		for (auto x : a) {
			auto it = S.lower_bound(x);
			if (it == S.end()) {
				S.insert(w - x);
			} else {
				int now = *it;
				S.erase(it);
				S.insert(now - x);
			}
		}
		std::cout << S.size() << '\n';
	}
	return 0;
}