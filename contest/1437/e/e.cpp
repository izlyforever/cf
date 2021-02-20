#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n + 2);
	a[0] = -1e9 - 2, a[n + 1] = 1e9 + 2;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		a[i] -= i;
	}
	std::vector<int> b(k + 2);
	b[0] = 0, b[k + 1] = n + 1;
	for (int i = 1; i <= k; ++i) std::cin >> b[i];
	for (int i = 2; i <= k; ++i) if (a[b[i]] < a[b[i - 1]]){
		print(-1);
		return 0;
	}
	int r = n - k;
	for (int i = 0; i <= k; ++i) {
		int now = 0;
		std::vector<int> c;
		for (int j = b[i] + 1; j < b[i + 1]; ++j) {
			if (a[j] >= a[b[i]] && a[j] <= a[b[i + 1]]) {
				auto it = std::upper_bound(c.begin(), c.end(), a[j]);
				if (it == c.end()) c.push_back(a[j]);
				else *it = a[j];
			}
		}
		r -= c.size();
	}
	print(r);
	return 0;
}