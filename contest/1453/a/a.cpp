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
		std::vector<int> a(101);
		for (int i = 0, x; i < n; ++i) {
			std::cin >> x;
			a[x] = 1;
		}
		int r = 0;
		for (int i = 0, x; i < m; ++i) {
			std::cin >> x;
			if (a[x]) ++r;
		}
		std::cout << r << std::endl;
	}
	return 0;
}