#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// 借鉴了 jiangly 的模板
namespace NTT {
const LL M = 998244353, g = 3;
std::vector<int> rev, roots{0, 1};
LL powMod(LL x, LL n) {
	LL r(1);
	while (n) {
		if (n & 1) r = r * x % M;
		n >>= 1; x = x * x % M;
	}
	return r;
}
void dft(std::vector<LL> &a) {
	int n = a.size();
	if (rev.size() != n) {
		int k = __builtin_ctz(n) - 1;
		rev.resize(n);
		for (int i = 0; i < n; ++i) {
			rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
		}
	}
	for (int i = 0; i < n; ++i) if (rev[i] < i) {
		std::swap(a[i], a[rev[i]]);
	}
	if (roots.size() < n) {
		int k = __builtin_ctz(roots.size());
		roots.resize(n);
		while ((1 << k) < n) {
			LL e = powMod(3, (M - 1) >> (k + 1));
			for (int i = 1 << (k - 1); i < (1 << k); ++i) {
				roots[2 * i] = roots[i];
				roots[2 * i + 1] = roots[i] * e % M;
			}
			++k;
		}
	}
	for (int k = 1; k < n; k *= 2) {
		for (int i = 0; i < n; i += 2 * k) {
			for (int j = 0; j < k; ++j) {
				LL u = a[i + j];
				LL v = a[i + j + k] * roots[k + j] % M;
				LL x = u + v, y = u - v;
				if (x >= M) x -= M;
				if (y < 0) y += M;
				a[i + j] = x;
				a[i + j + k] = y;
			}
		}
	}
}
void idft(std::vector<LL> &a) {
	int n = a.size();
	std::reverse(a.begin() + 1, a.end());
	dft(a);
	LL inv = powMod(n, M - 2);
	for (int i = 0; i < n; ++i) {
		a[i] = a[i] * inv % M;
	}
}
} //namespace NTT

