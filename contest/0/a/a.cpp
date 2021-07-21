#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	// std::cin.tie(nullptr)->sync_with_stdio(false);
    int n = 1e8 + 2;
    // std::vector<int> a(n);
    std::vector<int> a;
    a.reserve(n);
    a[1] = a[2] = a[3] = 0;
    int x;
    std::cin >> x;
    std::cout << a[x] << '\n';
	return 0;
}