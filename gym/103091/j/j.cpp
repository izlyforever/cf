#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::vector<int> a(3);
		for (auto &x : a) std::cin >> x;
		std::sort(a.begin(), a.end());
		std::cout << (a[0] + a[1] > a[2] ? "Yes\n" : "No\n");
	}
	return 0;
}