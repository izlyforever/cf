#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, m;
		std::string a;
		std::cin >> n >> m >> a;
		a = std::string("0") + a + std::string("0");
		m = std::min(n, m);
		while (m--) {
			std::string s = a;
			for (int i = 1; i <= n; ++i) if (a[i] == '0') {
				if ((a[i - 1] == '1') ^ a[i + 1] == '1') {
					s[i] = '1';
				}
			}
			std::swap(s, a);
		}
		for (int i = 1; i <= n; ++i) std::cout << a[i];
		std::cout << '\n';
	}
	return 0;
}