#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
std::vector<int> solve() {
	int k, n, m;
	std::cin >> k >> n >> m;
	std::vector<int> a(n), b(m);
	for (auto &x : a) std::cin >> x;
	for (auto &x : b) std::cin >> x;
	int i = 0, j = 0;
	std::vector<int> ans;
	while (i < n || j < m) {
		int cur = ans.size();
		while (i < n && a[i] <= k) {
			ans.emplace_back(a[i]);
			if (a[i] == 0) ++k;
			++i;
		}
		while (j < m && b[j] <= k) {
			ans.emplace_back(b[j]);
			if (b[j] == 0) ++k;
			++j;
		}
		if (cur == ans.size()) return std::vector<int>{-1};
	}
	return ans;
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas; // 根据情况注释掉
	while (cas--) {
		for (auto x : solve()) std::cout << x << ' ';
		std::cout << '\n';
	}
	return 0;
}