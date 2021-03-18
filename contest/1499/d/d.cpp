#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

std::vector<int> spf(int N) {
	std::vector<int> sp(N), p{0, 2};
	for (int i = 2; i < N; i += 2) sp[i] = 2;
	for (int i = 1; i < N; i += 2) sp[i] = i;
	for (int i = 3; i < N; i += 2) {
		if (sp[i] == i) p.emplace_back(i);
		for (int j = 2; j < p.size() && p[j] <= sp[i] && i * p[j] < N; ++j) {
			sp[i * p[j]] = p[j]; // 注意到sp只被赋值一次
		}
	}
	return sp;
}
auto sp = spf(2e7 + 2);

int factor(int n) {
	int r = 0;
	while (n > 1) {
		++r;
		int sn = sp[n];
		while (n % sn == 0) n /= sn;
	}
	return r;
}

LL solve() {
	int a, b, c;
	std::cin >> a >> b >> c;
	int d = std::gcd(a, b);
	if (c % d) return 0;
	c /= d;
	a /= d;
	b /= d;
	LL r = 0;
	for (int i = 1; i * i <= c; ++i) if (c % i == 0) {
		std::set<int> S{b + i, b + c / i};
		for (auto x: S) {
			if (x % a == 0) {
				int fx = factor(x / a);
				r += 1 << fx;
			}
		}
	}
	return r;
}

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		std::cout << solve() << '\n';
	}
	return 0;
}