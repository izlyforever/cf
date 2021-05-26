#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, k;
	std::cin >> n >> k;
	LL sm = 0;
	for (int i = 0, x; i < n; ++i) {
		std::cin >> x;
		sm += x;
	}
	std::cout << (sm >= k ? sm - (k + 1) / 2 : 0) << '\n';
	return 0;
}