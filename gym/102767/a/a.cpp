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
		int n, x;
		std::cin >> n >> x;
		std::vector<int> a(n);
		for (auto &x : a) std::cin >> x;
		std::sort(a.begin(), a.end());
		int id = std::upper_bound(a.begin(), a.end(), x) - a.begin();
		LL r = LL(x + 1) * x / 2;
		for (int i = 0; i < id; ++i) r -= a[i] * 2;
		std::cout << r << std::endl;
	}
	return 0;
}