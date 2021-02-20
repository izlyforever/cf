#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, p, k, x, y;
		std::string s;
		std::cin >> n >> p >> k >> s >> x >> y; 
		std::reverse(s.begin(),s.end());
		std::vector<int> a(n), cnt(k);
		std::set<int> S;
		for (int i = 0; i < n; ++i) {
			if (s[i] == '0') ++cnt[i % k];
			a[i] = cnt[i % k] * x;
			if (!S.empty()) a[i] = std::min(a[i], *S.begin() + i * y);
			S.insert(a[i] - i * y);
		}
		std::cout << a[n - p] << std::endl;
	}
	return 0;
}