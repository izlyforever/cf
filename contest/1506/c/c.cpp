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
		std::string a, b;
		std::cin >> a >> b;
		int ab = std::min(a.size(), b.size());
		int r = 0;
		for (int x = 0; x < ab; ++x) {
			for (int i = 0; i + x < a.size(); ++i) {
				for (int j = 0; j + x < b.size(); ++j) {
					if (a.substr(i, x + 1) == b.substr(j, x + 1)) r = x + 1;
				}
			}
		}
		std::cout << a.size() + b.size() - 2 * r << '\n';
	}
	return 0;
}