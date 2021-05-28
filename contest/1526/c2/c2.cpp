#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::cin >> n;
	int ans = 0;
	std::multiset<int> S;
	LL now = 0;
	for (int i = 0, x; i < n; ++i) {
		std::cin >> x;
		if (x >= 0) {
			++ans;
			now += x;
		} else {
			if (now + x >= 0) {
				++ans;
				now += x;
				S.insert(x);
			} else {
				auto it = S.begin();
				if (*it < x) {
					now += x - *it;
					S.erase(it);
					S.insert(x);
				}
			}
		}
	}
	std::cout << ans << '\n';
	return 0;
}