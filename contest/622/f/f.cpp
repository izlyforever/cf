#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
// #include "C:/Users/dna049/cf/include/math.hpp"

// 0 <= x < p < INT_MAX
LL powMod(LL x, LL n, LL p){
	LL r = 1;
	while (n) {
		if (n&1) r = r * x % p;
		n >>= 1; x = x * x % p;
	}
	return r;
}

std::vector<int> spf(int N) {
	std::vector<int> sp(N), p{2};
	for (int i = 2; i < N; i += 2) sp[i] = 2;
	for (int i = 1; i < N; i += 2) sp[i] = i;
	for (int i = 3; i < N; i += 2) {
		if (sp[i] == i) p.emplace_back(i);
		for (int j = 1; j < p.size() && p[j] <= sp[i] && i * p[j] < N; ++j) {
			sp[i * p[j]] = p[j]; // 注意到sp只被赋值一次
		}
	}
	return sp;
}
// 计算在 f 处的 lagrange 函数在 m 点的取值（模 M）
// 保证 M 为素数，0 <= f[i] < M
LL Lagrange(const std::vector<LL> &f, int m, LL M) {
	int n = f.size();
	if (m < n) return f[m];
	LL nfac = 1;
	for (int i = 2; i < n; ++i) nfac = nfac * i % M;
	std::vector<LL> ifac(n), AP(n), BP(n);
	ifac[n - 1] = powMod(nfac, M - 2, M);
	for (int i = n - 1; i > 0; --i) ifac[i - 1] = ifac[i] * i % M;
	AP[0] = BP[n - 1] = 1;
	for (int i = 1; i < n; ++i) AP[i] = AP[i - 1] * (m + 1 - i) % M;
	for (int i = n - 2; ~i; --i) BP[i] = BP[i + 1] * (m - 1 - i) % M;
	LL ans = 0;
	for (int i = 0; i < n; ++i) {
		LL x = f[i] * AP[i] % M * BP[i] % M * ifac[i] % M * ifac[n - 1 - i] % M;
		ans += (n - 1 - i) & 1 ? M - x : x;
	}
	return ans % M;
}
// f(x) =  \sum_{i = 0}^{n - 1} f_i \prod_{j \neq i} \frac{x - j}{i - j}
// f(m) = \sum_{i = 0}^{n - 1} (-1)^{n - 1 - i} f_i \binom{m}{i} \binom{m - i - 1}{n - 1 - i}

LL powSum(LL n, int k, LL M, const std::vector<int> &sp){
	if (k == 0) return n % M;
	std::vector<LL> f(k + 2);
	f[1] = 1;
	for (int i = 2; i < f.size(); ++i) {
		if (sp[i] == i) f[i] = powMod(i, k, M);
		else f[i] = f[sp[i]] * f[i / sp[i]] % M;
	}
	for (int i = 1; i < f.size(); ++i) {
		f[i] += f[i - 1];
		if (f[i] >= M) f[i] -= M;
	}
	return Lagrange(f, n, M);
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	const LL M = 1e9 + 7;
	int n, k;
	std::cin >> n >> k;
	auto sp = spf(k + 2);
	std::cout << powSum(n, k, M, sp) << "\n";
	return 0;
}