#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		LL x1, y1, x2, y2, x3, y3;
		std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		x1 -= x3; y1 -= y3;
		x2 -= x3; y2 -= y3;
		LL tmp = std::gcd(std::gcd(x1, y1), std::gcd(x2, y2));
		x1 /= tmp, x2 /= tmp, y1 /= tmp, y2 /= tmp;
		x3 = x1 - x2; y3 = y1 - y2;
		LL d1 = x1 * x1 + y1 * y1;
		LL d2 = x2 * x2 + y2 * y2;
		LL d3 = x3 * x3 + y3 * y3;
		LL d = std::gcd(d1, std::gcd(d2, d3));
		// 根据定理可知，d 一定可以写成两个平方因子之和!
		if (d != 1) {
			for (LL i = 1; i * i <= d; ++i) {
				LL tmp = d - i * i;
				LL j = std::sqrt(tmp + 0.2);
				if (j * j == tmp && ((i * x1 + j * y1) % d == 0 || (j * x1 + i * y1) % d == 0)) {
					if ((i * x1 + j * y1) % d) std::swap(i, j);
					std::tie(x1, y1) = std::pair(i * x1 + j * y1, i * y1 - j * x1);
					std::tie(x2, y2) = std::pair(i * x2 + j * y2, i * y2 - j * x2);
					x1 /= d, y1 /= d;
					x2 /= d, y2 /= d;
					break;
				}
			}
		}
		const LL N = 1e9;
		x3 = y3 = 0;
		LL mx = std::max({x1, x2, x3});
		if (mx > N) {
			x1 -= mx - N;
			x2 -= mx - N;
			x3 -= mx - N;
		}
		mx = std::min({x1, x2, x3});
		if (mx < -N) {
			x1 += -N - mx;
			x2 += -N - mx;
			x3 += -N - mx;
		}
		LL my = std::max({y1, y2, y3});
		if (my > N) {
			y1 -= my - N;
			y2 -= my - N;
			y3 -= my - N;
		}
		my = std::min({y1, y2, y3});
		if (my < -N) {
			y1 += -N - my;
			y2 += -N - my;
			y3 += -N - my;
		}
		std::cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << ' ' << x3 << ' ' << y3 << '\n';
	}
	return 0;
}