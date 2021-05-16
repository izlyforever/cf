#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
// #include "test.hpp"

class ModInt {
	inline static int M = 998244353;
	int n;
	int static inv(int x) {
		assert(std::gcd(x, M) == 1);
		return x == 1 ? x : 1LL * (M - M / x) * inv(M % x) % M;
	}
public:
	void static setMod(int m) {
		M = m;
	}
	int static mod() {
		return M;
	}
	ModInt(LL x = 0) : n(x % M) {
		if (n < 0) n += M;
	}
	operator int() const {
		return n;
	}
	ModInt operator-() const {
		return ModInt(n ? M - n : 0);
	}
	ModInt& operator+=(const ModInt &A) {
		n += A.n;
		if (n >= M) n -= M;
		return (*this);
	}
	ModInt& operator-=(const ModInt &A) {
		n -= A.n;
		if (n < 0) n += M;
		return (*this);
	}
	ModInt& operator*=(const ModInt &A) {
		n = 1LL * n * A.n % M;
		return (*this);
	}
	ModInt& operator/=(const ModInt &A) {
		return (*this) *= A.inv();
	}
	ModInt operator+(const ModInt &A) const {
		return ModInt(*this) += A;
	}
	ModInt operator-(const ModInt &A) const {
		return ModInt(*this) -= A;
	}
	ModInt operator*(const ModInt &A) const {
		return ModInt(*this) *= A;
	}
	ModInt operator/(const ModInt &A) const {
		return ModInt(*this) /= A;
	}
	ModInt operator<<(int x) const {
		LL r = n;
		r <<= x;
		return ModInt(r % M);
	}
	ModInt& operator<<=(int x) {
		return (*this) = (*this) << x;
	}
	ModInt& operator>>=(int x) {
		n >>= x;
		return (*this);
	}
	ModInt operator>>(int x) const {
		return ModInt(*this) >> x;
	}
	ModInt operator&(int x) const {
		return ModInt(*this) & x;
	}
	ModInt& operator&=(int x) {
		n &= x;
		return (*this);
	}
	ModInt inv() const {
		return inv(n);
	}
	friend ModInt powMod(ModInt A, int n) {
		ModInt R(1);
		while (n) {
			if (n& 1) R *= A;
			n >>= 1;  A *= A;
		}
		return R;
	}
	friend std::istream &operator>>(std::istream &in, ModInt &A) {
		LL x;
		in >> x;
		A = ModInt(x);
		return in;
	}
	friend std::ostream &operator<<(std::ostream &out, const ModInt &A) {
		out << A.n;
		return out;
	}
};

