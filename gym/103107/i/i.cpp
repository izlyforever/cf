#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int t;
		std::cin >> t;
		LL ans = 0;
		for (int i = 0; i < t; ++i) {
			int n, m;
			std::cin >> n >> m;
			std::set<int> S;			
			for (int i = 0, x; i < n; ++i) {
				std::cin >> x;
				S.insert(m - x - n + i + 1);
			}
			int cur = 0;
			for (auto x : S) cur += x & 1; 
			ans ^= cur & 1;
		}
		std::cout << (ans ? "Alice" : "Bob") << '\n';
	}
	return 0;
}