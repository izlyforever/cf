#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int x, y;
		std::string s;
		std::cin >> x >> y >> s;
		std::vector<int> a;
		int now = 0;
		while (now < s.size() && s[now] == '0') ++now;
		while (now < s.size()) {
			int tmp = now;
			while (now < s.size() && s[now] == '1') ++now;
			a.emplace_back(now - tmp);
			tmp = now;
			while (now < s.size() && s[now] == '0') ++now;
			if (now > tmp) a.emplace_back(tmp - now);
		}
		int r = 0;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] > 0) {
				int t = x;
				if (i > 0) t = std::min(t, (-a[i - 1]) * y);
				r += t;
			}
		}
		std::cout << r << std::endl;
	}
	return 0;
}