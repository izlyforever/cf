#pragma once
#include <bits/stdc++.h>
using LL = long long;

// 考虑环 $\mathbb{z}[sqrt{N}]: a + b sqrt{N}$
class SqrtZn {
	static inline int N;
public:
	LL a, b;
	static void setMod(int x) { N = x;}
	SqrtZn() {}
	SqrtZn(LL x, LL y = 0) : a(x), b(y) {}
	SqrtZn operator-() { return SqrtZn(-a, -b);}
	SqrtZn operator+(const SqrtZn &rhs) const { return SqrtZn(a + rhs.a, b + rhs.b);}
	SqrtZn operator-(const SqrtZn &rhs) const { return SqrtZn(a - rhs.a, b - rhs.b);}
	SqrtZn operator*(const SqrtZn &rhs) const { return SqrtZn(a * rhs.a + b * rhs.b * N, a * rhs.b + b * rhs.a);}
	SqrtZn& operator+=(const SqrtZn &rhs) {return *this = SqrtZn(*this) + rhs;}
	SqrtZn& operator-=(const SqrtZn &rhs) {return *this = SqrtZn(*this) - rhs;}
	SqrtZn& operator*=(const SqrtZn &rhs) {return *this = SqrtZn(*this) * rhs;}
	bool operator<(const SqrtZn &rhs) const { return a < rhs.a;}
};
// 例题：HDU 6222, 2281（建议都使用 int128）

template<int N>
class MInt {
	static inline constexpr int M = N;
	int n;
	static int inv(int x) {
		// assert(std::gcd(x, M) == 1);
		return x == 1 ? x : 1LL * (M - M / x) * inv(M % x) % M;
	}
public:
	static void setMod(int m) {
		M = m;
	}
	static constexpr int mod() {
		return M;
	}
	// 请自行确保 0 <= x < M
	static MInt raw(int x) {
		MInt A;
		A.n = x;
		return A;
	}
	MInt(int x = 0) : n(x % M) {
		if (n < 0) n += M;
	}
	MInt(LL x) : n(x % M) {
		if (n < 0) n += M;
	}
	operator int() const {
		return n;
	}
	MInt operator-() const {
		return n == 0 ? *this : raw(M - n);
	}
	MInt& operator++() {
		if (++n == M) n = 0;
		return *this;
	}
	MInt& operator--() {
		if (--n == -1) n += M;
		return *this;
	}
	MInt& operator+=(const MInt &A) {
		n += A.n;
		if (n >= M) n -= M;
		return (*this);
	}
	MInt& operator-=(const MInt &A) {
		n -= A.n;
		if (n < 0) n += M;
		return (*this);
	}
	MInt& operator*=(const MInt &A) {
		n = 1LL * n * A.n % M;
		return (*this);
	}
	MInt& operator/=(const MInt &A) {
		return (*this) *= A.inv();
	}
	MInt operator+(const MInt &A) const {
		return MInt(*this) += A;
	}
	MInt operator-(const MInt &A) const {
		return MInt(*this) -= A;
	}
	MInt operator*(const MInt &A) const {
		return MInt(*this) *= A;
	}
	MInt operator/(const MInt &A) const {
		return MInt(*this) /= A;
	}
	MInt operator<<(int x) const {
		LL r = n;
		r <<= x;
		return MInt(r);
	}
	MInt& operator<<=(int x) {
		return (*this) = (*this) << x;
	}
	MInt& operator>>=(int x) {
		n >>= x;
		return (*this);
	}
	MInt operator>>(int x) const {
		return MInt(*this) >> x;
	}
	MInt operator&(int x) const {
		return MInt(*this) & x;
	}
	MInt& operator&=(int x) {
		n &= x;
		return (*this);
	}
	bool operator==(const MInt &A) const {
		return n == A.n;
	}
	MInt inv() const {
		return inv(n);
	}
	friend MInt pow(MInt A, int n) {
		MInt R(1);
		while (n) {
			if (n& 1) R *= A;
			n >>= 1;  A *= A;
		}
		return R;
	}
	friend std::istream &operator>>(std::istream &in, MInt &A) {
		LL x;
		in >> x;
		A = MInt(x);
		return in;
	}
	friend std::ostream &operator<<(std::ostream &out, const MInt &A) {
		out << A.n;
		return out;
	}
};

