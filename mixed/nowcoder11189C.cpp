#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> p(n + 1), fa(n + 1), c(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> p[i], fa[i] = i;
	for (int i = 0, x; i < m; ++i) {
		std::cin >> x;
		++c[x];
	}
	std::function<int(int)> find = [&](int x) {
		return x == fa[x] ? x : fa[x] = find(fa[x]);
	};
	auto merge = [&](int x, int y) {
		fa[find(x)] = find(y);
	};
	for (int i = 1; i <= n; ++i) if (c[i] == 0) merge(i, p[i]);
	LL ans = 0;
	for (int i = n; i >= 0; --i) {
		int x = find(i);
		if (c[x]) {
			ans += i;
			if (--c[x] == 0) merge(x, p[x]);
		}
	}
	std::cout << ans << '\n';
	return 0;
}