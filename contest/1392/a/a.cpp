#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		int a[n];
		for (int i = 0; i < n; ++i) std::cin >> a[i];
		bool flag = false;
		for (int i = 1; i < n; ++i)  if (a[i] != a[0]) {
			flag = true;
			break;
		}
		std::cout << (flag ? 1 : n) << std::endl;
	}
	return 0;
}