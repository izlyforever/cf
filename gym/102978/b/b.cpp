#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// 0 <= x < p < INT_MAX
LL powMod(LL x, LL n, LL p){
	LL r = 1;
	while (n) {
		if (n&1) r = r * x % p;
		n >>= 1; x = x * x % p;
	}
	return r;
}

// 一般情况下 N < 1e6, M 必须是一个小于 INT_MAX 的素数
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
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (auto &x : a) std::cin >> x;
	const LL M = 998244353;
	Binom::init(n, M);
	std::vector<LL> x(n);
	x[0] = 1;
	for (int i = 1; i < n; ++i) x[i] = x[i - 1] * (2 * i - 1) % M;
	LL r = 0;
	for (int i = 0; i < n; ++i) if (a[i] == 1) {
		r += Binom::binom(n - 1, i) * x[i] % M * x[n - 1 - i] % M;
	}
	std::cout << r % M << "\n";
	return 0;
}