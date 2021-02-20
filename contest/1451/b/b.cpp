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
		int n, q;
		std::string a;
		std::cin >> n >> q >> a;
		auto f = [&](int l, int r) -> bool {
			for (int i = 0; i < l; ++i) if (a[i] == a[l]) return true;
			for (int i = r + 1; i < a.size(); ++i) if (a[i] == a[r]) return true;
			return false;
		};
		while (q--) {
			int x, y;
			std::cin >> x >> y;
			std::cout << (f(x - 1, y - 1) ? "YES" : "NO") << std::endl;
		}
	}
	return 0;
}