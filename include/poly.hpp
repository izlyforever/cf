#pragma once
#include <bits/stdc++.h>
#include "primary.hpp"
using LL = long long;

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

// 为了支持三模数，改成模板类的形式
template<int N>
class NFT {
	std::vector<int> rev, roots{0, 1};
public:
	inline const static int g = 3, M = N;
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

// 多项式底层基类，不能放带 PolyBase 返回值的，不然很麻烦
class PolyBase {
protected:
	void standard() {
		while (!a.empty() && a.back() == 0) a.pop_back();
	}
	void reverse() {
		std::reverse(a.begin(), a.end());
		standard();
	}
public:
	std::vector<ModInt> a;
	PolyBase() {}
	PolyBase(ModInt x) { if (x != 0) a = {x};}
	PolyBase(const std::vector<ModInt> _a) : a(_a) { standard();}
	int size() const { return a.size();}
	ModInt &operator[](int id) { return a[id];}
	ModInt at(int id) const {
		if (id < 0 || id > a.size()) return 0;
		return a[id];
	}
};

class PolyBaseNFT : public PolyBase {
protected:
	PolyBaseNFT mul(const PolyBaseNFT &rhs) const {
		int n = this->size(), m = rhs.size(), tot = std::max(1, n + m - 1);
		int sz = 1 << std::__lg(tot * 2 - 1);
		std::vector<int> a(n), b(m);
		for (int i = 0; i < n; ++i) a[i] = this->a[i];
		for (int i = 0; i < m; ++i) b[i] = rhs.a[i];
		a.resize(sz); b.resize(sz);
		nft.dft(a);
		nft.dft(b);
		for (int i = 0; i < sz; ++i) {
			a[i] = 1LL * a[i] * b[i] % M;
		}
		nft.idft(a);
		std::vector<ModInt> ans(n + m - 1);
		for (int i = 0; i < ans.size(); ++i) ans[i] = ModInt(a[i]);
		return PolyBaseNFT(ans);
	}
public:
	inline const static int M = 998244353;
	inline static NFT<M> nft;
	using PolyBase::PolyBase;
	PolyBaseNFT(const PolyBase &A) : PolyBase(A) {}
};

class PolyBaseMFT : public PolyBase {
protected:
	static ModInt crt(int a0, int a1, int a2) {
		int t0 = nft1.powMod(M0, M1 - 2);
		LL x = (a0 + 1LL * (a1 - a0) * t0 % M1 * M0) % M01;
		if (x < 0) x += M01;
		int t1 = nft2.powMod(M01 % M2, M2 - 2);
		LL y = (a2 - x) % M2;
		if (y < 0) y += M2;
		y = y * t1 % M2;
		if (y < 0) y += M01;
		return ModInt(x) + ModInt(y) * ModInt(M01);
	}
	PolyBaseMFT mul(const PolyBaseMFT &rhs) const {
		int tot = std::max(1, this->size() + rhs.size() - 1);
		int sz = 1 << std::__lg(tot * 2 - 1);
		std::vector<int> a0(this->size()), b0(rhs.size());
		for (int i = 0; i < this->size(); ++i) a0[i] = this->a[i];
		for (int i = 0; i < rhs.size(); ++i) b0[i] = rhs.a[i];
		a0.resize(sz); b0.resize(sz);
		auto a1 = a0, a2 = a0, b1 = b0, b2 = b0;
		nft0.dft(a0); nft0.dft(b0);
		nft1.dft(a1); nft1.dft(b1);
		nft2.dft(a2); nft2.dft(b2);
		for (int i = 0; i < sz; ++i) {
			a0[i] = 1LL * a0[i] * b0[i] % nft0.M;
			a1[i] = 1LL * a1[i] * b1[i] % nft1.M;
			a2[i] = 1LL * a2[i] * b2[i] % nft2.M;
		}
		nft0.idft(a0); nft1.idft(a1); nft2.idft(a2);
		a0.resize(tot); a1.resize(tot), a2.resize(tot);
		std::vector<ModInt> ans(tot);
		for (int i = 0; i < tot; ++i) ans[i] = crt(a0[i], a1[i], a2[i]);
		return PolyBaseMFT(ans);
	}
public:
	inline constexpr static int M0 = 469762049, M1 = 998244353, M2 = 1004535809;
	inline const static LL M01 = 1LL * M0 * M1;
	inline static NFT<M0> nft0;
	inline static NFT<M1> nft1;
	inline static NFT<M2> nft2;
	using PolyBase::PolyBase;
	PolyBaseMFT(const PolyBase &A) : PolyBase(A) {}
};

class PolyBaseFFT : public PolyBase {
protected:
	friend std::vector<ModInt> mulCore(PolyBaseFFT A, PolyBaseFFT B, int sz) {
		std::vector<std::complex<double>> C(sz);
		for (int i = 0; i < A.size(); ++i) C[i].real(A[i]);
		for (int i = 0; i < B.size(); ++i) C[i].imag(B[i]);
		FFT::dft(C);
		for (auto &x : C) x *= x;
		FFT::idft(C);
		std::vector<ModInt> ans(A.size() + B.size() - 1);
		for (int i = 0; i < ans.size(); ++i) ans[i] = ModInt(C[i].imag() / 2 + 0.5);
		return ans;
	}
	PolyBaseFFT mul(const PolyBaseFFT &rhs) const {
		int n = std::max(this->size(), rhs.size()), tot = std::max(1, n * 2 - 1);
		int sz = 1 << std::__lg(tot * 2 - 1);
		// return mulCore(A, B, sz); // 为了保证精度必须拆分
		// 下面用三次变两次优化 所以总 dft 次数为 8，一个小技巧可以变成 7 次
		// 利用 dft与共轭的关系可以优化到 4 次，懒得搞
		auto A1(*this), A2(*this), B1(rhs), B2(rhs);
		const static int bit = 15, msk = (1 << bit) - 1;
		for (auto &x : A1.a) x >>= bit;
		for (auto &x : A2.a) x &= msk;
		for (auto &x : B1.a) x >>= bit;
		for (auto &x : B2.a) x &= msk;
		auto ans = mulCore(A1, B1, sz);
		auto A1B2 = mulCore(A1, B2, sz);
		auto A2B1 = mulCore(A2, B1, sz);
		auto A2B2 = mulCore(A2, B2, sz);
		for (auto &x : ans) x <<= bit;
		for (int i = 0; i < ans.size(); ++i) ans[i] += A1B2[i] + A2B1[i];
		for (auto &x : ans) x <<= bit;
		for (int i = 0; i < ans.size(); ++i) ans[i] += A2B2[i];
		return PolyBaseFFT(ans);
	}
public:
	using PolyBase::PolyBase;
	PolyBaseFFT (const PolyBase &x) : PolyBase(x) {}
};

template<typename T>
class Poly : public T {
public:
	using T::T;
	Poly (const T &x) : T(x) {}
	Poly mulXn(int n) const {
		auto b = this->a;
		b.insert(b.begin(), n, 0);
		return Poly(b);
	}
	Poly modXn(int n) const {
		if (n > this->size()) return *this;
		return Poly({this->a.begin(), this->a.begin() + n});
	}
	Poly divXn(int n) const {
		if (this->size() <= n) return Poly();
		return Poly({this->a.begin() + n, this->a.end()});
	}
	Poly &operator+=(const Poly &rhs) {
		if (this->size() < rhs.size()) this->a.resize(rhs.size());
		for (int i = 0; i < rhs.size(); ++i) this->a[i] += rhs.a[i];
		this->standard();
		return *this;
	}
	Poly &operator-=(const Poly &rhs) {
		if (this->size() < rhs.size()) this->a.resize(rhs.size());
		for (int i = 0; i < rhs.size(); ++i) this->a[i] -= rhs.a[i];
		this->standard();
		return *this;
	}
	Poly operator+(const Poly &rhs) const {
		return Poly(*this) += rhs;
	}
	Poly operator-(const Poly &rhs) const {
		return Poly(*this) -= rhs;
	}
	Poly operator*(const Poly &rhs) const {
		return this->mul(rhs);
	}
	Poly &operator*=(const Poly &rhs) {
		return (*this) = (*this) * rhs;
	}
	Poly inv(int n) const {
		assert(this->a[0] != 0);
		Poly x(this->a[0].inv());
		int k = 1;
		while (k < n) {
			k *= 2;
			x *= (Poly(2) - this->modXn(k) * x).modXn(k);
		}
		return x.modXn(n);
	}
	Poly &operator/=(Poly rhs) {
		int n = this->size(), m = rhs.size();
		if (n < m) return (*this) = Poly();
		this->reverse();
		rhs.reverse();
		(*this) *= rhs.inv(n - m + 1);
		this->a.resize(n - m + 1);
		this->reverse();
		return *this;
	}
	Poly operator/(const Poly &rhs) const {
		return Poly(*this) /= rhs;
	}
	Poly &operator%=(const Poly &rhs) {
		return *this -= (*this) / rhs * rhs; 
	}
	Poly operator%(const Poly &rhs) const {
		return Poly(*this) %= rhs;
	}
	Poly powModPoly(int n, const Poly &p) const {
		Poly r(1), x(*this);
		while (n) {
			if (n&1) r = r * x % p;
			n >>= 1; x = x * x % p;
		}
		return r;
	}
	ModInt inner(const Poly &rhs) const {
		ModInt r(0);
		int n = std::min(this->size(), rhs.size());
		for (int i = 0; i < n; ++i) r += this->a[i] * rhs.a[i];
		return r;
	}
	Poly derivation() const {
		if (this->a.empty()) return Poly();
		int n = this->size();
		std::vector<ModInt> r(n - 1);
		for (int i = 1; i < n; ++i) r[i - 1] = this->a[i] * ModInt(i);
		return Poly(r);
	}
	Poly integral() const {
		if (this->a.empty()) return Poly();
		int n = this->size();
		std::vector<ModInt> r(n + 1), inv(n + 1, 1);
		for (int i = 2; i <= n; ++i) inv[i] = ModInt(ModInt::mod() - ModInt::mod() / i) * inv[ModInt::mod() % i];
		for (int i = 0; i < n; ++i) r[i + 1] = this->a[i] * inv[i + 1];
		return Poly(r);
	}
	// 需要保证首项为 1
	Poly log(int n) const {
		return Poly(derivation() * inv(n)).integral().modXn(n);
	}
	// 需要保证首项为 0
	Poly exp(int n) const {
		Poly x(1);
		int k = 1;
		while (k < n) {
			k *= 2;
			x = (x * (Poly(1) - x.log(k) + this->modXn(k))).modXn(k);
		}
		return x.modXn(n);
	}
	// 需要保证首项为 1，开任意次方可以先 ln 再 exp 实现。
	Poly sqrt(int n) const {
		Poly x(1), inv2 = ModInt(2).inv();
		int k = 1;
		while (k < n) {
			k *= 2;
			x += this->modXn(k) * x.inv(k);
			x = x.modXn(k) * inv2;
		}
		return x.modXn(n);
	}
	// 减法卷积，也称转置卷积 {\rm MULT}(F(x),G(x))=\sum_{i\ge0}(\sum_{j\ge 0}f_{i+j}g_j)x^i
	Poly mulT(Poly rhs) const {
		if (rhs.size() == 0) return Poly();
		int n = rhs.size();
		std::reverse(rhs.a.begin(), rhs.a.end());
		return ((*this) * rhs).divXn(n - 1);
	}
	ModInt eval(ModInt x) const {
		ModInt r(0), t(1);
		for (int i = 0, n = this->size(); i < n; ++i) {
			r += this->a[i] * t;
			t *= x;
		}
		return r;
	}
	// 多点求值新科技：https://jkloverdcoi.github.io/2020/08/04/转置原理及其应用/
	std::vector<ModInt> eval(std::vector<ModInt> x) const {
		if (this->size() == 0) return std::vector<ModInt>(x.size());
		int n = x.size();
		std::vector<ModInt> ans(n);
		std::vector<Poly> g(4 * n);
		std::function<void(int, int, int)> build = [&](int l, int r, int p) {
			if (r - l == 1) {
				g[p] = Poly({1, -x[l]});
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
		solve(0, n, 1, mulT(g[1].inv(this->size())).modXn(n));
		return ans;
	}
};

using PolyNFT = Poly<PolyBaseNFT>;
using PolyMFT = Poly<PolyBaseMFT>;
using PolyFFT = Poly<PolyBaseFFT>;

// 计算 \sum_{i = 0}^{n - 1} a_i / (1 - b_i x)
std::vector<ModInt> sumFraction(std::vector<ModInt> a, std::vector<ModInt> b, int N) {
	std::function<std::pair<PolyNFT, PolyNFT>(int, int)> solve = [&](int l, int r) -> std::pair<PolyNFT, PolyNFT> {
		if (r - l == 1) {
			return {PolyNFT(a[l]), PolyNFT({1, - b[l]})};
		}
		int m = (l + r) / 2;
		auto [pl, ql] = solve(l, m);
		auto [pr, qr] = solve(m, r);
		return {pl * qr + pr * ql, ql * qr};
	};
	auto [p, q] = solve(0, a.size());
	p *= q.inv(N);
	auto ans = p.a;
	ans.resize(N);
	return ans;
} // 模板例题：https://codeforces.com/gym/102978/problem/D

// $a_n = \sum_{i = 1}^{k} f_i a_{n - i}$，理论：https://oi-wiki.org/math/linear-recurrence/
// $O(k \log k \log n)$ 求 k 阶常系数递推公式的第 n 项
ModInt linearRecursion(std::vector<ModInt> a, std::vector<ModInt> f, int n) {
	if (n < a.size()) return a[n];
	int m = f.size();
	std::reverse(f.begin(), f.end());
	std::vector<ModInt> g(m);
	g.emplace_back(1);
	PolyNFT A = PolyNFT({0, 1}), p = PolyNFT(g) - PolyNFT(f);
	PolyNFT R = A.powModPoly(n, p);
	return R.inner(a);
} // 模板: https://www.luogu.com.cn/problem/P4723

// ans[i] = 1^i + 2^i + ... + (n - 1)^i, 0 < i < k
// 原理：https://dna049.com/fastPowSumOfNaturalNumber/
std::vector<ModInt> powSum(int n, int k) {
	PolyNFT Numerator = PolyNFT({0, n}).exp(k + 1).divXn(1);
	PolyNFT denominator  = PolyNFT({0, 1}).exp(k + 1).divXn(1);
	auto f = (Numerator * denominator.inv(k)).modXn(k) - PolyNFT(1);
	auto ans = f.a;
	ans.resize(k);
	ModInt now(1);
	for (int i = 2; i < k; ++i) {
		now *= ModInt(i);
		ans[i] *= now;
	}
	return ans;
}

// 任意模素数 min25 求阶乘 $O(\sqrt{n} \log n)$


// 例题：https://www.luogu.com.cn/problem/solution/P5282