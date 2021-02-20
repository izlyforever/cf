#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	for (auto &x : a) std::cin >> x;
	// 保存当前除了前一个位置外，还能取的元素
	std::set<int> S;
	int r = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] == a[i - 1]) continue;
		if (S.count(a[i])) {
			S = {a[i - 1]};
		} else {
			++r;
			S.insert(a[i - 1]);
		}
	}
	std::cout << r << "\n";
	return 0;
}