class PolyV {
	void standard() {
		while (!a.empty() && a.back() == 0) a.pop_back();
	}
	void reverse() {
		std::reverse(a.begin(), a.end());
		standard();
	}
public:
	std::vector<ModInt> a;
	PolyV() {}
	PolyV(ModInt x) { if (x != 0) a = {x};}
	PolyV(const std::vector<ModInt> &_a) : a(_a) { standard();}
	int size() const { return a.size();}
	void resize(int x) { a.resize(x);} 
	ModInt operator[](int id) const {
		if (id < 0 || id > a.size()) return 0;
		return a[id];
	}
	PolyV mulXn(int n) const {
		auto b = a;
		b.insert(b.begin(), n, 0);
		return b;
	}
	PolyV modXn(int n) const {
		if (n > size()) return *this;
		return std::vector<ModInt>{a.begin(), a.begin() + n};
	}
	PolyV divXn(int n) const {
		if (size() <= n) return PolyV();
		return std::vector<ModInt>{a.begin() + n, a.end()};
	}
	PolyV &operator+=(const PolyV &rhs) {
		if (size() < rhs.size()) a.resize(rhs.size());
		for (int i = 0; i < rhs.size(); ++i) a[i] += rhs.a[i];
		standard();
		return *this;
	}
	PolyV &operator-=(const PolyV &rhs) {
		if (size() < rhs.size()) a.resize(rhs.size());
		for (int i = 0; i < rhs.size(); ++i) a[i] -= rhs.a[i];
		standard();
		return *this;
	}
	friend PolyV mul(const PolyV &A, const PolyV &B) {
		int n = A.size(), m = B.size();
		std::vector<ModInt> C(n + m - 1);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				C[i + j] += A.a[i] * B.a[j];
			}
		}
		return C;
	}
	virtual PolyV &operator*=(PolyV rhs) {
		return (*this) = (*this) * rhs;
	}
	PolyV &operator/=(PolyV rhs) {
		int n = size(), m = rhs.size();
		if (n < m) return (*this) = PolyV();
		reverse();
		rhs.reverse();
		(*this) *= rhs.inv(n - m + 1);
		a.resize(n - m + 1);
		reverse();
		return *this;
	}
	PolyV &operator%=(PolyV rhs) {
		return (*this) -= (*this) / rhs * rhs; 
	}
	PolyV operator+(const PolyV &rhs) const {
		return (*this).copy() += rhs;
	}
	PolyV operator-(const PolyV &rhs) const {
		return PolyV(*this) -= rhs;
	}
	virtual PolyV operator*(PolyV rhs) const {
		return mul(*this, rhs);
	}
	PolyV operator/(PolyV rhs) const {
		return PolyV(*this) /= rhs;
	}
	PolyV operator%(PolyV rhs) const {
		return PolyV(*this) %= rhs;
	}
	PolyV powModPoly(int n, PolyV p) {
		PolyV r(1), x(*this);
		while (n) {
			if (n&1) (r *= x) %= p;
			n >>= 1; (x *= x) %= p;
		}
		return r;
	}
	ModInt inner(const PolyV &rhs) {
		ModInt r(0);
		int n = std::min(size(), rhs.size());
		for (int i = 0; i < n; ++i) r += a[i] * rhs.a[i];
		return r;
	}
	PolyV derivation() const {
		if (a.empty()) return PolyV();
		int n = size();
		std::vector<ModInt> r(n - 1);
		for (int i = 1; i < n; ++i) r[i - 1] = a[i] * ModInt(i);
		return PolyV(r);
	}
	PolyV integral() const {
		if (a.empty()) return PolyV();
		int n = size();
		std::vector<ModInt> r(n + 1), inv(n + 1, 1);
		for (int i = 2; i <= n; ++i) inv[i] = ModInt(ModInt::mod() - ModInt::mod() / i) * inv[ModInt::mod() % i];
		for (int i = 0; i < n; ++i) r[i + 1] = a[i] * inv[i + 1];
		return PolyV(r);
	}
	PolyV inv(int n) const {
		assert(a[0] != 0);
		PolyV x(a[0].inv());
		int k = 1;
		while (k < n) {
			k *= 2;
			x *= (PolyV(2) - modXn(k) * x).modXn(k);
		}
		return x.modXn(n);
	}
	// 需要保证首项为 1
	PolyV log(int n) const {
		return (derivation() * inv(n)).integral().modXn(n);
	}
	// 需要保证首项为 0
	PolyV exp(int n) const {
		PolyV x(1);
		int k = 1;
		while (k < n) {
			k *= 2;
			x = (x * (PolyV(1) - x.log(k) + modXn(k))).modXn(k);
		}
		return x.modXn(n);
	}
	// 需要保证首项为 1，开任意次方可以先 ln 再 exp 实现。
	PolyV sqrt(int n) const {
		PolyV x(1), inv2 = ModInt(2).inv();
		int k = 1;
		while (k < n) {
			k *= 2;
			x += modXn(k) * x.inv(k);
			x = x.modXn(k) * inv2;
		}
		return x.modXn(n);
	}
	// 减法卷积，也称转置卷积 {\rm MULT}(F(x),G(x))=\sum_{i\ge0}(\sum_{j\ge 0}f_{i+j}g_j)x^i
	PolyV mulT(PolyV rhs) const {
		if (rhs.size() == 0) return PolyV();
		int n = rhs.size();
		std::reverse(rhs.a.begin(), rhs.a.end());
		return ((*this) * rhs).divXn(n - 1);
	}
	int eval(int x) {
		ModInt r(0), t(1);
		for (int i = 0, n = size(); i < n; ++i) {
			r += a[i] * t;
			t *= x;
		}
		return r;
	}
	// 多点求值新科技：https://jkloverdcoi.github.io/2020/08/04/转置原理及其应用/
	std::vector<ModInt> eval(std::vector<ModInt> x) const {
		if (size() == 0) return std::vector<ModInt>(x.size());
		int n = x.size();
		std::vector<ModInt> ans(n);
		std::vector<PolyV> g(4 * n);
		std::function<void(int, int, int)> build = [&](int l, int r, int p) {
			if (r - l == 1) {
				g[p] = PolyV({1, -x[l]});
			} else {
				int m = (l + r) / 2;
				build(l, m, 2 * p);
				build(m, r, 2 * p + 1);
				g[p] = g[2 * p] * g[2 * p + 1];
			}
		};
		build(0, n, 1);
		std::function<void(int, int, int, const PolyV &)> solve = [&](int l, int r, int p, const PolyV &f) {
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
	} // 模板例题：https://www.luogu.com.cn/problem/P5050
}; // 多项式全家桶测试：https://www.luogu.com.cn/training/3015#information

