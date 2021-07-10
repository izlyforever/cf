#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
	//freopen("in","r",stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (auto &x : a) std::cin >> x;
	int ma = *std::max_element(a.begin(), a.end()) * 2;
	std::vector<int> p;
	for (int i = 2; i < ma; ++i) {
		bool flag = true;
		for (int j = 2; j * j <= i; ++j) if (i % j == 0) {
			flag = false;
			break;
		}
		if (flag) p.emplace_back(i);
	}
	std::vector<int> factor(ma);
	for (int i = 2; i < ma; ++i) {
		for (int j = 0; j < p.size(); ++j) if (i % p[j] == 0) {
			factor[i] |= (1 << j);
		}
	}
	std::vector<std::vector<int>> ans(n + 1, std::vector<int>(1 << p.size(), 1e9));
	ans[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < 2 * a[i - 1]; ++j) {
			for (int k = 0; k < (1 << p.size()); ++k) if ((k & factor[j]) == 0) {
				ans[i][k | factor[j]] = std::min(ans[i][k | factor[j]], ans[i - 1][k] + abs(a[i - 1] - j));
			}
		}
	}
	std::vector<int> r(n);
	int now = std::min_element(ans[n].begin(), ans[n].end()) - ans[n].begin();
	for (int i = n - 1; i >= 0; --i) {
		for (int j = 1; j < 2 * a[i]; ++j) if ((now | factor[j]) == now) {
			if (ans[i][now ^ factor[j]] + abs(a[i] - j) == ans[i + 1][now]) {
				r[i] = j;
				now ^= factor[j];
				break;
			}
		}
	}
	for (auto x : r) std::cout << x << " ";
	println;
	return 0;
}