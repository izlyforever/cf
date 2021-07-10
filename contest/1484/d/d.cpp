#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n), nxt(n);
		for (auto &x : a) std::cin >> x;
		for (int i = 0; i < n; ++i) nxt[i] = i + 1;
		nxt.back() = 0;
		std::set<int> S;
		for (int i = 0; i < n; ++i) if (std::gcd(a[i], a[nxt[i]]) == 1) S.insert(i);
		std::vector<int> ans;
		int x = -1;
		while (!S.empty()) {
			auto it = S.upper_bound(x);
			if (it == S.end()) it = S.upper_bound(-1);
			x = *it;
			ans.emplace_back(nxt[x]);
			S.erase(nxt[x]);
			nxt[x] = nxt[nxt[x]];
			if (std::gcd(a[x], a[nxt[x]]) != 1) S.erase(x);
		}
		std::cout << ans.size();
		for (auto x : ans) std::cout << ' ' << x + 1;
		std::cout << '\n';
	}
	return 0;
}