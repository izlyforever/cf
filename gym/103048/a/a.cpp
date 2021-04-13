#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		std::vector<std::string> s;
		auto f = [&](int a, int n) {
			if (a == 1) {
				s.emplace_back(std::string("A ") + std::to_string(n));
			} else {
				s.emplace_back(std::string("A ") + std::to_string(-n));
				s.emplace_back("B 2");
			}
		};
		if (c == 0) {
			f(a, b);
		} else if (a == 0) {
			s.emplace_back("B 1");
			f(-c, -d);
		} else if (b == 0) {
			s.emplace_back("B 1");
			f(-d, c);
			s.emplace_back("B 1");
		} else {
			f(b, -a);
			s.emplace_back("B 1");
		}
		std::cout << s.size() << '\n';
		for (auto &x : s) std::cout << x << '\n';
	}
	return 0;
}