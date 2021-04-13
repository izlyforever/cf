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
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for (auto &x : a) std::cin >> x;
		int mx = *std::max_element(a.begin(), a.end());
		int r = -1;
		for (int i = 0; i < n; ++i) if (a[i] == mx) {
			if ((i > 0 && a[i - 1] < mx) || (i + 1 < n && a[i + 1] < mx)) {
				r = i + 1;
				break;
			}
		}
		print(r);
	}
	return 0;
}