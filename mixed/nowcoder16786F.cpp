#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;
// #include "include/izlyforever.hpp"

const int M = 1e9 + 7;
constexpr int N = 5e6 + 2;
// 函数 O(N) 预处理 Euler 函数
std::vector<int> initPhi(int N) {
	std::vector<int> phi(N), p{0, 2};
	for (int i = 1; i < N; i += 2) phi[i] = i;
	for (int i = 2; i < N; i += 2) phi[i] = i >> 1;
	for (int i = 3; i < N; i += 2) {
		if (phi[i] == i) p.emplace_back(i), --phi[i];
		for (int j = 2, t = (N - 1) / i + 1, np = p.size(); j < np && p[j] < t; ++j) {
			if (i % p[j] == 0) {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
			phi[i * p[j]] = phi[i] * (p[j] - 1);
		}
	}
	for (int i = 2; i < N; i += 4) phi[i] = phi[i >> 1];
	for (int i = 4; i < N; i += 4) phi[i] = phi[i >> 1] << 1;
	return phi;
}
// Euler 函数前缀和
std::vector<LL> sumPhi(N);
std::unordered_map<LL, LL> mpPhi;
void initSumPhi() {
	auto phi = initPhi(N);
	for (int i = 1; i < N; ++i) sumPhi[i] = sumPhi[i - 1] + phi[i];
}
LL getSumPhi(LL n) {
	if (n < N) return sumPhi[n];
	if (mpPhi.count(n)) return mpPhi[n];
	LL r = (n + 1) * n / 2;
	for (LL i = 2, j; i <= n; i = j + 1) {
		j = n / (n / i);
		r -= (j - i + 1) * getSumPhi(n / i);
	}
	return mpPhi[n] = r;
}

int main() {
	// freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	auto start = std::clock();
	initSumPhi();
	int n, m;
	std::cin >> n >> m;
	LL ans = 0;
	for (int i = 1, j; i <= n && i <= m; i = j + 1) {
		j = std::min(n / (n / i), m / (m / i));
		ans += (getSumPhi(j) - getSumPhi(i - 1)) % M * (n / i) % M * (m / i) % M;
	}
	std::cout << ((ans % M + M) * 4 % M + 1LL * (n - m) * (n - m)) % M;
	std::clog << "Time used: " << (std::clock() - start) << "ms" << std::endl;
	return 0;
}