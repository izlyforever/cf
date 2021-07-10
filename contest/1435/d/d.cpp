#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::cin >> n;
	int now = 0;
	std::vector<int> r(n);
	std::stack<std::pair<int, int>> A;
	for (int i = 0, x; i < 2 * n; ++i) {
		char op;
		std::cin >> op;
		if (op == '+') A.push({now++, 0});
		else {
			std::cin >> x;
			if (A.empty() || A.top().second > x) {
				print("NO");
				return 0;
			} else {
				r[A.top().first] = x;
				A.pop();
				if (!A.empty()) A.top().second = std::max(A.top().second, x);
			}
		}
	}
	print("YES");
	for (auto x : r) std::cout << x << " ";
	println;
	return 0;
}