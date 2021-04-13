#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
 
const LL M = 998244353;
const int N = 3e5 + 2;
LL fac[N], ifac[N];
LL inv(LL a, LL p){ // 0 < a < p and gcd(a,p) = 1
	return a == 1 ? 1 : (p - p / a) * inv(p % a, p) % p;
}
void init() {
	fac[0] = 1;
	for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % M;
	ifac[N - 1] = inv(fac[N - 1], M);
	for (int i = N - 1; i; --i) ifac[i - 1] = ifac[i] * i % M;
}
LL binom(int n, int k) {
	if (n < k) return 0;
	return fac[n] * ifac[k] % M * ifac[n - k] % M;
}
 
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	init();
	int n, k;
	std::cin >> n >> k;
	std::vector<std::pair<int, int>> a;
	for (int i = 0, x, y; i < n; ++i) {
		std::cin >> x >> y;
		a.push_back({x, 1});
		a.push_back({y + 1, -1});
	}
	std::sort(a.begin(), a.end());
	LL r = 0;
	int now = 0;
	for (auto [x, y]: a) {
		if (y == 1) r += binom(now, k - 1);
		now += y;
	}
	print(r % M);
	return 0;
}