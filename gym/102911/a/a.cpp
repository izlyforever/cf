#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<LL> a(n);
	for (auto &x : a) std::cin >> x;
	std::sort(a.begin(), a.end());
	for (int i = n - 1; i > 0; --i) a[i] -= a[i - 1];
	for (auto &x : a) std::cout << x << " ";
	std::cout << std::endl;
	return 0;
}