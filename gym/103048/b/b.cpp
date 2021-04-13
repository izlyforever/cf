#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int main() {
	freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::string s, ans;
		std::cin >> s;
		bool flag;
		auto solve = [&](int i, int j) {
			std::string x = s.substr(j);
			if (i < j) {
				if (s.substr(i, j - i) == std::string(j - i, '9')) {
					x = s.substr(j) + std::string(j - i, '0');
				} else {
					x = s.substr(j) + s.substr(i, j - i);
					int now = x.size() - 1;
					while (x[now] == '9') {
						x[now] = '0';
						--now;
					}
					x[now] += 1;
				}
			}
			if (ans < x) return;
			std::string a(x);
			std::reverse(a.begin(), a.end());
			while (j > 0) {
				int t = 0;
				while (t < a.size() && a[t] == '0') {
					a[t] = '9';
					++t;
				}
				if (t == a.size()) return;
				--a[t];
				if (a.back() == '0') a.pop_back();
				for (auto c : a) {
					if (s[--j] != c) return;
					if (j == 0) break;
				}
			}
			flag = true;
			ans = x;
		};
		for (int i = 1; i <= s.size(); ++i) {
			flag = false;
			ans = std::string(i, '9');
			for (int j = 1; j <= i; ++j) if (s[s.size() - j] != '0') {
				solve(s.size() - i, s.size() - j);
			}
			if (flag) break;
		}
		std::cout << ans << '\n';
	}
	return 0;
}