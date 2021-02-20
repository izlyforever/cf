#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::string s;
	std::cin >> s;
	int n = 0;
	n += s.back() - '0';
	s.pop_back();
	if (!s.empty()) n += 10 * (s.back() - '0');
	std::cout << (n % 4 == 0 ? 4 : 0) << std::endl;
	return 0;
}