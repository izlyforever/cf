#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	std::vector<int> cnt(35);
	for (int i = 0, x; i < 14; ++i) {
		std::cin >> x;
		++cnt[x];
	}
	int r = 0, flag = 0;
	for (int i = 1; i <= 13; ++i) if (cnt[i]) {
		++r;
		if (cnt[i] > 1) flag = 1;
	}
	if (flag == 1) ++r;
	std::cout << 14 - r << std::endl;
	return 0;
}