#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	const int N = 5e7 + 10086; // 再多内存吃不消。 1e8 就要 400 M 内存了。
	std::vector<int> f(N);
	for (int i = 1; i * i < N; ++i) {
		int ii = i * i, cur = 0;
		for (int j = ii; j < N; j += ii) f[j] = ++cur;
	}
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::map<int, int> mp;
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			++mp[f[x]];
		}
		int r0 = INT_MIN, now = mp[1];
		for (auto [u, v] : mp) {
			r0 = std::max(r0, v);
			if (u != 1 && v % 2 == 0) now += v;
		}
		int r1 = std::max(r0, now);
		int q;
		std::cin >> q;
		while (q--) {
			LL w;
			std::cin >> w;
			std::cout << (w == 0 ? r0 : r1) << "\n";
		}
	}
	return 0;
}