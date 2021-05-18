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
	PolyBaseFFT mul(const PolyBaseFFT &rhs) const {
		int tot = std::max(1, this->size() + rhs.size() - 1);
		int sz = 1 << std::__lg(tot * 2 - 1);
		// 为了保证精度必须拆分（否则直接用 三次变两次 技巧）
		auto A1(*this), A2(*this), B1(rhs), B2(rhs);
		static constexpr int bit = 15, msk = (1 << bit) - 1;
		for (auto &x : A1.a) x &= msk;
		for (auto &x : A2.a) x >>= bit;
		for (auto &x : B1.a) x &= msk;
		for (auto &x : B2.a) x >>= bit;
		std::vector<std::complex<double>> A(sz), B(sz), C(sz);
		for (int i = 0, tSize = this->size(); i < tSize; ++i) {
			A[i] = std::complex((double)A1[i], (double)A2[i]);
		}
		for (int i = 0, rSize = rhs.size(); i < rSize; ++i) {
			B[i] = std::complex((double)B1[i], (double)B2[i]);
		}
		FFT::dft(A); FFT::dft(B);
		C[0] = conj(B[0]);
		for (int i = 1; i < sz; ++i) C[i] = conj(B[sz - i]);
		for (int i = 0; i < sz; ++i) B[i] *= A[i];
		for (int i = 0; i < sz; ++i) C[i] *= A[i];
		FFT::idft(B); FFT::idft(C);
		std::vector<T> ans(tot), A1B2(tot), A1B1(tot);
		for (int i = 0; i < tot; ++i) {
			A1B2[i] = LL(B[i].imag() + 0.5);
			A1B1[i] = LL(B[i].real() + C[i].real() + 0.5) / 2;
			ans[i] = LL(C[i].real() - B[i].real() + 0.5) / 2;
		}
		for (auto &x : ans) x <<= bit;
		for (int i = 0; i < tot; ++i) ans[i] += A1B2[i];
		for (auto &x : ans) x <<= bit;
		for (int i = 0; i < tot; ++i) ans[i] += A1B1[i];
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
				ans[l] = f.at(0);
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
	static std::vector<valT> sumFraction(std::vector<valT> a, std::vector<valT> b, int N) {
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
	static valT linearRecursion(std::vector<valT> a, std::vector<valT> f, int n) {
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
	static std::vector<valT> prefixPowSum(int n, int k) {
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
	// 计算 $\prod_{i = 0}^{n - 1} (x + i)$
	static Poly prod(int n) {
		std::function<Poly(int l, int r)> solve = [&](int l, int r) -> Poly {
			if (r - l == 1) {
				return Poly({l, 1});
			} else {
				int m = (l + r) / 2;
				return solve(l, m) * solve(m, r);
			}
		};
		return solve(0, n);
	}
}; // 多项式全家桶测试：https://www.luogu.com.cn/training/3015#information

const constexpr int NFTM = 998244353;
using PolyNFT = Poly<PolyBaseNFT<NFTM>, MInt<NFTM>>;

const constexpr int FFTM = 1e9 + 7;
using PolyFFT = Poly<PolyBaseFFT<MInt<FFTM>>, MInt<FFTM>>;
using PolyFFTDynamic = Poly<PolyBaseFFT<ModInt>, ModInt>;

// 这个太慢了，但可以保证正确性
using PolyMFT = Poly<PolyBaseMFT<MInt<FFTM>>, MInt<FFTM>>;
using PolyMFTDynamic = Poly<PolyBaseMFT<ModInt>, ModInt>;


// 求阶乘：多点求值 $O(\sqrt{n} \log^2 n)$ 算法
int factorialS(int n, int p) {
	if (n >= p) return 0;
	ModInt::setMod(p);
	int sn = std::sqrt(n);
	auto A = PolyMFTDynamic::prod(sn);
	std::vector<ModInt> x;
	for (int i = sn; i <= n; i += sn) x.emplace_back(i - sn + 1);
	auto y = A.evals(x);
	ModInt r(1);
	for (auto t : y) r *= t;
	for (int i = n / sn * sn + 1; i <= n; ++i) r *= ModInt::raw(i);
	return r;
}


int factorial(int n, int p) {
	if (n >= p) return 0;
	if (n <= 1) return 1;
	ModInt::setMod(p);
	if (n > p - 1 - n) {
		int ans = ModInt(factorial(p - 1 - n, p)).inv();
		return (p - n) & 1 ? p - ans : ans; 
	}
	int s = std::sqrt(n);
	std::vector<ModInt> fac(s + 1), ifac(s + 1), inv(s + 1);
	fac[0] = inv[1] = 1;
	for (int i = 1; i <= s; ++i) fac[i] = fac[i - 1] * ModInt::raw(i);
	ifac[s] = fac[s].inv();
	for (int i = s; i > 0; --i) ifac[i - 1] = ifac[i] * ModInt::raw(i);
	for (int i = 2; i <= s; ++i) inv[i] = inv[p % i] * ModInt::raw(p - p / i);
	// 根据 $h(0), h(1), \cdots, h(d)$ 的值 求 $h(m), \cdots, h(m + cnt - 1)$
	auto solve = [&](std::vector<ModInt> h, ModInt m, int cnt) { // m > h.size()
		int d = h.size() - 1;
		for (int i = 0; i <= d; ++i) {
			h[i] *= ifac[i] * ifac[d - i];
			if ((d - i) & 1) h[i] = -h[i];
		}
		std::vector<ModInt> f(d + cnt);
		auto now = m - ModInt(d);
		for (int i = 0; i < d + cnt; ++i) {
			f[i] = now.inv();
			++now;
		}
		h = (PolyFFTDynamic(f) * PolyFFTDynamic(h)).a;
		h.resize(d + cnt);
		h = std::vector<ModInt>(h.begin() + d, h.end());
		now = 1;
		for (int i = 0; i <= d; ++i) now *= m - ModInt::raw(i);
		h[0] *= now;
		for (int i = 1; i < cnt; ++i) {
			now *= m + ModInt::raw(i);
			now *= (m + ModInt(i - d - 1)).inv();
			h[i] *= now;
		}
		return h;
	};
	auto invS = ModInt(s).inv();
	std::vector<ModInt> h{1, s + 1};
	for (int bit = std::__lg(s) - 1, d = 1; bit >= 0; --bit) {
		auto nh1 = solve(h, d + 1, d);
		auto nh2 = solve(h, invS * ModInt(d), 2 * d + 1);
		h.insert(h.end(), nh1.begin(), nh1.end());
		d *= 2;
		for (int i = 0; i <= d; ++i) h[i] *= nh2[i];
		if (s >> bit & 1) {
			++d;
			for (int i = 0, t = d; i < d; ++i, t += s) h[i] *= ModInt::raw(t);
			ModInt tmp(1), tj = s * d;
			for (int i = 0; i < d; ++i) ++tj, tmp *= tj;
			h.emplace_back(tmp);
		}
	}
	ModInt ans = 1;
	for (int i = 0; i < s; ++i) ans *= h[i];
	for (int i = s * s + 1; i <= n; ++i) ans *= ModInt::raw(i);
	return ans;
}
// 例题：https://www.luogu.com.cn/problem/solution/P5282
