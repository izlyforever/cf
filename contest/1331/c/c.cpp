#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::cin >> n;
	auto a = std::bitset<6>(n);
	bool flag = a[0];
	a[0] = a[4];
	a[4] = flag;
	flag = a[2];
	a[2] = a[3];
	a[3] = flag;
	std::cout << a.to_ulong() << '\n';
	return 0;
}