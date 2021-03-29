#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

bool query(int x, int y) {
	std::string s;
	std::cout << "? " << ++x << ' ' << ++y << std::endl;
	std::cin >> s;
	return s[0] == 'Y';
}

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	int now = -1;
	for (auto &[x, id] : a) std::cin >> x, id = ++now;
	std::sort(a.begin(), a.end());
	now = 0;
	while (now < n && a[now].first == now) ++now;
	if (now == n) std::cout << "! 0 0" << std::endl;
	else std::cout << "! " << ++a[now].second << ' ' << ++a.back().second << std::endl;
	return 0;
}