#pragma once
#include <bits/stdc++.h>
using LL = long long;

template<int N>
class MInt {
	static inline constexpr int M = N;
	int n;
public:
	static int inv(int x) {
		// assert(std::gcd(x, M) == 1);
		return x == 1 ? x : 1LL * (M - M / x) * inv(M % x) % M;
	}
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
	MInt(LL x = 0) : n(x % M) {
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
	ModInt(LL x = 0) : n(x % M) {
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
		n = 1LL * n * A.n % M;
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