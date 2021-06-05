#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int k;
		std::cin >> k;
		int ans = 0;
		for (int i = 1; i <= 6; ++i) {
			for (int j = 1; j <= i; ++j) {
				if (i + j == k) ++ans;
			}
		}
		std::cout << ans << '\n';
	}
	return 0;
}