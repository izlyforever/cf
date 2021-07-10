#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	// freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::set<std::pair<int, int>> S;
	while (m--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			int l, r, w;
			std::cin >> l >> r >> w;
			auto it = S.upper_bound({l, INT_MAX});
			if (it == S.begin() || (*--it).second < r) {
				if ((*it).first == l) S.erase(it);
				S.insert({l, r});
				while (1) {
					auto it = S.upper_bound({l, r});
					if (it != S.end() && (*it).second < r) S.erase(it);
					else break;
				}
			}
		} else {
			int k;
			std::cin >> k;
			std::vector<int> a(k);
			for (auto &x : a) std::cin >> x;
			int ans = 0, now = 0;
			while (now < k) {
				auto it = S.upper_bound({a[now], INT_MAX});
				if (it == S.begin() || (*--it).second < a[now]) {
					ans = -1;
					break;
				}
				++ans;
				while (now < k && a[now] <= (*it).second) ++now;
			}
			std::cout << ans << '\n';
		}
	}
	return 0;
}