#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> cnt(m);
	while (n) {
		if (++cnt[n % m] > 1) {
			std::cout << "NO\n";
			return 0;
		}
		n /= m;
	}
	std::cout << "YES\n";
	return 0;
}