class ModInt {
	static inline int M = 998244353;
	int n;
	static int inv(int x) {
		// assert(std::gcd(x, M) == 1);
		return x == 1 ? x : 1LL * (M - M / x) * inv(M % x) % M;
	}
public:
	static void setMod(int m) {
		M = m;
	}
	static int mod() {
		return M;
	}
	// 自行确保 0 <= x < M
	static ModInt raw(int x) {
		ModInt A;
		A.n = x;
		return A;
	}
	ModInt(int x = 0) : n(x % M) {
		if (n < 0) n += M;
	}
	ModInt(LL x) : n(x % M) {
		if (n < 0) n += M;
	}
	ModInt operator-() const {
		return n == 0 ? *this : raw(M - n);
	}
	ModInt& operator++() {
		if (++n == M) n = 0;
		return *this;
	}
	ModInt& operator--() {
		if (--n == -1) n += M;
		return *this;
	}
	operator int() const {
		return n;
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
		return ModInt(r);
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
	bool operator==(const ModInt &A) const {
		return n == A.n;
	}
	ModInt inv() const {
		return inv(n);
	}
	friend ModInt pow(ModInt A, int n) {
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


class ModLL {
	static inline LL M = 998244353;
	LL n;
	static LL inv(LL x) {
		// assert(std::gcd(x, M) == 1);
		return x == 1 ? x : __int128(M - M / x) * inv(M % x) % M;
	}
public:
	static void setMod(LL m) {
		M = m;
	}
	static LL mod() {
		return M;
	}
	// 自行确保 0 <= x < M
	static ModLL raw(LL x) {
		ModLL A;
		A.n = x;
		return A;
	}
	ModLL(__int128 x = 0) : n(x % M) {
		if (n < 0) n += M;
	}
	ModLL operator-() const {
		return n == 0 ? *this : raw(M - n);
	}
	ModLL& operator++() {
		if (++n == M) n = 0;
		return *this;
	}
	ModLL& operator--() {
		if (--n == -1) n += M;
		return *this;
	}
	operator LL() const {
		return n;
	}
	ModLL& operator+=(const ModLL &A) {
		n += A.n;
		if (n >= M) n -= M;
		return (*this);
	}
	ModLL& operator-=(const ModLL &A) {
		n -= A.n;
		if (n < 0) n += M;
		return (*this);
	}
	ModLL& operator*=(const ModLL &A) {
		n = __int128(n) * A.n % M;
		return (*this);
	}
	ModLL& operator/=(const ModLL &A) {
		return (*this) *= A.inv();
	}
	ModLL operator+(const ModLL &A) const {
		return ModLL(*this) += A;
	}
	ModLL operator-(const ModLL &A) const {
		return ModLL(*this) -= A;
	}
	ModLL operator*(const ModLL &A) const {
		return ModLL(*this) *= A;
	}
	ModLL operator/(const ModLL &A) const {
		return ModLL(*this) /= A;
	}
	ModLL operator<<(int x) const {
		__int128 r = n;
		r <<= x;
		return ModLL(r);
	}
	ModLL& operator<<=(int x) {
		return (*this) = (*this) << x;
	}
	ModLL& operator>>=(int x) {
		n >>= x;
		return (*this);
	}
	ModLL operator>>(int x) const {
		return ModLL(*this) >> x;
	}
	ModLL operator&(int x) const {
		return ModLL(*this) & x;
	}
	ModLL& operator&=(LL x) {
		n &= x;
		return (*this);
	}
	bool operator==(const ModLL &A) const {
		return n == A.n;
	}
	ModLL inv() const {
		return inv(n);
	}
	friend ModLL pow(ModLL A, LL n) {
		ModLL R(1);
		while (n) {
			if (n& 1) R *= A;
			n >>= 1;  A *= A;
		}
		return R;
	}
	friend std::istream &operator>>(std::istream &in, ModLL &A) {
		LL x;
		in >> x;
		A = ModLL(x);
		return in;
	}
	friend std::ostream &operator<<(std::ostream &out, const ModLL &A) {
		out << A.n;
		return out;
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


// 为了支持三模数，改成模板类的形式
template<int M>
class NTT { // 请自行保证输入的 N 为 原根 3 的 NTT-friendly 素数
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

template<typename T> // 仅用于 ModInt 和 MInt
class BinomInPoly {
public:
	std::vector<T> fac, ifac, inv;
	BinomInPoly(int n) : fac(n), ifac(n), inv(n) {
		int M = T::mod();
		ifac[0] = fac[0] = inv[1] = 1;
		for (int i = 2; i < n; ++i) inv[i] = inv[M % i] * T::raw(M - M / i);
		for (int i = 1; i < n; ++i) fac[i] = fac[i - 1] * T::raw(i);
		for (int i = 1; i < n; ++i) ifac[i] = ifac[i - 1] * inv[i];
		// ifac[n - 1] = fac[n - 1].inv();
		// for (int i = n - 1; i > 0; --i) ifac[i - 1] = ifac[i] * T(i);
	}
};