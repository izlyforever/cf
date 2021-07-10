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
		std::vector<int> a(n + m - 1);
		for (int i = 0; i < n; ++i) {
			for (int j = 0, x; j < m; ++j) {
				std::cin >> x;
				a[i + j] ^= x;
			}
		}
		bool flag = true;
		for (int i = 0; i < n + m - 1; ++i) if (a[i]) {
			flag = false;
			break;
		}
		std::cout << (flag ? "Jeel" : "Ashish") << std::endl; 
	}
	return 0;
}