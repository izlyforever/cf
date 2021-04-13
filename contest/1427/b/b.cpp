#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n, k;
		std::string a;
		std::cin >> n >> k >> a;
		int now = 0;
		while (now < n && a[now] == 'L') ++now;
		if (now == n) {
			print(std::max(2 * k - 1, 0));
			continue;
		}
		int r = 2 * k;
		std::vector<int> x;
		while (now < n) {
			int cur = now;
			while (now < n && a[now] == 'W') ++now;
			r += 2 * (now - cur) - 1; 
			cur = now;
			while (now < n && a[now] == 'L') ++now;
			if (cur < now && now != n) x.emplace_back(now - cur);
		}
		std::sort(x.begin(), x.end());
		for (auto t : x) {
			if (t <= k) {
				++r;
				k -= t;
			} else break;
		}
		print(std::min(r, 2 * n - 1));
	}
	return 0;
}