namespace FFT {
const double PI = std::acos(-1);
using C = std::complex<double>;
std::vector<int> rev;
std::vector<C> roots{C(0, 0), C(1, 0)};
void dft(std::vector<C> &a) {
	int n = a.size();
	if (rev.size() != n) {
		int k = __builtin_ctz(n) - 1;
		rev.resize(n);
		for (int i = 0; i < n; ++i) {
			rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
		}
	}
	if (roots.size() < n) {
		int k = __builtin_ctz(roots.size());
		roots.resize(n);
		while ((1 << k) < n) {
			C e = std::polar(1.0, PI / (1 << k));
			for (int i = 1 << (k - 1); i < (1 << k); ++i) {
				roots[2 * i] = roots[i];
				roots[2 * i + 1] = roots[i] * e;
			}
			++k;
		}
	}
	for (int i = 0; i < n; ++i) if (rev[i] < i) {
		std::swap(a[i], a[rev[i]]);
	}
	for (int k = 1; k < n; k *= 2) {
		for (int i = 0; i < n; i += 2 * k) {
			for (int j = 0; j < k; ++j) {
				auto u = a[i + j], v = a[i + j + k] * roots[k + j];
				a[i + j] = u + v;
				a[i + j + k] = u - v;
			}
		}
	}
}
void idft(std::vector<C> &a) {
	int n = a.size();
	std::reverse(a.begin() + 1, a.end());
	dft(a);
	for (auto &x : a) x /= n;
}	
} // namespace FFT 
// 模板例题：https://www.luogu.com.cn/problem/P3803

class PolyFFT : public PolyV {
public:
	using PolyV::PolyV;
	PolyFFT(const PolyV &A) : PolyV(A) {}
	friend PolyFFT mulFFTCore(PolyFFT A, PolyFFT B, int sz) {
		std::vector<std::complex<double>> C(sz);
		for (int i = 0; i < A.size(); ++i) C[i].real(A[i]);
		for (int i = 0; i < B.size(); ++i) C[i].imag(B[i]);
		FFT::dft(C);
		for (auto &x : C) x *= x;
		FFT::idft(C);
		std::vector<ModInt> ans(A.size() + B.size() - 1);
		for (int i = 0; i < ans.size(); ++i) ans[i] = ModInt(C[i].imag() / 2 + 0.5);
		return PolyFFT(ans);
	}
	friend PolyFFT mulFFT(PolyFFT A, PolyFFT B) {
		int n = std::max(A.size(), B.size()), tot = std::max(1, n * 2 - 1);
		int sz = 1 << std::__lg(tot * 2 - 1);
		// return mulCore(A, B, sz); // 为了保证精度必须拆分
		auto A2 = A, B2 = B;
		const static int bit = 15, msk = (1 << bit) - 1;
		for (auto &x : A.a) x >>= bit;
		for (auto &x : A2.a) x &= msk;
		for (auto &x : B.a) x >>= bit;
		for (auto &x : B2.a) x &= msk;
		PolyFFT ans = mulFFTCore(A, B, sz);
		for (auto &x : ans.a) x <<= bit;
		ans += mulFFTCore(A2, B, sz);
		ans += mulFFTCore(A, B2, sz);
		for (auto &x : ans.a) x <<= bit;
		ans += mulFFTCore(A2, B2, sz);
		return ans;
	}
	PolyFFT operator*(PolyFFT rhs) const {
		return mulFFT(*this, rhs);
	}
	PolyFFT &operator*=(PolyFFT rhs) {
		return (*this) = (*this) * rhs;
	}
	PolyFFT inv(int n) const {
		assert(a[0] != 0);
		PolyFFT x(a[0].inv());
		int k = 1;
		while (k < n) {
			k *= 2;
			x *= (PolyFFT(2) - modXn(k) * x).modXn(k);
		}
		return x.modXn(n);
	}
};

