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
		int n;
		std::cin >> n;
		std::vector<int> a(n), b;
		for (auto &x : a) std::cin >> x;
		LL r = 0;
		for (int i = 1; i < n; ++i) {
			r += abs(a[i] - a[i - 1]);
		}
		int mx = std::max(abs(a[1] - a[0]), abs(a[n - 1] - a[n - 2]));
		for (int i = 1; i + 1 < n; ++i) {
			mx = std::max(mx, abs(a[i] - a[i - 1]) + abs(a[i + 1] - a[i]) - abs(a[i + 1] - a[i - 1]));
		};
		std::cout << r - mx << std::endl;
	}
	return 0;
}