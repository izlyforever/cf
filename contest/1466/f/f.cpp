#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
const int M = 1e9 + 7;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> p(m + 1), sz(m + 1, 1);
	std::iota(p.begin(), p.end(), 0);
	auto find = [&](int x) {
		int ans = x;
		while (ans != p[ans]) ans = p[ans];
		while (x != ans) {
			int t = p[x];
			p[x] = ans;
			x = t;
		}
		return ans;
	};
	auto merge = [&](int x, int y) {
		int px = find(x), py = find(y);
		if (px == py) return false;
		p[py] = px;
		sz[py] += sz[px];
		sz[px] = 0;
		return true;
	};
	std::vector<int> r;
	for (int i = 1, k, x, y; i <= n; ++i) {
		std::cin >> k;
		if (k == 1) {
			std::cin >> y;
			x = 0;
		} else {
			std::cin >> x >> y;
		}
		if (merge(x, y)) {
			r.emplace_back(i);
		}
	}
	int ans = 1;
	for (int i = 0; i < r.size(); ++i) {
		ans *= 2;
		if (ans >= M) ans -= M;
	}
	std::cout << ans << " " << r.size() << std::endl;
	for (auto x : r) std::cout << x << " ";
	std::cout << std::endl;
	return 0;
}