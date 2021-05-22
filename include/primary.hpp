#pragma once
#include <bits/stdc++.h>
using LL = long long;

int powMod(int x, int n, int p) {
	int r = 1;
	while (n) {
		if (n&1) r = 1LL * r * x % p;
		n >>= 1; x = 1LL * x * x % p;
	}
	return r;
}

namespace int128 { // 请勿与 cin/cout 混用！
__int128 read(){
	__int128 x = 0;
	bool negetive = false;
	char ch = getchar();
	while (ch < '0' || ch > '9'){
		if (ch == '-') negetive = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return negetive ?  -x : x;
}

void printS(__int128 x){
	if (x > 9) printS(x / 10);
	putchar(x % 10 + '0');
}
void print(__int128 x){ 
	if (x < 0) {
		putchar('-');
		x = -x;
	}
	printS(x);
}
} // namespace int128

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

// 求逆 0 < a < p and gcd(a,p) = 1，单次 p 为奇素数时，请使用 powMod(a, p - 2, p)
// 猜想复杂度为 $O(\log^2 p)$，已知上界 O(\sqrt{N})
int inv(int a, int p){
	return a == 1 ? 1 : 1LL * (p - p / a) * inv(p % a, p) % p;
}
// O(n) 预处理全部逆元
std::vector<int> initInv(int N, int M) {
	std::vector<int> inv(N);
	inv[1] = 1;
	for (int i = 2; i < N; ++i) inv[i] = 1LL * (M - M / i) * inv[M % i] % M;
	return inv;
}

// 快速计算 gcd，效率稍微比 std::gcd 快
LL gcd(LL a, LL b) {
	if (!a || !b) return a | b;
	unsigned shift = __builtin_ctzll(a | b);
	a >>= __builtin_ctzll(a);
	do {
		b >>= __builtin_ctzll(b);
		if (a > b) std::swap(a, b);
		b -= a;
	} while (b);
	return a << shift;
}
// 参考 https://cp-algorithms.com/algebra/euclid-algorithm.html

// ax + by = gcd(a,b)
template<typename T>
std::tuple<T, T, T> exGcd(T a, T b) {
	if (b == 0) return {a, 1, 0};
	auto [d, y, x] = exGcd(b, a % b);
	return {d, x, y - a / b * x};
}

// n 个集合中选 k 个，二进制为 1 的表示选择
void GospersHack(int n, int k) {
	int cur = (1 << k) - 1;
	while (!(cur >> n)) {
		// do something
		int lb = __builtin_ctz(cur);
		int r = cur + (1 << lb);
		cur = ((r ^ cur) >> (2 + lb)) | r;
	}
}

void GospersHackS(int n, int k) {
	int cur = (1 << k) - 1;
	while (!(cur >> n)) {
		// do something
		int lb = cur & -cur;
		int r = cur + lb;
		cur = (((r ^ cur) >> 2) / lb) | r;
	}
}


// 一般情况下 N < 1e6, M 必须是一个小于 INT_MAX 的素数
namespace Binom {
const int CN = 65; // 再大就超 LL 了
LL C[CN][CN];
void initC() {
	for (int i = 0; i < CN; ++i) C[i][0] = C[i][i] = 1;
	for (int i = 1; i < CN; ++i) {
		for (int j = 1; j < i; ++j) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}
}
int N = 0, M = 1e9 + 7;
std::vector<int> fac, ifac;
void setMod(int m) {
	M = m;
	fac[0] = 1;
	for (int i = 1; i < N; ++i) fac[i] = 1LL * fac[i - 1] * i % M;
	ifac[N - 1] = powMod(fac[N - 1], M - 2, M);
	for (int i = N - 1; i; --i) ifac[i - 1] = 1LL * ifac[i] * i % M;
}
// 请确保 n < m，否则无法保证后面的正确性
void init(int n, int m = M) {
	N = n;
	fac.resize(N);
	ifac.resize(N);
	setMod(m);
	initC();
}
// 需要预处理小于 n 的所有值！
int binom(int n, int k) {
	if (n < 0 || n < k) return 0;
	return 1LL * fac[n] * ifac[k] % M * ifac[n - k] % M;
}
// 一般说来需要预处理出小于 M 的所有值，且 M 是素数！
int lucas(int n, int k) {
	int r = 1;
	while (n && k) {
		int np = n % M, kp = k % M;
		if (np < kp) return 0;
		r = 1LL * r * binom(np, kp) % M;
		n /= M; k /= M;
	}
	return r;
}
} // namespace Binom
// 模板例题：https://www.luogu.com.cn/problem/P3807


namespace Stirling {
constexpr int N = 1e3 + 2, M = 1e9 + 7;
std::vector<std::vector<int>> S1(N), S2(N);
void init() {
	S1[0] = {1, 0};
	for (int i = 1; i < N; ++i) {
		S1[i].resize(i + 2);
		for (int j = 1; j <= i; ++j) {
			S1[i][j] = (1LL * S1[i - 1][j] * (i - 1) + S1[i - 1][j - 1]) % M;
		}
	}
	S2[0] = {1, 0};
	for (int i = 1; i < N; ++i) {
		S2[i].resize(i + 2);
		for (int j = 1; j <= i; ++j) {
			S2[i][j] = (1LL * S2[i - 1][j] * j + S2[i - 1][j - 1]) % M;
		}
	}
}
} // namespace Stirling
// 模板例题：https://www.luogu.com.cn/problem/P5408
// 模板例题：https://www.luogu.com.cn/problem/P5395

// 中国剩余定理：x = ai mod mi, m_i > 0, 0 <= a_i < m_i
std::pair<LL, LL> crt2(LL a1, LL m1, LL a2, LL m2){
	auto [d, t1, t2] = exGcd(m1, m2);
	assert((a2 - a1) % d == 0);
	LL m = m1 / d * m2;
	LL ans = (a1 + (a2 - a1) / d * t1 % m2 * m1) % m;
	return std::make_pair(ans < 0 ? ans + m: ans, m);
}
std::pair<LL, LL> crt(const std::vector<std::pair<LL, LL>> &a){
	auto ans = a[0];
	for (int i = 1, na = a.size(); i < na; ++i) {
		ans = crt2(ans.first, ans.second, a[i].first, a[i].second);
	}
	return ans;
}
// 模板例题：https://www.luogu.com.cn/problem/P1495


// 计算在 f 处的 lagrange 函数在 m 点的取值（模 M），M 为素数，0 <= f[i] < M
int Lagrange(const std::vector<int> &f, int m, int M) {
	int n = f.size();
	if (m < n) return f[m];
	int nfac = 1;
	for (int i = 2; i < n; ++i) nfac = 1LL * nfac * i % M;
	std::vector<int> ifac(n), AP(n), BP(n);
	ifac[n - 1] = powMod(nfac, M - 2, M);
	for (int i = n - 1; i > 0; --i) ifac[i - 1] = 1LL * ifac[i] * i % M;
	AP[0] = BP[n - 1] = 1;
	for (int i = 1; i < n; ++i) AP[i] = 1LL * AP[i - 1] * (m + 1 - i) % M;
	for (int i = n - 2; ~i; --i) BP[i] = 1LL * BP[i + 1] * (m - 1 - i) % M;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int x = 1LL * f[i] * AP[i] % M * BP[i] % M * ifac[i] % M * ifac[n - 1 - i] % M;
		ans += (n - 1 - i) & 1 ? M - x : x;
		if (ans >= M) ans -= M;
	}
	return ans;
}
// 由 lagrange 插值定理 知f(x) =  \sum_{i = 0}^{n - 1} f_i \prod_{j \neq i} \frac{x - j}{i - j}
// 简化得 f(m) = \sum_{i = 0}^{n - 1} (-1)^{n - 1 - i} f_i \binom{m}{i} \binom{m - i - 1}{n - 1 - i}

