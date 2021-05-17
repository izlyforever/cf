#pragma once
#include <bits/stdc++.h>
#include "primary.hpp"
using LL = long long;

// 为了支持三模数，改成模板类的形式
template<int M>
class NFT { // 请自行保证输入的 N 为 原根 3 的 NFT-friendly 素数
	std::vector<int> rev;
	std::vector<MInt<M>> roots{0, 1};
public:
	static inline const MInt<M> g = 3;
	void dft(std::vector<MInt<M>> &a) {
		int n = a.size();
		if ((int)rev.size() != n) {
			int k = __builtin_ctz(n) - 1;
			rev.resize(n);
			for (int i = 0; i < n; ++i) {
				rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
			}
		}
		if ((int)roots.size() < n) {
			int k = __builtin_ctz(roots.size());
			roots.resize(n);
			while ((1 << k) < n) {
				auto e = pow(g, (M - 1) >> (k + 1));
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
	void idft(std::vector<MInt<M>> &a) {
		int n = a.size();
		std::reverse(a.begin() + 1, a.end());
		dft(a);
		auto inv = pow(MInt<M>(n), M - 2);
		for (auto &x : a) x *= inv;
	}
};

// 多项式底层基类（不能放带 PolyBase 返回值的，不然很麻烦）
template<typename T>
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
	std::vector<T> a;
	PolyBase() {}
	PolyBase(T x) { if (x != 0) a = {x};}
	PolyBase(const std::vector<T> &_a) : a(_a) { standard();}
	int size() const { return a.size();}
	T &operator[](int id) { return a[id];}
	T at(int id) const {
		if (id < 0 || id > (int)a.size()) return 0;
		return a[id];
	}
};

template<int N>
class PolyBaseNFT : public PolyBase<MInt<N>> {
protected:
	PolyBaseNFT mul(const PolyBaseNFT &rhs) const {
		int n = this->size(), m = rhs.size(), tot = std::max(1, n + m - 1);
		int sz = 1 << std::__lg(tot * 2 - 1);
		auto A = this->a, B = rhs.a;
		A.resize(sz); B.resize(sz);
		nft.dft(A); nft.dft(B);
		for (int i = 0; i < sz; ++i) A[i] *= B[i];
		nft.idft(A);
		A.resize(n + m - 1);
		return PolyBaseNFT(A);
	}
public:
	static inline const int M = N;
	static inline NFT<N> nft;
	using PolyBase<MInt<N>>::PolyBase;
	PolyBaseNFT(const PolyBase<MInt<N>> &A) : PolyBase<MInt<N>>(A) {}
};

template<typename T>
class PolyBaseMFT : public PolyBase<T> {
public:
	static inline constexpr int M0 = 469762049, M1 = 998244353, M2 = 1004535809;
	static inline constexpr LL M01 = 1LL * M0 * M1;
	static inline NFT<M0> nft0;
	static inline NFT<M1> nft1;
	static inline NFT<M2> nft2;
	using PolyBase<T>::PolyBase;
	PolyBaseMFT (const PolyBase<T> &x) : PolyBase<T>(x) {}
protected:
	static T crt(int a0, int a1, int a2) {
		static const int t0 = MInt<M1>::inv(M0);
		static const int t1 = MInt<M2>::inv(M01 % M2);
		static const T m01(M01);
		LL x = (a0 + 1LL * (a1 - a0) * t0 % M1 * M0) % M01;
		if (x < 0) x += M01;
		LL y = (a2 - x) % M2;
		if (y < 0) y += M2;
		y = y * t1 % M2;
		if (y < 0) y += M01;
		return T(x) + T(y) * m01;
	}
	PolyBaseMFT mul(const PolyBaseMFT &rhs) const {
		int tot = std::max(1, this->size() + rhs.size() - 1);
		int sz = 1 << std::__lg(tot * 2 - 1);
		std::vector<MInt<M0>> a0(sz), b0(sz);
		std::vector<MInt<M1>> a1(sz), b1(sz);
		std::vector<MInt<M2>> a2(sz), b2(sz);
		for (int i = 0, ns = this->size(); i < ns; ++i) {
			int t = this->a[i];
			a0[i] = t; a1[i] = t; a2[i] = t;
		}
		for (int i = 0, ns = rhs.size(); i < ns; ++i) {
			int t = rhs.a[i];
			b0[i] = t; b1[i] = t; b2[i] = t;
		}
		nft0.dft(a0); nft0.dft(b0);
		nft1.dft(a1); nft1.dft(b1);
		nft2.dft(a2); nft2.dft(b2);
		for (int i = 0; i < sz; ++i) {
			a0[i] *= b0[i]; a1[i] *= b1[i]; a2[i] *= b2[i];
		}
		nft0.idft(a0); nft1.idft(a1); nft2.idft(a2);
		std::vector<T> ans(tot);
		for (int i = 0; i < tot; ++i) ans[i] = crt(a0[i], a1[i], a2[i]);
		return PolyBaseMFT(ans);
	}
};

namespace FFT {
const double PI = std::acos(-1);
using C = std::complex<double>;
std::vector<int> rev;
std::vector<C> roots{C(0, 0), C(1, 0)};
void dft(std::vector<C> &a) {
	int n = a.size();
	if ((int)rev.size() != n) {
		int k = __builtin_ctz(n) - 1;
		rev.resize(n);
		for (int i = 0; i < n; ++i) {
			rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
		}
	}
	if ((int)roots.size() < n) {
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

template<typename T>
class PolyBaseFFT : public PolyBase<T> {
protected:
	friend std::vector<T> mulCore(PolyBaseFFT A, PolyBaseFFT B, int sz) {
		std::vector<std::complex<double>> C(sz);
		for (int i = 0; i < A.size(); ++i) C[i].real(A[i]);
		for (int i = 0; i < B.size(); ++i) C[i].imag(B[i]);
		FFT::dft(C);
		for (auto &x : C) x *= x;
		FFT::idft(C);
		std::vector<T> ans(A.size() + B.size() - 1);
		for (int i = 0; i < ans.size(); ++i) ans[i] = T(C[i].imag() / 2 + 0.5);
		return ans;
	}
	PolyBaseFFT mul(const PolyBaseFFT &rhs) const {
		int n = std::max(this->size(), rhs.size()), tot = std::max(1, n * 2 - 1);
		int sz = 1 << std::__lg(tot * 2 - 1);
		// return mulCore(A, B, sz); // 为了保证精度必须拆分
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
	using PolyBase<T>::PolyBase;
	PolyBaseFFT (const PolyBase<T> &x) : PolyBase<T>(x) {}
};

// using valT = decltype(T::a)::value_type;
template<typename T, typename valT>
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
	valT inner(const Poly &rhs) const {
		valT r(0);
		int n = std::min(this->size(), rhs.size());
		for (int i = 0; i < n; ++i) r += this->a[i] * rhs.a[i];
		return r;
	}
	Poly derivation() const {
		if (this->a.empty()) return Poly();
		int n = this->size();
		std::vector<valT> r(n - 1);
		for (int i = 1; i < n; ++i) r[i - 1] = this->a[i] * valT(i);
		return Poly(r);
	}
	Poly integral() const {
		if (this->a.empty()) return Poly();
		int n = this->size();
		std::vector<valT> r(n + 1), inv(n + 1, 1);
		for (int i = 2; i <= n; ++i) inv[i] = valT(valT::mod() - valT::mod() / i) * inv[valT::mod() % i];
		for (int i = 0; i < n; ++i) r[i + 1] = this->a[i] * inv[i + 1];
		return Poly(r);
	}
	// 需要保证首项为 1
	Poly log(int n) const {
		return (derivation() * inv(n)).integral().modXn(n);
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
		Poly x(1), inv2 = valT(2).inv();
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
	valT eval(valT x) const {
		valT r(0), t(1);
		for (int i = 0, n = this->size(); i < n; ++i) {
			r += this->a[i] * t;
			t *= x;
		}
		return r;
	}
	// 多点求值新科技：https://jkloverdcoi.github.io/2020/08/04/转置原理及其应用/
	std::vector<valT> evals(std::vector<valT> x) const {
		if (this->size() == 0) return std::vector<valT>(x.size());
		int n = x.size();
		std::vector<valT> ans(n);
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
	} // 模板例题：https://www.luogu.com.cn/problem/P5050

	// 计算 \sum_{i = 0}^{n - 1} a_i / (1 - b_i x)
	friend std::vector<valT> sumFraction(std::vector<valT> a, std::vector<valT> b, int N) {
		std::function<std::pair<Poly, Poly>(int, int)> solve = [&](int l, int r) -> std::pair<Poly, Poly> {
			if (r - l == 1) {
				return {Poly(a[l]), Poly({1, - b[l]})};
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
	valT linearRecursion(std::vector<valT> a, std::vector<valT> f, int n) {
		if (n < a.size()) return a[n];
		int m = f.size();
		std::reverse(f.begin(), f.end());
		std::vector<valT> g(m);
		g.emplace_back(1);
		Poly A = Poly({0, 1}), p = Poly(g) - Poly(f);
		Poly R = A.powModPoly(n, p);
		return R.inner(a);
	} // 模板: https://www.luogu.com.cn/problem/P4723

	// ans[i] = 1^i + 2^i + ... + (n - 1)^i, 0 < i < k
	// 原理：https://dna049.com/fastPowSumOfNaturalNumber/
	std::vector<valT> powSum(int n, int k) {
		Poly Numerator = Poly({0, n}).exp(k + 1).divXn(1);
		Poly denominator  = Poly({0, 1}).exp(k + 1).divXn(1);
		auto f = (Numerator * denominator.inv(k)).modXn(k) - Poly(1);
		auto ans = f.a;
		ans.resize(k);
		valT now(1);
		for (int i = 2; i < k; ++i) {
			now *= valT(i);
			ans[i] *= now;
		}
		return ans;
	}
}; // 多项式全家桶测试：https://www.luogu.com.cn/training/3015#information

const constexpr int NFTM = 998244353;
using PolyNFT = Poly<PolyBaseNFT<NFTM>, MInt<NFTM>>;

const constexpr int FFTM = 1e9 + 7;
using PolyFFT = Poly<PolyBaseFFT<MInt<FFTM>>, MInt<FFTM>>;
using PolyFFTDynamic = Poly<PolyBaseFFT<ModInt>, ModInt>;

using PolyMFT = Poly<PolyBaseMFT<MInt<FFTM>>, MInt<FFTM>>;
using PolyMFTDynamic = Poly<PolyBaseMFT<ModInt>, ModInt>;


// 请谨慎使用，仅有答案的值域在 0 <= M0 * M1 * M2 时才对！
template<typename valT>
class PolyMFTStrictly {
public:
	static inline constexpr int M0 = 469762049;
	static inline constexpr int M1 = 998244353;
	static inline constexpr int M2 = 1004535809;
	using P0 = Poly<PolyBaseNFT<M0>, MInt<M0>>;
	using P1 = Poly<PolyBaseNFT<M1>, MInt<M1>>;
	using P2 = Poly<PolyBaseNFT<M2>, MInt<M2>>;
	P0 poly0; P1 poly1; P2 poly2;
	PolyMFTStrictly(const P0 &A, const P1 &B, const P2 &C) : poly0(A), poly1(B), poly2(C) {}
	PolyMFTStrictly() {}
	PolyMFTStrictly(valT x = 0) : poly0(int(x)), poly1(int(x)), poly2(int(x)) {}
	PolyMFTStrictly(const std::vector<valT> &a) {
		int n = a.size();
		std::vector<MInt<M0>> a0(n);
		std::vector<MInt<M1>> a1(n);
		std::vector<MInt<M2>> a2(n);
		for (int i = 0; i < n; ++i) {
			int t = a[i];
			a0[i] = t; a1[i] = t; a2[i] = t;
		}
		*this = PolyMFTStrictly(a0, a1, a2);
	}
	int size() {
		return std::max({poly0.size(), poly1.size(), poly2.size()});
	}
	void resize(int n) {
		poly0.size(); poly1.size(); poly2.size();
	}
	std::vector<valT> get(int n) {
		std::vector<valT> ans(n);
		for (int i = 0; i < n; ++i) ans[i] = crt(poly0.at(i), poly1.at(i), poly2.at(i));
		return ans;
	}
	PolyMFTStrictly operator+(const PolyMFTStrictly &rhs) const {
		return PolyMFTStrictly(poly0 + rhs.poly0, poly1 + rhs.poly1, poly2 + rhs.poly2);
	}
	PolyMFTStrictly operator-(const PolyMFTStrictly &rhs) const {
		return PolyMFTStrictly(poly0 - rhs.poly0, poly1 - rhs.poly1, poly2 - rhs.poly2);
	}
	PolyMFTStrictly operator*(const PolyMFTStrictly &rhs) const {
		return PolyMFTStrictly(poly0 * rhs.poly0, poly1 * rhs.poly1, poly2 * rhs.poly2);
	}
	PolyMFTStrictly operator/(const PolyMFTStrictly &rhs) const {
		return PolyMFTStrictly(poly0 / rhs.poly0, poly1 / rhs.poly1, poly2 / rhs.poly2);
	}
	PolyMFTStrictly operator%(const PolyMFTStrictly &rhs) const {
		return PolyMFTStrictly(poly0 % rhs.poly0, poly1 % rhs.poly1, poly2 % rhs.poly2);
	}
	PolyMFTStrictly &operator+=(const PolyMFTStrictly &rhs) {
		return *this = *this + rhs;
	}
	PolyMFTStrictly &operator-=(const PolyMFTStrictly &rhs) {
		return *this = *this - rhs;
	}
	PolyMFTStrictly &operator*=(const PolyMFTStrictly &rhs) {
		return *this = *this * rhs;
	}
	PolyMFTStrictly &operator/=(const PolyMFTStrictly &rhs) {
		return *this = *this / rhs;
	}
	PolyMFTStrictly &operator%(const PolyMFTStrictly &rhs) {
		return *this = *this % rhs;
	}
	PolyMFTStrictly inv(int n) const {
		return PolyMFTStrictly(poly0.inv(n), poly1.inv(n), poly2.inv(n));
	}
	PolyMFTStrictly powModPoly(int n, const PolyMFTStrictly &p) const {
		return PolyMFTStrictly(poly0.powModPoly(n, p.poly0), poly1.powModPoly(n, p.poly1), poly2.powModPoly(n, p.poly2));
	}
	valT inner(const PolyMFTStrictly &rhs) const {
		return crt(poly0.inner(rhs.poly0), poly1.inner(rhs.poly1), poly2.inner(rhs.poly2));
	}
	PolyMFTStrictly derivation() const {
		return PolyMFTStrictly(poly0.derivation(), poly1.derivation(), poly2.derivation());
	}
	PolyMFTStrictly integral() const {
		return PolyMFTStrictly(poly0.integral(), poly1.integral(), poly2.integral());
	}
	PolyMFTStrictly log(int n) const {
		return PolyMFTStrictly(poly0.log(n), poly1.log(n), poly2.log(n));
	}
	PolyMFTStrictly exp(int n) const {
		return PolyMFTStrictly(poly0.exp(n), poly1.exp(n), poly2.exp(n));
	}
	PolyMFTStrictly sqrt(int n) const {
		return PolyMFTStrictly(poly0.sqrt(n), poly1.sqrt(n), poly2.sqrt(n));
	}
	PolyMFTStrictly mulT(PolyMFTStrictly rhs) const {
		return PolyMFTStrictly(poly0.mulT(rhs.poly0), poly1.mulT(poly1), poly2.mulT(poly2));
	}
	valT eval(valT x) const {
		return crt(poly0.eval(int(x)), poly1.eval(int(x)), poly2.eval(int(x)));
	}
	std::vector<valT> evals(std::vector<valT> x) const {
		PolyMFTStrictly val(x);
		PolyMFTStrictly ans = PolyMFTStrictly(poly0.evals(val.poly0.a), poly1.evals(val.poly1.a), poly2.evals(poly2.a));
		return ans.get(x.size());
	}
protected:
	static inline constexpr LL M01 = 1LL * M0 * M1;
	static valT crt(int a0, int a1, int a2) {
		static const int t0 = MInt<M1>::inv(M0);
		static const int t1 = MInt<M2>::inv(M01 % M2);
		static const valT m01(M01);
		LL x = (a0 + 1LL * (a1 - a0) * t0 % M1 * M0) % M01;
		if (x < 0) x += M01;
		LL y = (a2 - x) % M2;
		if (y < 0) y += M2;
		y = y * t1 % M2;
		if (y < 0) y += M01;
		return valT(x) + valT(y) * m01;
	}
};

// 任意模素数 min25 求阶乘 $O(\sqrt{n} \log n)$


// 例题：https://www.luogu.com.cn/problem/solution/P5282