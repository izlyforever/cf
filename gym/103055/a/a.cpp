#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	std::vector<int> a(5), b(5);
	for (auto &x : a) std::cin >> x;
	for (auto &x : b) std::cin >> x;
	std::cout << (std::accumulate(a.begin(), a.end(), 0) >= std::accumulate(b.begin(), b.end(), 0) ? "Blue" : "Red") << '\n';
	return 0;
}