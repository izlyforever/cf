#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

namespace NFT {
LL M = 998244353, ROOT = 3;
void setM(LL _m, LL _root) {
	M = _m; ROOT = _root;
}
LL powMod(LL x, LL n) {
	LL r(1);
	while (n) {
		if (n & 1) r = r * x % M;
		n >>= 1;
		x = x * x % M;
	}
	return r;
}
void bitreverse(std::vector<LL> &a) {
	for (int i = 0, j = 0; i != a.size(); ++i) {
		if (i > j) std::swap(a[i], a[j]);
		for (int l = a.size() >> 1;
			(j ^= l) < l; l >>= 1);
	}
}
void nft(std::vector<LL> &a, bool isInverse = false) {
	LL g = powMod(ROOT, (M - 1) / a.size());
	if (isInverse) {
		g = powMod(g, M - 2);
		LL invLen = powMod(LL(a.size()), M - 2);
		for (auto & x: a) x = x * invLen % M;
	}
	bitreverse(a);
	std::vector<LL> w(a.size(), 1);
	for (int i = 1; i != w.size(); ++i) w[i] = w[i - 1] * g % M;
	auto addMod = [](LL x, LL y) {
		return (x += y) >= M ? x -= M : x;
	};
	for (int step = 2, half = 1; half != a.size(); step <<= 1, half <<= 1) {
		for (int i = 0, wstep = a.size() / step; i != a.size(); i += step) {
			for (int j = i; j != i + half; ++j) {
				LL t = (a[j + half] * w[wstep * (j - i)]) % M;
				a[j + half] = addMod(a[j], M - t);
				a[j] = addMod(a[j], t);
			}
		}
	}
}
void mul(std::vector<LL>& a, std::vector<LL> b) {
	int sz = 1, tot = a.size() + b.size() - 1;
	while (sz < tot) sz *= 2;
	a.resize(sz);
	b.resize(sz);
	nft(a);
	nft(b);
	for (int i = 0; i != sz; ++i) a[i] = a[i] * b[i] % M;
	nft(a, 1);
	a.resize(tot);
}
// 递归版本
std::vector<LL> inv(std::vector<LL> a, int n) {
	if (n == 1) return std::vector<LL>({powMod(a[0], M - 2)});
	std::vector<LL> invA(n), b = inv(a, (n + 1) / 2);
	a.resize(n); mul(a, b); a.resize(n);
	invA[0] = (M + 2 - a[0]) % M;
	for (int i = 1; i < n; ++i) invA[i] = (a[i] == 0 ? 0 : M - a[i]);
	mul(invA, b); invA.resize(n);
	return std::move(invA);
}
// 非递归版本实测要慢一些（不敢相信）
std::vector<LL> invS(std::vector<LL> a, int n) {
	assert(a[0] != 0);
	std::vector<LL> invA({powMod(a[0], M - 2)});
	for (int sz = 1; sz < n; sz *= 2) {
		auto aa = a;
		aa.resize(2 * sz);
		mul(aa, invA);
		std::vector<LL> invAA(2 * sz);
		invAA[0] = (M + 2 - aa[0]) % M;
		for (int i = 1; i < 2 * sz; ++i) invAA[i] = (aa[i] == 0 ? 0 : M - aa[i]);
		mul(invAA, invA);
		invAA.resize(2 * sz);
		std::swap(invAA, invA);
	}
	return std::move(invA);
}
} // namespace NFT

LL powMod(LL x, LL n, LL p){
	LL r = 1;
	while (n) {
		if (n&1) r = r * x % p;
		n >>= 1; x = x * x % p;
	}
	return r;
}

namespace Binom {
int N = 0;
LL M = 1e9 + 7;
std::vector<LL> fac, ifac;
void setMod(LL m) { 
	M = m;
	fac[0] = 1;
	for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % M;
	ifac[N - 1] = powMod(fac[N - 1], M - 2, M);
	for (int i = N - 1; i; --i) ifac[i - 1] = ifac[i] * i % M;
}
void init(int n, LL m) {
	N = n;
	fac.resize(N);
	ifac.resize(N);
	setMod(m);
}
// 需要预处理小于 n 的所有值！
LL binom(int n, int k) {
	if (n < 0 || n < k) return 0;
	return fac[n] * ifac[k] % M * ifac[n - k] % M;
}
// 一般说来需要预处理出小于 M 的所有值，且 M 是素数！
LL lucas(LL n, LL k) {
	LL r = 1;
	while (n && k) {
		int np = n % M, kp = k % M;
		if (np < kp) return 0;
		r = r * binom(np, kp) % M;
		n /= M; k /= M;
	}
	return r;
}
} // namespace Binom

// ans[i] = 1^i + 2^i + ... + n^i, 0 < i < k
std::vector<LL> powSum(LL n, int k, LL M){
	auto e = Binom::ifac;
	e.resize(k + 1);
	auto b = e;
	for (int i = 0; i < k; ++i) b[i] = b[i + 1];
	b.resize(k);
	auto a = b;
	LL r = 1, x = n % M;
	for (int i = 0; i < k; ++i) {
		r = r * x % M;
		a[i] = a[i] * r % M;
	}
	NFT::mul(a, NFT::inv(b, k));
	a.resize(k);
	NFT::mul(e, a);
	e.resize(k);
	for (int i = 0; i < k; ++i) e[i] = e[i] * Binom::fac[i] % M;
	return e;
}

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	LL R;
	int B;
	std::cin >> R >> B;
	const LL M = 998244353;
	Binom::init(B + 12, M);
	LL N = R / B, RM = R % M;
	std::vector<LL> f(B + 1);
	f[0] = 1;
	for (int i = 1; i <= B; ++i) {
		f[i] = f[i - 1] * (RM + B + 2 - i) % M;
	}
	for (int i = 1; i <= B; ++i) f[i] = f[i] * Binom::ifac[i] % M;
	auto g = powSum(N, B + 2, M);
	LL r1 = 0;
	for (int i = 0; i <= B; ++i) r1 = (r1 + f[i] * g[B - i]) % M;
	r1 = (R + 1) % M * r1 % M;
	LL r2 = 0;
	for (int i = 0; i <= B; ++i) r2 = (r2 + f[i] * g[B + 1 - i]) % M;
	r2 = r2 * B % M;
	std::cout << (r1 + M - r2) % M << "\n";
	return 0;
}