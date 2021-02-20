#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::string s;
	s.resize(n);
	int now = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (now >= 0) {
			s[i] = 'B';
			now -= i + 1;
		} else {
			s[i] = 'A';
			now += i + 1;
		}
	}
	std::cout << abs(now) << std::endl;
	std::cout << s << std::endl;
	return 0;
}