class Poly {
	void standard() {
		while (!a.empty() && !a.back()) a.pop_back();
	}
public:
	inline const static LL M = NTT::M, inv2 = (M + 1) / 2;
	std::vector<LL> a;
	Poly() {}
	Poly(LL x) { if (x) a = {x};}
	Poly(const std::vector<LL> _a) : a(_a) { standard();}
	int size() const { return a.size();}
	LL operator[](int id) const {
		if (id < 0 || id > a.size()) return 0;
		return a[id];
	}
	Poly mulXn(int n) const {
		auto b = a;
		b.insert(b.begin(), n, 0);
		return Poly(b);
	}
	Poly modXn(int n) const {
		if (n > size()) return *this;
		return Poly(std::vector<LL>(a.begin(), a.begin() + n));
	}
	Poly divXn(int n) const {
		if (size() <= n) return Poly();
		return Poly(std::vector<LL>(a.begin() + n, a.end()));
	}
	Poly &operator+=(const Poly &A) {
		if (size() < A.size()) a.resize(A.size());
		for (int i = 0; i < A.size(); ++i) {
			if ((a[i] += A.a[i]) >= M) a[i] -= M;
		}
		standard();
		return *this;
	}
	Poly &operator-=(const Poly &rhs) {
		if (size() < rhs.size()) a.resize(rhs.size());
		for (int i = 0; i < rhs.size(); ++i) {
			if ((a[i] -= rhs.a[i]) < 0) a[i] += M;
		}
		standard();
		return *this;
	}
	Poly &operator*=(Poly rhs) {
		int n = size(), m = rhs.size(), tot = n + m - 1, sz = 1;
		while (sz < tot) sz *= 2;
		a.resize(sz);
		rhs.a.resize(sz);
		NTT::dft(a);
		NTT::dft(rhs.a);
		for (int i = 0; i < sz; ++i) {
			a[i] = a[i] * rhs.a[i] % M;
		}
		NTT::idft(a);
		standard();
		return *this;
	}
	Poly operator+(const Poly &rhs) const {
		return Poly(*this) += rhs;
	}
	Poly operator-(const Poly &rhs) const {
		return Poly(*this) -= rhs;
	}
	Poly operator*(Poly rhs) const {
		return Poly(*this) *= rhs;
	}
	Poly derivation() const {
		if (a.empty()) return Poly();
		int n = size();
		std::vector<LL> r(n - 1);
		for (int i = 1; i < n; ++i) r[i - 1] =  a[i] * i % M;
		return Poly(r);
	}
	Poly integral() const {
		if (a.empty()) return Poly();
		int n = size();
		std::vector<LL> r(n + 1), inv(n + 1);
		inv[1] = 1;
		for (int i = 2; i <= n; ++i) inv[i] = (M - M / i) * inv[M % i] % M;
		for (int i = 0; i < n; ++i) r[i + 1] = a[i] * inv[i + 1] % M;
		return Poly(r);
	}
	Poly inv(int n) const {
		Poly x(NTT::powMod(a[0], M - 2));
		int k = 1;
		while (k < n) {
			k *= 2;
			x *= (Poly(2) - modXn(k) * x).modXn(k);
		}
		return x.modXn(n);
	}
	Poly log(int n) const {
		return (derivation() * inv(n)).integral().modXn(n);
	}
	Poly exp(int n) const {
		Poly x(1);
		int k = 1;
		while (k < n) {
			k *= 2;
			x = (x * (Poly(1) - x.log(k) + modXn(k))).modXn(k);
		}
		return x.modXn(n);
	}
	Poly sqrt(int n) const {
		Poly x(1);
		int k = 1;
		while (k < n) {
			k *= 2;
			x = (x + (modXn(k) * x.inv(k)).modXn(k) * (inv2 % M));
		}
		return x.modXn(n);
	}
	// 减法卷积，也称转置卷积
	Poly mulT(Poly rhs) const {
		if (rhs.size() == 0) return Poly();
		int n = rhs.size();
		std::reverse(rhs.a.begin(), rhs.a.end());
		return ((*this) * rhs).divXn(n - 1);
	}
	// 多点求值新科技：https://jkloverdcoi.github.io/2020/08/04/转置原理及其应用/
	std::vector<LL> eval(std::vector<LL> x) const {
		if (size() == 0) return std::vector<LL>(x.size());
		int n = x.size();
		std::vector<LL> ans(n);
		std::vector<Poly> g(4 * n);
		std::function<void(int, int, int)> build = [&](int l, int r, int p) {
			if (r - l == 1) {
				g[p] = std::vector<LL>{1, (M - x[l]) % M};
			} else {
				int m = (l + r) / 2;
				build(l, m, 2 * p);
				build(m, r, 2 * p + 1);
				g[p] = g[2 * p] * g[2 * p + 1];
			}
		};
		build(0, n, 1);
		std::function<void(int, int, int, const Poly &)> solve = [&](int l, int r, int p, const Poly &f) {
			if (r - l == 1) {
				ans[l] = f[0];
			} else {
				int m = (l + r) / 2;
				solve(l, m, 2 * p, f.mulT(g[2 * p + 1]).modXn(m - l));
				solve(m, r, 2 * p + 1, f.mulT(g[2 * p]).modXn(r - m));
			}
		};
		solve(0, n, 1, mulT(g[1].inv(size())).modXn(n));
		return ans;
	}
};

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
std::vector<LL> powSum(LL n, int k){
	auto e = Binom::ifac;
	e.resize(k + 1);
	auto b = e;
	for (int i = 0; i < k; ++i) b[i] = b[i + 1];
	b.resize(k);
	auto a = b;
	LL M = Poly::M, r = 1, x = n % M;
	for (int i = 0; i < k; ++i) {
		r = r * x % M;
		a[i] = a[i] * r % M;
	}
	Poly A(a), B(b), E(e);
	A *= B.inv(k);
	A.modXn(k);
	E *= A;
	e = E.a;
	e.resize(k);
	for (int i = 0; i < k; ++i) e[i] = e[i] * Binom::fac[i] % M;
	return e;
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
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
	auto g = powSum(N, B + 2);
	LL r1 = 0;
	for (int i = 0; i <= B; ++i) r1 = (r1 + f[i] * g[B - i]) % M;
	r1 = (R + 1) % M * r1 % M;
	LL r2 = 0;
	for (int i = 0; i <= B; ++i) r2 = (r2 + f[i] * g[B + 1 - i]) % M;
	r2 = r2 * B % M;
	std::cout << (r1 + M - r2) % M << "\n";
	return 0;
}