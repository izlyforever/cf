#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, q;
		std::cin >> n >> q;
		std::vector<int> a(n);
		for (auto &x : a) std::cin >> x;
		std::sort(a.begin(), a.end());
		std::vector<LL> b(n + 1);
		for (int i = 0; i < n; ++i) {
			b[i + 1] = b[i] + a[i];
		}
		std::unordered_set<LL> S;
		std::function<void(int, int)> f = [&](int i, int j) {
			S.insert(b[j] - b[i]);
			int it = std::upper_bound(a.begin() + i, a.begin() + j, (a[i] + a[j - 1]) / 2) - a.begin();
			if (it == j) return;
			if (i < it) f(i, it);
			if (it < j) f(it, j);
		};
		f(0, n);
		while (q--) {
			int x;
			std::cin >> x;
			std::cout << (S.count(x) ? "Yes\n" : "No\n");
		}
	}
	return 0;
}