template<int N>
class NFT {
	inline const static int g = 3, M = N;
	std::vector<int> rev, roots{0, 1};
public:
	int powMod(int x, int n) {
		int r(1);
		while (n) {
			if (n&1) r = 1LL * r * x % M;
			n >>= 1; x = 1LL * x * x % M;
		}
		return r;
	}
	void dft(std::vector<int> &a) {
		int n = a.size();
		if (rev.size() != n) {
			int k = __builtin_ctz(n) - 1;
			rev.resize(n);
			for (int i = 0; i < n; ++i) {
				rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
			}
		}
		if (roots.size() < n) {
			int k = __builtin_ctz(roots.size());
			roots.resize(n);
			while ((1 << k) < n) {
				int e = powMod(g, (M - 1) >> (k + 1));
				for (int i = 1 << (k - 1); i < (1 << k); ++i) {
					roots[2 * i] = roots[i];
					roots[2 * i + 1] = 1LL * roots[i] * e % M;
				}
				++k;
			}
		}
		for (int i = 0; i < n; ++i) if (rev[i] < i) {
			std::swap(a[i], a[rev[i]]);
		}
		for (int k = 1; k < n; k *= 2) {
			for (int i = 0; i < n; i += 2 * k) {
				for (int j = 0; j < k; ++j) {
					int u = a[i + j];
					int v = 1LL * a[i + j + k] * roots[k + j] % M;
					int x = u + v, y = u - v;
					if (x >= M) x -= M;
					if (y < 0) y += M;
					a[i + j] = x;
					a[i + j + k] = y;
				}
			}
		}
	}
	void idft(std::vector<int> &a) {
		int n = a.size();
		std::reverse(a.begin() + 1, a.end());
		dft(a);
		int inv = powMod(n, M - 2);
		for (int i = 0; i < n; ++i) {
			a[i] = 1LL * a[i] * inv % M;
		}
	}
};

NFT<998244353> nft;
class PolyNFT : public PolyV {
public:
	inline const static int M = 998244353;
	// inline static NFT<M> nft;
	using PolyV::PolyV;
	PolyNFT(const PolyV &A) : PolyV(A) {}
	friend PolyNFT mulNFT(const PolyNFT &A, const PolyNFT &B) {
		int n = A.size(), m = B.size(), tot = std::max(1, n + m - 1);
		int sz = 1 << std::__lg(tot * 2 - 1);
		std::vector<int> a(n), b(m);
		for (int i = 0; i < n; ++i) a[i] = A.a[i];
		for (int i = 0; i < m; ++i) b[i] = B.a[i];
		a.resize(sz); b.resize(sz);
		nft.dft(a);
		nft.dft(b);
		for (int i = 0; i < sz; ++i) {
			a[i] = 1LL * a[i] * b[i] % M;
		}
		nft.idft(a);
		std::vector<ModInt> ans(n + m - 1);
		for (int i = 0; i < ans.size(); ++i) ans[i] = ModInt(a[i]);
		return PolyNFT(ans);
	}
	PolyNFT operator*(PolyNFT rhs) const {
		return mulNFT(*this, rhs);
	}
	PolyNFT &operator*=(PolyNFT rhs) {
		return (*this) = (*this) * rhs;
	}
	PolyNFT inv(int n) const {
		assert(a[0] != 0);
		PolyNFT x(a[0].inv());
		int k = 1;
		while (k < n) {
			k *= 2;
			x *= (PolyNFT(2) - modXn(k) * x).modXn(k);
		}
		return x.modXn(n);
	}
};

template<typename T>
void debug(std::vector<T> a){
	for (auto &i : a) std::cout << i << ' ';
	std::cout << std::endl; 
}

// int main() {
// 	//freopen("in", "r", stdin);
// 	std::cin.tie(nullptr)->sync_with_stdio(false);
// 	ModInt::setMod(1e9 + 7);
// 	int n, k;
// 	std::cin >> n >> k;
// 	PolyNFT Numerator = PolyNFT({0, n}).exp(k + 2).divXn(1);
// 	PolyNFT denominator  = PolyNFT({0, 1}).exp(k + 2).divXn(1);
// 	auto f = (Numerator * denominator.inv(k + 1)).modXn(k + 1).a;
// 	f.resize(k + 1);
// 	std::vector<ModInt> g(k + 1);
// 	LL now = 1;
// 	for (int i = 1; i <= k; ++i) {
// 		g[i] = f[i] * ModInt(i & 1 ? now : -now);
// 		now = now * i % ModInt::mod();
// 	}
// 	auto ans = PolyNFT(g).exp(k + 1).a;
// 	ans.resize(k + 1);
// 	LL s[2]{1, 0};
// 	for (int i = 1; i <= k; ++i) {
// 		if ((s[i & 1] += ans[i]) >= ModInt::mod()) s[i & 1] -= ModInt::mod();
// 		std::cout << s[i & 1] << ' ';
// 	}
// 	std::cout << '\n';
// 	return 0;
// }

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n;
	std::cin >> n;
	std::vector<ModInt> a(n);
	for (auto &x : a) std::cin >> x;
	PolyFFT A(a);
	auto b = A.inv(n);
	for (int i = 0; i < n; ++i) std::cout << b[i] << ' ';
	std::cout << "\n";
	return 0;
}