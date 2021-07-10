#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int query(int t, int l, int r, int x) {
	std::cout << "? " << t << ' ' << l << ' ' << r << ' ' << x << std::endl;
	int ans;
	std::cin >> ans;
	return ans;
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::vector<int> p(n + 1);
		auto queryMax = [&](int l, int r) {
			return query(1, l, r, n - 1);
		};
		auto queryMin = [&](int l, int r) {
			return query(2, l, r, 1);
		};
		// 想根据 p1, p2 的最大值 以及 p1, p3 的最大值确定其中一个数
		int a12 = std::max(queryMax(1, 2), queryMax(2, 1));
		int a13 = std::max(queryMax(1, 3), queryMax(3, 1));
		int now = 0;
		if (a12 == a13) {
			now = 1;
			p[now] = a12;
		} else if (a12 > a13) {
			now = 2;
			p[now] = a12;
		} else {
			now = 3;
			p[now] = a13;
		}
		// 根据确定的这个数分情况讨论即可，注意此时 p[now] > 2
		if (p[now] > n / 2) {
			for (int i = 1; i <= n; ++i) if (p[i] == 0) {
				int x = queryMin(i, now);
				if (x == p[now]) {
					p[i] = queryMax(now, i);
					now = i;
				} else {
					p[i] = x;
				}
			}
		} else {
			for (int i = 1; i <= n; ++i) if (p[i] == 0) {
				int x = queryMax(now, i);
				if (x == p[now]) {
					p[i] = queryMin(i, now);
					now = i;
				} else {
					p[i] = x;
				}
			}
		}
		std::cout << "!";
		for (int i = 1; i <= n; ++i) std::cout << ' ' << p[i];
		std::cout << std::endl;
	}
	return 0;
}