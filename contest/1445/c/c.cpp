#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
 
const int N = 4e5+ 2;
bool isp[N];
std::vector<int> p;
int initPrimeP() {
	p.emplace_back(2);
	isp[2] = true;
	for (int i = 3; i < N; i += 2) isp[i] = true;
	int sq = int(std::sqrt(N + 0.1))|1;
	for (int i = 3; i <= sq; i += 2) if (isp[i]) {
		p.emplace_back(i);
		for (int j = i * i; j < N; j += i << 1) {
			isp[j] = false;
		}
	}
	for (int i = sq + 2; i < N; i += 2) if (isp[i]) p.emplace_back(i);
	return p.size();
}
 
std::vector<std::pair<int, int>> factor(int n) {
	std::vector<std::pair<int, int>> r;
	for (int i = 0; p[i] * p[i] <= n; ++i) {
		if (n % p[i] == 0) {
			int t = 1;
			while (n % p[i] == 0) {
				t *= p[i];
				n /= p[i];
			}
			r.push_back({p[i], t / p[i]});
		}
	}
	if (n > 1) r.push_back({n, 1});
	return r;
}
 
int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	initPrimeP();
	while (cas--) {
		LL a;
		int n;
		std::cin >> a >> n;
		if (a % n) {
			std::cout << a << std::endl;
		} else {
			auto f = factor(n);
			LL r = 1;
			for (auto [x, cntx] : f) {
				LL t = a;
				while (t % x == 0) t /= x;
				r = std::max(r, t * cntx);
			}
			std::cout << r << std::endl;
		}
	}
	return 0;
}