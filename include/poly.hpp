#pragma once
#include <bits/stdc++.h>
#include "ring.hpp"
using LL = long long;
// 核弹流参考资料：https://www.luogu.com.cn/blog/command-block/sheng-cheng-han-shuo-za-tan
// 生成函数 离散微积分

// using valT = decltype(T::a)::value_type;
template<typename T, typename valT>
class Poly : public T {
	// 请特别注意 $n > mod$ 的情况！此时很多功能无法保证正确性
	static inline const valT j = pow(valT(3), (valT::mod() - 1) / 4);
	static inline const valT inv2 = (valT::mod() + 1) / 2;
	static inline const int maxN = 1e6 + 2;  // a 的 size 请勿超过 maxN
	static inline const auto Binom = BinomInPoly<valT>(maxN);
	// static inline constexpr Binom
public:
	using T::T;
	Poly (const T &x) : T(x) { this->standard();}
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
	Poly operator-() const {
		auto A = *this;
		for (auto &x : A.a) x = -x;
		return A;
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
		// assert(this->a[0] != 0);
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
	Poly powModPoly(LL n, const Poly &p) const {
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
	Poly sin(int n) const {
		auto A = *this;
		for (auto &x : A.a) x *= j;
		A = A.exp(n);
		A -= A.inv(n);
		auto m = -j * inv2;
		for (auto &x : A.a) x *= m;
		return A;
	}
	Poly cos(int n) const {
		auto A = *this;
		for (auto &x : A.a) x *= j;
		A = A.exp(n);
		A += A.inv(n);
		for (auto &x : A.a) x *= inv2;
		return A;
	}
	// 自行确保首项 为 0
	Poly asin(int n) const { // cos 貌似搞不了
		auto D = this -> derivation();
		auto A = (Poly(1) - (*this) * (*this)).modXn(n - 1);
		D = D * A.sqrt(n - 1).inv(n - 1);
		D = D.modXn(n - 1);
		return D.integral();
	}
	// 自行确保首项 为 0
	Poly atan(int n) const {
		auto D = this -> derivation();
		auto A = (Poly(1) + (*this) * (*this)).modXn(n - 1);
		D = D * A.inv(n - 1);
		D = D.modXn(n - 1);
		return D.integral();
	}
	// 需要保证首项为 1，开任意次方可以先 ln 再 exp 实现。
	Poly sqrt(int n) const {
		Poly x(1);
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
	// 复合函数 F(A(x)) 普通算法（Brent-Kung 算法复杂度 $(n \log n)^{1.5}$ 实际很慢）
	Poly compose(Poly A, int n) const {
		A = A.modXn(n);
		int sn = std::sqrt(n);
		std::vector<Poly> G(sn);
		G[0] = {1};
		for (int i = 1; i < sn; ++i) G[i] = (G[i - 1] * A).modXn(n);
		auto B = (G.back() * A).modXn(n);
		Poly now{1}, ans;
		for (int i = 0; i < n; i += sn) {
			Poly sm;
			for (int j = 0; j < sn && i + j < n; ++j) {
				auto m = this->at(i + j);
				auto tmp = G[j];
				for (auto &x : tmp.a) x *= m;
				sm += tmp;
			}
			ans += (now * sm).modXn(n);
			now = (now * B).modXn(n);
		}
		return ans;
	}
	// 复合函数逆，需要首项为 0，一次项非 0
	// 理论依据：Langrange 反演 $[x^n]G(x) = \frac{1}{n}[x^{n - 1}](\frac{x}{F(x)})^n$
	Poly composeInv(int n) const {
		auto A = this->divXn(1).inv(n - 1);
		int sn = std::sqrt(n);
		std::vector<Poly> G(sn + 1);
		G[0] = {1};
		for (int i = 1; i <= sn; ++i) G[i] = (G[i - 1] * A).modXn(n - 1);
		std::vector<valT> ans(n), inv(n);
		auto M = valT::mod();
		inv[1] = 1;
		for (int i = 2; i < n; ++i) inv[i] = inv[M % i] * valT(M - M / i);
		Poly now{1};
		for (int i = 0; i < n; i += sn) {
			for (int j = 1; j <= sn && i + j < n; ++j) {
				valT tmp;
				auto &sg = G[j];
				for (int k = 0, sk = i + j - 1; k <= sk; ++k) {
					tmp += now.at(k) * sg.at(sk - k);
				}
				ans[i + j] = tmp * inv[i + j];
			}
			now = (now * G.back()).modXn(n - 1);
		}
		return Poly(ans);
	}
	Poly toFallingFactorial() {
		int n = this->size();
		std::vector<valT> x(n);
		for (int i = 0; i < n; ++i) x[i] = i;
		auto y = this->evals(x);
		auto tmp = Binom.ifac;
		for (int i = 1; i < n; i += 2) tmp[i] = -tmp[i];
		Poly A = Poly(y) * Poly(tmp);
		return A.modXn(n);
	}
	Poly fromFallingFactorial() {
		int n = this->size();
		Poly A = ((*this) * Poly(Binom.ifac)).modXn(n);
		std::vector<valT> x(n), y = A.a;
		for (int i = 0; i < n; ++i) x[i] = i;
		y.resize(n);
		for (int i = 0; i < n; ++i) y[i] *= Binom.fac[i];
		return Lagrange(x, y);
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
			if (r - l == 1) return {Poly(a[l]), Poly({1, - b[l]})};
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
	
	// 根据 $h(0), h(1), \cdots, h(d)$ 的值 求 $h(m), \cdots, h(m + cnt - 1)$
	static std::vector<valT> valToVal(std::vector<valT> h, valT m, int cnt) { // m > h.size()
		int d = h.size() - 1;
		for (int i = 0; i <= d; ++i) {
			h[i] *= Binom.ifac[i] * Binom.ifac[d - i];
			if ((d - i) & 1) h[i] = -h[i];
		}
		std::vector<valT> f(d + cnt);
		auto now = m - valT(d);
		for (int i = 0; i < d + cnt; ++i) {
			f[i] = now.inv();
			++now;
		}
		h = (Poly(f) * Poly(h)).a;
		h.resize(d + cnt);
		h = std::vector<valT>(h.begin() + d, h.end());
		now = 1;
		for (int i = 0; i <= d; ++i) now *= m - valT::raw(i);
		h[0] *= now;
		for (int i = 1; i < cnt; ++i) {
			now *= m + valT::raw(i);
			now *= (m + valT(i - d - 1)).inv();
			h[i] *= now;
		}
		return h;
	}; // 模板例题：https://www.luogu.com.cn/problem/P5667
	static Poly Lagrange(std::vector<valT> x, std::vector<valT> y) {
		std::function<Poly(int l, int r)> mulP = [&](int l, int r) -> Poly {
			if (r - l == 1) return Poly({-x[l], 1});
			int m = (l + r) / 2;
			return mulP(l, m) * mulP(m, r);
		};
		int n = x.size();
		auto A = mulP(0, n).derivation();
		auto z = A.evals(x);
		for (int i = 0; i < n; ++i) y[i] /= z[i];
		std::function<std::pair<Poly, Poly>(int, int)> solve = [&](int l, int r) -> std::pair<Poly, Poly> {
			if (r - l == 1) {
				return {Poly(y[l]), Poly({-x[l], 1})};
			}
			int m = (l + r) / 2;
			auto [pl, ql] = solve(l, m);
			auto [pr, qr] = solve(m, r);
			return {pl * qr + pr * ql, ql * qr};
		};
		auto [p, q] = solve(0, x.size());
		return p;
	}
	
	// $a_n = \sum_{i = 1}^{k} f_i a_{n - i}$，理论：https://oi-wiki.org/math/linear-recurrence/
	// $O(k \log k \log n)$ 求 k 阶常系数递推公式的第 n 项
	static valT linearRecursion(std::vector<valT> a, std::vector<valT> f, int n) {
		if (n < (int)a.size()) return a[n];
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
		// exp 常数好大啊！谨慎使用！这里建议修改，直接求。
		// Poly Numerator = Poly({0, n}).exp(k + 1).divXn(1);
		// Poly denominator  = Poly({0, 1}).exp(k + 1).divXn(1);
		std::vector<valT> a(k), b(k);
		for (int i = 0; i < k; ++i) a[i] = b[i] = Binom.ifac[i + 1];
		valT cur = 1;
		for (int i = 0; i < k; ++i) a[i] *= (cur *= valT::raw(n));
		auto Numerator = Poly(a), denominator = Poly(b);
		
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
	// 计算 $\prod_{i = 0}^{n - 1} (x + i)$ 上升幂($O(n \log n)$)
	static Poly prod(int n) {
		// $O(n \log^2 n)$ 朴素做法
		// std::function<Poly(int l, int r)> solve = [&](int l, int r) -> Poly {
		// 	if (r - l == 1) return Poly({l, 1});
		// 	int m = (l + r) / 2;
		// 	return solve(l, m) * solve(m, r);
		// };
		// return solve(0, n);
		std::function<Poly(int)> solve = [&](int n) -> Poly {
			if (n == 1) return Poly({0, 1});
			int k = n / 2;
			auto A = solve(k);
			std::vector<valT> tmp(k + 1);
			valT now{1};
			for (int i = 0; i <= k; ++i) {
				tmp[i] = now * Binom.ifac[i];
				now *= k;
			}
			auto B = A;
			for (int i = 0; i < B.size(); ++i) B[i] *= Binom.fac[i];
			B = B.mulT(tmp).modXn(k + 1);
			for (int i = 0; i < B.size(); ++i) B[i] *= Binom.ifac[i];
			A *= B;
			if (2 * k != n) {
				B = A;
				for (auto &x : B.a) x *= valT::raw(n - 1);
				A = A.mulXn(1) + B;
			}
			return A;
		};
		return solve(n);
	}
}; // 多项式全家桶测试：https://www.luogu.com.cn/training/3015#information

// 多项式底层基类（不能放带 PolyBase 返回值的，不然很麻烦）
template<typename T>
class PolyBase {
protected:
	void standard() {
		while (!a.empty() && !a.back()) a.pop_back();
	}
	void reverse() {
		std::reverse(a.begin(), a.end());
		standard();
	}
public:
	std::vector<T> a;
	PolyBase() {}
	PolyBase(T x) { if (x != 0) a = {x};}
	PolyBase(const std::vector<T> &_a) : a(_a) {}
	int size() const { return a.size();}
	T &operator[](int id) { return a[id];}
	T at(int id) const {
		if (id < 0 || id >= (int)a.size()) return 0;
		return a[id];
	}
};
// 以上内容是必须要的，以下内容必须根据需要选择一个







template<typename T>
class PolyBaseOrigin : public PolyBase<T> {
public:
	using PolyBase<T>::PolyBase;
	PolyBaseOrigin (const PolyBase<T> &x) : PolyBase<T>(x) {}
protected:
	PolyBaseOrigin mul(const PolyBaseOrigin &rhs) const {
		std::vector<T> ans(this->size() + rhs.size() - 1);
		for (int i = 0, sn = this->size(); i < sn; ++i) {
			for (int j = 0, rsn = rhs.size(); j < rsn; ++j) {
				ans[i + j] += this->a[i] * rhs.a[j];
			}
		}
		return PolyBaseOrigin(ans);
	}
};

template<int N>
class PolyBaseNTT : public PolyBase<MInt<N>> {
protected:
	PolyBaseNTT mul(const PolyBaseNTT &rhs) const {
		int n = this->size(), m = rhs.size(), tot = std::max(1, n + m - 1);
		int sz = 1 << std::__lg(tot * 2 - 1);
		auto A = this->a, B = rhs.a;
		A.resize(sz); B.resize(sz);
		ntt.dft(A); ntt.dft(B);
		for (int i = 0; i < sz; ++i) A[i] *= B[i];
		ntt.idft(A);
		A.resize(n + m - 1);
		return PolyBaseNTT(A);
	}
public:
	static inline const int M = N;
	static inline NTT<N> ntt;
	using PolyBase<MInt<N>>::PolyBase;
	PolyBaseNTT(const PolyBase<MInt<N>> &A) : PolyBase<MInt<N>>(A) {}
};

template<typename T>
class PolyBaseMFT3 : public PolyBase<T> {
public:
	static inline constexpr int M0 = 469762049, M1 = 998244353, M2 = 1004535809;
	static inline constexpr LL M01 = 1LL * M0 * M1;
	static inline constexpr int t0 = 554580198, t1 = 395249030;
	static inline NTT<M0> ntt0;
	static inline NTT<M1> ntt1;
	static inline NTT<M2> ntt2;
	using PolyBase<T>::PolyBase;
	PolyBaseMFT3 (const PolyBase<T> &x) : PolyBase<T>(x) {}
protected:
	static T crt(int a0, int a1, int a2) {
		static const T m01(M01);
		LL x = (a0 + 1LL * (a1 - a0) * t0 % M1 * M0) % M01;
		if (x < 0) x += M01;
		LL y = (a2 - x) % M2;
		if (y < 0) y += M2;
		y = y * t1 % M2;
		if (y < 0) y += M01;
		return T(x) + T(y) * m01;
	}
	PolyBaseMFT3 mul(const PolyBaseMFT3 &rhs) const {
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
		ntt0.dft(a0); ntt0.dft(b0);
		ntt1.dft(a1); ntt1.dft(b1);
		ntt2.dft(a2); ntt2.dft(b2);
		for (int i = 0; i < sz; ++i) {
			a0[i] *= b0[i]; a1[i] *= b1[i]; a2[i] *= b2[i];
		}
		ntt0.idft(a0); ntt1.idft(a1); ntt2.idft(a2);
		std::vector<T> ans(tot);
		for (int i = 0; i < tot; ++i) ans[i] = crt(a0[i], a1[i], a2[i]);
		return PolyBaseMFT3(ans);
	}
};

// 为什么用 4 模数 NTT 而不是两个 LL（int128 太耗时）
class PolyBaseMFT4 : public PolyBase<ModLL> {
public: // 都 4 模数了肯定是用 ModLL 啦，ctz(Mi) = 23, 所以 N 上限 4e6！
	static inline constexpr int M0 = 595591169, M1 = 645922817, M2 = 897581057, M3 = 998244353;
	static inline constexpr LL M01 = 1LL * M0 * M1, M23 = 1LL * M2 * M3;
	static inline constexpr __int128 M0123 = __int128(M01) * M23;
	static inline constexpr int t01 = 538269027, t23 = 415935157;
	static inline constexpr LL t0123 = 341204425684314487LL;
	static inline NTT<M0> ntt0;
	static inline NTT<M1> ntt1;
	static inline NTT<M2> ntt2;
	static inline NTT<M3> ntt3;
	using PolyBase<ModLL>::PolyBase;
	PolyBaseMFT4 (const PolyBase<ModLL> &x) : PolyBase<ModLL>(x) {}
protected:
	static ModLL crt(int a0, int a1, int a2, int a3) {
		LL ans1 = a0 + LL(a1 - a0) * t01 % M1 * M0;
		LL ans2 = a2 + LL(a3 - a2) * t23 % M3 * M2;
		__int128 ans = ans1 + __int128(ans2 - ans1) * t0123 % M23 * M01; // ans 不可能大于 M0123
		if (ans < 0) ans += M0123;
		return ModLL(ans);
	}
	PolyBaseMFT4 mul(const PolyBaseMFT4 &rhs) const {
		int tot = std::max(1, this->size() + rhs.size() - 1);
		int sz = 1 << std::__lg(tot * 2 - 1);
		std::vector<MInt<M0>> a0(sz), b0(sz);
		std::vector<MInt<M1>> a1(sz), b1(sz);
		std::vector<MInt<M2>> a2(sz), b2(sz);
		std::vector<MInt<M3>> a3(sz), b3(sz);
		for (int i = 0, ns = this->size(); i < ns; ++i) {
			LL tmp = this->a[i];
			a0[i] = tmp; a1[i] = tmp; a2[i] = tmp; a3[i] = tmp;
		}
		for (int i = 0, ns = rhs.size(); i < ns; ++i) {
			LL tmp = rhs.a[i];
			b0[i] = tmp; b1[i] = tmp; b2[i] = tmp; b3[i] = tmp;
		}
		ntt0.dft(a0); ntt0.dft(b0);
		ntt1.dft(a1); ntt1.dft(b1);
		ntt2.dft(a2); ntt2.dft(b2);
		ntt3.dft(a3); ntt3.dft(b3);
		for (int i = 0; i < sz; ++i) {
			a0[i] *= b0[i]; a1[i] *= b1[i]; a2[i] *= b2[i]; a3[i] *= b3[i];
		}
		ntt0.idft(a0); ntt1.idft(a1); ntt2.idft(a2); ntt3.idft(a3);
		std::vector<ModLL> ans(tot);
		for (int i = 0; i < tot; ++i) ans[i] = crt(a0[i], a1[i], a2[i], a3[i]);
		return PolyBaseMFT4(ans);
	}
};

// 当 N 特别大，或者数据处于 LL 就要慎重使用了
template<typename T>
class PolyBaseFFT : public PolyBase<T> {
protected:
	PolyBaseFFT mul(const PolyBaseFFT &rhs) const {
		int tot = std::max(1, this->size() + rhs.size() - 1);
		int sz = 1 << std::__lg(tot * 2 - 1);
		// 为了保证精度必须拆分（否则直接用 三次变两次 技巧）
		auto A1(*this), A2(*this), B1(rhs), B2(rhs);
		static constexpr int bit = 15, msk = (1LL << bit) - 1;
		for (auto &x : A1.a) x &= msk;
		for (auto &x : A2.a) x >>= bit;
		for (auto &x : B1.a) x &= msk;
		for (auto &x : B2.a) x >>= bit;
		std::vector<std::complex<double>> A(sz), B(sz), C(sz);
		for (int i = 0, tSize = this->size(); i < tSize; ++i) {
			A[i] = std::complex<double>((double)A1[i], (double)A2[i]);
		}
		for (int i = 0, rSize = rhs.size(); i < rSize; ++i) {
			B[i] = std::complex<double>((double)B1[i], (double)B2[i]);
		}
		FFT::dft(A); FFT::dft(B);
		C[0] = conj(B[0]);
		for (int i = 1; i < sz; ++i) C[i] = conj(B[sz - i]);
		for (int i = 0; i < sz; ++i) B[i] *= A[i];
		for (int i = 0; i < sz; ++i) C[i] *= A[i];
		FFT::idft(B); FFT::idft(C);
		std::vector<T> ans(tot), A1B2(tot), A1B1(tot);
		// 这里会丢掉很多精度，怎么优化呢
		for (int i = 0; i < tot; ++i) {
			A1B2[i] = llround(B[i].imag());
			A1B1[i] = llround(B[i].real() * 0.5 + C[i].real() * 0.5);
			ans[i] = llround(C[i].real() * 0.5 - B[i].real() * 0.5);
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


const constexpr int NTTM = 998244353;
using PolyNTT = Poly<PolyBaseNTT<NTTM>, MInt<NTTM>>;

const constexpr int FFTM = 1e9 + 7;
using PolyFFT = Poly<PolyBaseFFT<MInt<FFTM>>, MInt<FFTM>>;
using PolyFFTDynamic = Poly<PolyBaseFFT<ModInt>, ModInt>;
// 请勿使用，精度直接爆炸！
using PolyFFTLL = Poly<PolyBaseFFT<ModLL>, ModLL>;

// 这个较慢，仅供参考
using PolyMFT3 = Poly<PolyBaseMFT3<MInt<FFTM>>, MInt<FFTM>>;
using PolyMFTDynamic = Poly<PolyBaseMFT3<ModInt>, ModInt>;

// 四模数 NTT，由于一般 N 最大为 1e6，所以 M 最大可到 1e14
using PolyMFT = Poly<PolyBaseMFT4, ModLL>;

// 这个是原始的，可用于对拍
using PolyOrigin = Poly<PolyBaseOrigin<MInt<FFTM>>, MInt<FFTM>>;
using PolyOriginDynamic = Poly<PolyBaseOrigin<ModInt>, ModInt>;


// 求阶乘：多点求值 $O(\sqrt{n} \log^2 n)$ 算法
int factorialS(int n, int p) {
	if (n >= p) return 0;
	if (n <= 1) return 1;
	ModInt::setMod(p);
	if (n > p - 1 - n) {
		int ans = ModInt(factorialS(p - 1 - n, p)).inv();
		return (p - n) & 1 ? p - ans : ans; 
	}
	ModInt::setMod(p);
	int sn = std::sqrt(n);
	auto A = PolyFFTDynamic::prod(sn);
	std::vector<ModInt> x;
	for (int i = sn; i <= n; i += sn) x.emplace_back(i - sn + 1);
	auto y = A.evals(x);
	ModInt r(1);
	for (auto t : y) r *= t;
	for (int i = n / sn * sn + 1; i <= n; ++i) r *= ModInt::raw(i);
	return r;
}

// 求阶乘：多点求值 $O(\sqrt{n} \log n)$ 算法
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
		h = (PolyMFTDynamic(f) * PolyMFTDynamic(h)).a;
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

// 求阶乘：多点求值 $O(\sqrt{n} \log n)$ 算法，$N < 1e12$ 都能算
LL factorial(LL n, LL p) {
	if (n >= p) return 0;
	if (n <= 1) return 1;
	ModLL::setMod(p);
	if (n > p - 1 - n) {
		LL ans = ModLL(factorial(p - 1 - n, p)).inv();
		return (p - n) & 1 ? p - ans : ans; 
	}
	int s = std::sqrt(n);
	std::vector<ModLL> fac(s + 1), ifac(s + 1), inv(s + 1);
	fac[0] = inv[1] = 1;
	for (int i = 1; i <= s; ++i) fac[i] = fac[i - 1] * ModLL::raw(i);
	ifac[s] = fac[s].inv();
	for (int i = s; i > 0; --i) ifac[i - 1] = ifac[i] * ModLL::raw(i);
	for (int i = 2; i <= s; ++i) inv[i] = inv[p % i] * ModLL::raw(p - p / i);
	// 根据 $h(0), h(1), \cdots, h(d)$ 的值 求 $h(m), \cdots, h(m + cnt - 1)$
	auto solve = [&](std::vector<ModLL> h, ModLL m, int cnt) { // m > h.size()
		int d = h.size() - 1;
		for (int i = 0; i <= d; ++i) {
			h[i] *= ifac[i] * ifac[d - i];
			if ((d - i) & 1) h[i] = -h[i];
		}
		std::vector<ModLL> f(d + cnt);
		auto now = m - ModLL(d);
		for (int i = 0; i < d + cnt; ++i) {
			f[i] = now.inv();
			++now;
		}
		h = (PolyMFT(f) * PolyMFT(h)).a;
		h.resize(d + cnt);
		h = std::vector<ModLL>(h.begin() + d, h.end());
		now = 1;
		for (int i = 0; i <= d; ++i) now *= m - ModLL::raw(i);
		h[0] *= now;
		for (int i = 1; i < cnt; ++i) {
			now *= m + ModLL::raw(i);
			now *= (m + ModLL(i - d - 1)).inv();
			h[i] *= now;
		}
		return h;
	};
	auto invS = ModLL(s).inv();
	std::vector<ModLL> h{1, s + 1};
	for (int bit = std::__lg(s) - 1, d = 1; bit >= 0; --bit) {
		auto nh1 = solve(h, d + 1, d);
		auto nh2 = solve(h, invS * ModLL(d), 2 * d + 1);
		h.insert(h.end(), nh1.begin(), nh1.end());
		d *= 2;
		for (int i = 0; i <= d; ++i) h[i] *= nh2[i];
		if (s >> bit & 1) {
			++d;
			LL tmp = d;
			for (int i = 0; i < d; ++i, tmp += s) h[i] *= ModLL::raw(tmp);
			ModLL last(1), tj = 1LL * s * d;
			for (int i = 0; i < d; ++i) ++tj, last *= tj;
			h.emplace_back(last);
		}
	}
	ModLL ans = 1;
	for (int i = 0; i < s; ++i) ans *= h[i];
	for (LL i = 1LL * s * s + 1; i <= n; ++i) ans *= ModLL::raw(i);
	return ans;
}
// 终极例题：https://vjudge.net/problem/SPOJ-FACTMODP


const int M = 998244353;
using mod = MInt<M>;

std::vector<mod> stirling1row(int n) {
	auto B = PolyNTT::prod(n).a;
	B.resize(n + 1);
	return B;
}
std::vector<mod> stirling1col(int n, int k) {
	if (k > n)  return std::vector<mod>(n + 1);
	auto B = PolyNTT({1, -1}).log(n + 2 - k).divXn(1);
	B = (-B).log(n + 1 - k);
	for (auto &x : B.a) x *= mod::raw(k);
	auto ans = B.exp(n + 1 - k).mulXn(k).a;
	std::vector<mod> fac(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * mod::raw(i);
	mod ifacK = fac[k].inv();
	ans.resize(n + 1);
	for (int i = 0; i <= n; ++i) ans[i] *= fac[i] * ifacK;
	return ans;
}
std::vector<mod> stirling2row(int n) {
	std::vector<mod> fac(n + 1), ifac(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * mod::raw(i);
	ifac[n] = fac[n].inv();
	for (int i = n; i > 0; --i) ifac[i - 1] = ifac[i] * mod::raw(i);
	auto tmp = ifac, a = ifac;
	for (int i = 1; i <= n; i += 2) tmp[i] = -tmp[i];
	for (int i = 0; i <= n; ++i) a[i] *= pow(mod::raw(i), n);
	auto ans = (PolyNTT(a) * PolyNTT(tmp)).a;
	ans.resize(n + 1);
	return ans;
}
std::vector<mod> stirling2col(int n, int k) {
	if (k > n)  return std::vector<mod>(n + 1);
	std::vector<mod> fac(n + 1), ifac(n + 1);
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * mod::raw(i);
	ifac[n] = fac[n].inv();
	for (int i = n; i > 0; --i) ifac[i - 1] = ifac[i] * mod::raw(i);
	PolyNTT A(ifac);
	A = A.divXn(1).modXn(n + 1 - k);
	A = A.log(n + 1 - k);
	for (auto &x : A.a) x *= mod::raw(k);
	A = A.exp(n + 1 - k).mulXn(k);
	auto ans = A.a;
	ans.resize(n + 1);
	auto ifacK = ifac[k];
	for (int i = 0; i <= n; ++i) ans[i] *= fac[i] * ifacK;
	return ans;
}

