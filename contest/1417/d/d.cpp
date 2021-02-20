#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n + 1);
		for (int i = 1; i <= n; ++i) std::cin >> a[i];
		int s = std::accumulate(a.begin(), a.end(), 0);
		if (s % n) {
			print(-1);
			continue;
		}
		s /= n;
		std::vector<std::tuple<int, int, int>> ans;
		for (int i = 2; i <= n; ++i) {
			int x = a[i] % i;
			if (x) {
				ans.push_back({1, i, i - x});
				a[i] += i - x;
			}
			ans.push_back({i, 1, a[i] / i});
		}
		for (int i = 2; i <= n; ++i) ans.push_back({1, i, s});
		print(ans.size());
		for (auto [i, j ,x] : ans) std::cout << i << " " << j << " " << x << std::endl;
	}
	return 0;
}