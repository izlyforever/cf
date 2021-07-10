#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> sa(n), sb(n);
		for (auto &x : sa) std::cin >> x;
		for (auto &x : sb) std::cin >> x;
		std::vector<LL> a, b;
		for (int i = 0; i < n; ++i) {
			if (sb[i] == 1) a.emplace_back(sa[i]);
			else b.emplace_back(sa[i]);
		}
		std::sort(a.rbegin(), a.rend());
		std::sort(b.rbegin(), b.rend());
		for (int i = 1; i < a.size(); ++i) a[i] += a[i - 1];
		for (int i = 1; i < b.size(); ++i) b[i] += b[i - 1];
		int r = INT_MAX;
		int na = 0, nb = 0;
		while (na < a.size() && a[na] < m) ++na;
		if (na < a.size()) {
			r = std::min(r, na + 1);
		} else {
			while (nb < b.size() && b[nb] + (a.empty() ? 0 : a.back()) < m) ++nb;
			if (nb == b.size()) {
				std::cout << "-1\n";
				continue;
			}
			r = std::min(r, int(a.size() + 2 * (nb + 1)));
		}
		while (--na >= 0) {
			while (nb < b.size() && b[nb] + a[na] < m) ++nb;
			if (nb == b.size()) break;
			r = std::min(r, na + 1 + 2 * (nb + 1));
		}
		while (nb < b.size() && b[nb] < m) ++nb;
		if (nb != b.size()) r = std::min(r, 2 * (nb + 1));
		std::cout << r << "\n";
	}
	return 0;
}