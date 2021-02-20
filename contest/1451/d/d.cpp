#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
bool solve() {
	LL d, k;
	std::cin >> d >> k;
	d = d * d / k / k;
	LL x = std::sqrt(d / 2 + 0.1);
	return x * x + (x + 1) * (x + 1) <= d;
}
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::cout << (solve() ? "Ashish\n" : "Utkarsh\n");
	}
	return 0;
}