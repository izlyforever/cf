#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	LL a[11] = {0, 1, 3, 40, 1260, 72576, 6652800 , 889574400, 163459296000, 39520825344000, 12164510040883200};
	int n;
	std::cin >> n;
	print(a[n / 2]);
	return 0;
}