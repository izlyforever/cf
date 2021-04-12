#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k;
	std::cin >> n >> k;
	bool vis[k][k]{}, v[k]{}, flag = true;
	std::vector<int> s{0};
	while (flag) {
		flag = false;
		for (int i = 0; i < k; ++i) if (!v[i] && !vis[s.back()][i]) {
			vis[s.back()][i] = true;
			v[s.back()] = true;
			for (int j = 0; j < k; ++j) if (!vis[s.back()][j]) v[s.back()] = false;
			s.emplace_back(i);
			flag = true;
			break;
		}
	}
	for (int i = 0; i < n; ++i) std::cout << char('a' + s[i % s.size()]);
	std::cout << '\n';
	return 0;
}