// 基于 lagrange 插值 O(k) 计算自然数方幂和
int powSum(int n, int k, int M, const std::vector<int> &sp){
	if (k == 0) return n % M;
	std::vector<int> f(k + 2);
	f[1] = 1;
	for (int i = 2, nf = f.size(); i < nf; ++i) {
		if (sp[i] == i) f[i] = powMod(i, k, M);
		else f[i] = 1LL * f[sp[i]] * f[i / sp[i]] % M;
	}
	for (int i = 1, nf = f.size(); i < nf; ++i) {
		f[i] += f[i - 1];
		if (f[i] >= M) f[i] -= M;
	}
	return Lagrange(f, n, M);
}
//模板例题：https://codeforces.com/problemset/problem/622/F


namespace FMT {
constexpr int M = 998244353, inv2 = (M + 1) / 2;
auto add = [](int &x, int y) {
	(x += y) >= M && (x -= M);
};
auto sub = [](int &x, int y) {
	(x -= y) < 0 && (x += M);
};
auto extend = [](int n) {
	int r = std::log(n);
	while ((1 << r) < n) ++r;
	return r; 
};
auto FMTor = [](std::vector<int> &a, bool isRev) {
	int n = extend(a.size());
	a.resize(1 << n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (1 << n); ++j) if ((j >> i) & 1) {
			if (isRev) sub(a[j], a[j ^ (1 << i)]);
			else add(a[j], a[j ^ (1 << i)]);
		}
	}
};
auto FMTand = [](std::vector<int> &a, bool isRev) {
	int n = extend(a.size());
	a.resize(1 << n);
	for (int i = 0; i < n; ++i) {
		for (int j = (1 << n) - 1; j >= 0; --j) if ((j >> i) & 1) {
			if (isRev) sub(a[j ^ (1 << i)], a[j]);
			else add(a[j ^ (1 << i)], a[j]);
		}
	}
};
auto FMTxor = [](std::vector<int> &a, bool isRev) {
	int n = extend(a.size());
	a.resize(1 << n);
	for (int i = 0; i < n; ++i) {
		for (int j = (1 << n) - 1; j >= 0; --j) if ((j >> i) & 1) {
			int u = a[j], v = a[j ^ (1 << i)];
			a[j] = (v - u + M) % M;
			a[j ^ (1 << i)] = (u + v) % M;
		}
		if (isRev) for (auto &x : a) x = 1LL * inv2 * x % M;
	}
};
auto fun = [](std::function<void(std::vector<int> &, bool)> f, std::vector<int> a, std::vector<int> b) {
	int n = extend(std::max(a.size(), b.size()));
	a.resize(1 << n); b.resize(1 << n);
	f(a, 0); f(b, 0);
	std::vector<int> c(1 << n);
	for (int i = 0; i < (1 << n); ++i) c[i] = 1LL * a[i] * b[i] % M;
	f(c, 1);
	return c;
};
auto Or = [](std::vector<int> a, std::vector<int> b) {
	return fun(FMTor, a, b);
};
auto And = [](std::vector<int> a, std::vector<int> b) {
	return fun(FMTand, a, b);
};
auto Xor = [](std::vector<int> a, std::vector<int> b) {
	return fun(FMTxor, a, b);
};
// i = j | k and j & k = 0
auto OrAnd = [](std::vector<int> a, std::vector<int> b) {
	int n = extend(std::max(a.size(), b.size()));
	a.resize(1 << n); b.resize(1 << n);
	std::vector<std::vector<int>> sa(n + 1, std::vector<int>(1 << n));
	auto sb = sa, sc = sa;
	for (int i = 0; i < (1 << n); ++i) sa[__builtin_popcount(i)][i] = a[i];
	for (int i = 0; i < (1 << n); ++i) sb[__builtin_popcount(i)][i] = b[i];
	for (int i = 0; i <= n; ++i) {
		FMTor(sa[i], 0);FMTor(sb[i], 0);
	}
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= i; ++j) {
			for (int k = 0; k < (1 << n); ++k) {
				add(sc[i][k], 1LL * sa[j][k] * sb[i - j][k] % M);
			}
		}
		FMTor(sc[i], 1);
	}
	std::vector<int> c(1 << n);
	for (int i = 0; i < (1 << n); ++i) c[i] = sc[__builtin_popcount(i)][i];
	return c;
};
} // namespace FMT


// 计算集合 S 中所有数与 x 异或后的 MEX 值。
class MEX {
	// 具体数值要对应修改。
	static inline constexpr int B = 20;
	std::array<std::map<int, int>, B> mp;
	std::map<int, int> S;
public:
	void insert(int x) {
		if (S[x]++) return;
		int mask = 0;
		for (int i = B - 1; i >= 0; --i) {
			mask |= 1 << i;
			++mp[i][x & mask];
		}
	}
	void erase(int x) {
		if (--S[x]) return;
		S.erase(x);
		int mask = 0;
		for (int i = B - 1; i >= 0; --i) {
			mask |= 1 << i;
			--mp[i][x & mask];
		}
	}
	// find mex(a_i ^ x)
	int solve(int x = 0) {
		int mask = 0, r = 0;
		for (int i = B - 1; i >= 0; --i) {
			mask |= x & (1 << i);
			if (mp[i][mask] == (1 << i)) {
				mask ^= 1 << i;
				r |= 1 << i;
			}
		}
		return r;
	}
};