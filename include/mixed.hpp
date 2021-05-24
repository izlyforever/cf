#pragma once
#include <bits/stdc++.h>
#include "poly.hpp"
using LL = long long;

// O(\log n) 计算 \displaystyle \sum_{i = 0}^{n - 1} \lfloor \frac{a \cdot i + b}{m} \rfloor
LL floorSum(int n, int m, int a, int b) {
	LL r = 0;
	if (a >= m) {
		r += 1LL * a / m * (n - 1) * n / 2;
		a %= m;
	}
	if (b >= m) {
		r += 1LL * b / m * n;
		b %= m;
	}
	int yMax = (1LL * a * n + b) / m;
	if (yMax == 0) return r;
	r += 1LL * (n - 1) * yMax;
	r -= floorSum(yMax, a, m, m - b - 1);
	return r;
}
// 模板例题：https://atcoder.jp/contests/practice2/tasks/practice2_c

// \sum_{\sum c_i x_i = m} \frac{(\sum x_i)!}{\prod (x_i !)}
int sumNum(const std::vector<int> &c, int m, int M) {
	std::vector<int> dp(m + 1);
	dp[0] = 1;
	for (int i = 1; i <= m; ++i) {
		for (auto x : c) if (x <= i) {
			dp[i] += dp[i - x];
			if (dp[i] >= M) dp[i] -= M;
		}
	}
	return dp[m];
}
// 解释：https://dna049.com/classicalCombination/

// 每次可选择 n 减一 或 m 加一，使得 m 是 n 的倍数的最小次数
int decInc(int n, int m) {
	if (n > m) return n - m;
	int ans = n - 1;
	// 让 n 变成 i，那么结果就是 n - i + (m % i ? i - m % i : 0) <= n - m % i
	// 注意到 m % i = m - m / i * i 因此可以用数论分块技术加速
	for (int i = 1; i <= n; i = m / (m / i) + 1) {
		ans = std::min(ans, n - m % i);
	}
	// 再特判一下 m % i == 0 的情况
	for (int i = 1; i <= n && i * i <= m; ++i) if (m % i == 0) {
		ans = std::min(ans, n - i);
		if (m / i <= n) ans = std::min(ans, n - m / i);
	}
	return ans;
}

// finds min x s.t. L <= (A * x) % M <= R (or -1 if it does not exist)
int FirstInRange(int a, int m, int l, int r) { // 0 <= L <= R < M, 0 < a < M
	if (l == 0) return 0;
	std::function<std::pair<int, int>(int, int)> dfs = [&](int a, int m) -> std::pair<int, int> {
		if (a == 0) return std::pair(-1, 0);
		if (a > m - a) {
			std::tie(l, r) = std::pair(m - r, m - l);
			auto [x, y] = dfs(m - a, m);
			return std::pair(x, x - y - 1);
		}
		int k = (l + a - 1) / a;
		if (k * a <= r) return std::pair(k, 0);
		--k;
		l -= k * a;
		r -= k * a;
		int z = (m + a - 1) / a;
		auto [x, y] = dfs(z * a - m, a);
		return x == -1 ? std::pair(-1, -1) : std::pair(k + x * z - y, x);
	};
	return dfs(a, m).first;
}


class Matrix {
public:
	static constexpr int N = 1003;
	int n, a[N][N], mod;
	Matrix() {}
	Matrix(int _n, int x = 0): n(_n) { // xIn
		all(0);
		for (int i = 0; i < n; ++i) {
			a[i][i] = x;
		}
	}
	void all(int x) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				a[i][j] = x;
			}
		}
	}
	Matrix operator + (const Matrix & A) const {
		Matrix R(n);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				R.a[i][j] = a[i][j] + A.a[i][j];
				if (R.a[i][j] >= mod) R.a[i][j] -= mod;
			}
		}
		return R;
	}
	Matrix operator * (const Matrix & A) const {
		Matrix R(n);
		for (int i = 0; i < n; ++i) {
			for (int k = 0; k < n; ++k) {
				for (int j = 0; j < n; ++j) {
					R.a[i][j] = (R.a[i][j] + 1LL * a[i][k] * A.a[k][j]) % mod;
				}
			}
		}
		return R;
	}
	void print() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				std::cout << a[i][j] << ' ';
			}
			std::cout << std::endl;
		}
	}
};
Matrix pow(Matrix A, int n) {
	Matrix R(A.n, 1);
	while (n) {
		if (n&1) R = R * A;
		n >>= 1; A = A * A;
	}
	return R;
}

// Gauss 消元法 Ax = b 浮点数版
std::vector<double> Gauss(std::vector<std::vector<double>> A, std::vector<double> b) {
	int n = A.size(), m = A[0].size();
	std::vector<double> x(m);
	std::vector<int> p(m);
	std::iota(p.begin(), p.end(), 0);
	const double eps = 1e-12;
	auto findNonZero = [&](int i) { // 实际上找最大的比较好
		for (int row = i; row < n; ++row) if (fabs(A[row][i]) > eps) return row;
		return n;
	};
	auto triangleGauss = [&](int sz) { // A[i][i] = 1
		std::vector<double> x(sz);
		for (int i = sz - 1; i >=0; --i) {
			x[i] = b[i];
			for (int row = 0; row < i; ++row) b[row] -= A[row][i] * x[i];
		}
		x.resize(A[0].size());
		return x;
	};
	int sz = n;
	for (int i = 0, row; i < n; ++i) {
		while (i < m) {
			row = findNonZero(i);
			if (row != n) break;
			for (int j = 0; j < n; ++j) A[j][i] = A[j][m - 1];
			std::swap(p[i], p[--m]);
		}
		if (i == m) {
			for (int row = m; row < n; ++row) if (fabs(b[row])) {
				// std::cout << "\nNo answer\n";
				return std::vector<double>();
			}
			sz = i;
			break;
		}
		if (row != i) {
			std::swap(A[row], A[i]);
			std::swap(b[row], b[i]);
		}
		b[i] /= A[i][i];
		for (int j = m - 1; j >= i; --j) A[i][j] /= A[i][i];
		for (int row = i + 1; row < n; ++row) {
			b[row] -= A[row][i] * b[i];
			for (int j = m - 1; j >= i; --j) {
				A[row][j] -= A[row][i] * A[i][j];
			}
		}
	}
	// if (sz != A[0].size()) std::cout << "\nInfinite answer\n";
	auto xt = triangleGauss(sz);
	for (int t = 0, na = A[0].size(); t < na; ++t) x[p[t]] = xt[t];
	return x;
}

// 模 Gauss 消元法 Ax = b
std::vector<int> Gauss(std::vector<std::vector<int>> A, std::vector<int> b) {
	constexpr int M = 998244353;
	int n = A.size(), m = A[0].size();
	std::vector<int> x(m), p(m);
	std::iota(p.begin(), p.end(), 0);
	auto sub = [](int &x, int y) {
		(x -= y) < 0 && (x += M);
	};
	auto triangleGauss = [&](int sz) { // A[i][i] = 1
		std::vector<int> x(sz);
		for (int i = sz - 1; i >=0; --i) {
			x[i] = b[i];
			if (x[i] < 0) x[i] += M;
			for (int row = 0; row < i; ++row) sub(b[row], 1LL * A[row][i] * x[i] % M);
		}
		x.resize(A[0].size());
		return x;
	};
	auto findNonZero = [&](int i) {
		for (int row = i; row < n; ++row) if (A[row][i]) return row;
		return n;
	};
	int sz = n;
	for (int i = 0, row; i < n; ++i) {
		while (i < m) {
			row = findNonZero(i);
			if (row != n) break;
			for (int j = 0; j < n; ++j) A[j][i] = A[j][m - 1];
			std::swap(p[i], p[--m]);
		}
		if (i == m) {
			for (int row = m; row < n; ++row) if (b[row]) {
				// std::cout << "\nNo answer\n";
				return {};
			}
			sz = i;
			break;
		}
		if (row != i) {
			std::swap(A[i], A[row]);
			std::swap(b[i], b[row]);
		}
		int inva = powMod(A[i][i], M - 2, M);
		b[i] = b[i] * inva % M;
		for (int j = m - 1; j >= i; --j) A[i][j] = 1LL * A[i][j] * inva % M;
		for (int row = i + 1; row < n; ++row) {
			sub(b[row], 1LL * A[row][i] * b[i] % M);
			for (int j = m - 1; j >= i; --j) {
				sub(A[row][j], 1LL * A[row][i] * A[i][j] % M);
			}
		}
	}
	// if (sz != A[0].size()) std::cout << "\nInfinite answer\n";
	auto xt = triangleGauss(sz);
	for (int t = 0, na = A[0].size(); t < na; ++t) x[p[t]] = xt[t];
	return x;
}

// 线性规划单纯形法
using VD = std::vector<double>;
const double eps = 1e-10;
const double inf = 1e10;
// make sure that A = (I, A') and b >= 0, compute max cx
VD simplexCore(VD c, std::vector<VD> A, VD b) {
	int n = A.size(), m = c.size();
	std::vector<int> p(m);
	std::iota(p.begin(), p.end(), 0);
	for (int i = 0; i < n; ++i) A[i].emplace_back(b[i]);
	c.emplace_back(0);
	A.emplace_back(c);
	for (int j = n; j <= m; ++j) {
		for (int i = 0; i < n; ++i) {
			A[n][j] -= A[n][i] * A[i][j];
		}
	}
	auto check = [&]() -> bool {
		for (int j = n; j < m; ++j) if (A[n][j] > eps) {
			bool flag = false;
			for (int i = 0; i < n; ++i) if (A[i][j] > eps) {
				flag = true;
				break;
			}
			if (!flag) return false;
		}
		return true;
	};
	while (1) {
		int ch = std::max_element(A[n].begin() + n, A[n].begin() + m) - A[n].begin(), hc;
		if (A[n][ch] < eps) break;	
		assert(check()); // otherwise unbounded, no max solution
		double theta = DBL_MAX;
		for (int i = 0; i < n; ++i) if (A[i][ch] > eps && A[i].back() / A[i][ch] < theta) {
			theta = A[i].back() / A[i][ch];
			hc = i;
		}
		std::swap(p[ch], p[hc]);
		double tmp = 1 / A[hc][ch];
		for (int j = n; j <= m; ++j) A[hc][j] *= tmp;
		for (int i = 0; i <= n; ++i) if (i != hc) {
			for (int j = n; j <= m; ++j) if (j != ch) {
				A[i][j] -= A[i][ch] * A[hc][j];
			}
		}
		for (int i = 0; i <= n; ++i) A[i][ch] *= -tmp;
		A[hc][ch] = tmp;
	}
	VD x(m);
	for (int i = 0; i < n; ++i) x[p[i]] = A[i].back();
	// watch(-A.back().back()); // max_val
	return x; // point Corresponds to max_val
}
// compute max cx, with Aqx = bq and Alq x <= blq, end of 0 can be ommit in A and Aq
VD simplex(VD c, std::vector<VD> Aq, VD bq, std::vector<VD> Alq, VD blq) {
	assert(Aq.size() == bq.size());
	assert(Alq.size() == blq.size());
	int n = Aq.size() + Alq.size();
	int m = c.size();
	for (int i = 0, nb = bq.size(); i < nb; ++i) if (bq[i] < -eps) {
		for (auto &x : Aq[i]) x = -x;
		bq[i] = -bq[i];
	}
	for (int i = 0, nb = blq.size(); i < nb; ++i) if (blq[i] < -eps) {
		for (auto &x : Alq[i]) x = -x;
		++m;
	}
	std::vector<VD> A(n, VD(n + m));
	VD f(n + m), b(n);
	int now = n + c.size();
	for (int i = 0; i < n; ++i) A[i][i] = 1;
	for (int i = 0, na = Aq.size(); i < na; ++i) {
		for (int j = 0; j < na; ++j) A[i][n + j] = Aq[i][j];
		b[i] = bq[i];
		f[i] = -inf;
	}
	for (int i = 0, na = Alq.size(); i < na; ++i) {
		for (int j = 0; j < na; ++j) A[i + Aq.size()][n + j] = Alq[i][j];
		if (blq[i] < -eps) {
			A[i + Aq.size()][now++] = -1;
			f[i + Aq.size()] = -inf;
		}
		b[i + Aq.size()] = fabs(blq[i]);
	}
	for (int i = 0, nc = c.size(); i < nc; ++i) f[n + i] = c[i];
	auto x = simplexCore(f, A, b);
	return VD(x.begin() + n, x.begin() + n + c.size());
}


// 任意模数多项式乘法 O(n^{\log_2 3})
using VL = std::vector<LL>;
VL Karatsuba(VL a, VL b, LL p) {
	if (a.size() < b.size()) std::swap(a, b);
	auto mulS = [&](VL a, VL b) {
		int n = a.size(), m = b.size(), sz = n + m - 1;
		std::vector<__int128> c(sz);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				c[i + j] += a[i] * b[j];
			}
		}
		VL r(sz);
		for (int i = 0; i < sz; ++i) r[i] = c[i] % p;
		return r;
	};
	constexpr int N = 65;
	std::function<VL(VL, VL, int)> mul = [&](VL a, VL b, int n) -> VL {
		if (n < N) return mulS(a, b);
		int n2 = n / 2, n1 = n - 1;
		VL a2 = VL(a.begin() + n2, a.end());
		VL b2 = VL(b.begin() + n2, b.end());
		a.resize(n2); b.resize(n2);
		VL ap = a2, bp = b2;
		for (int i = 0; i < n2; ++i) if ((ap[i] += a[i]) >= p) ap[i] -= p;
		for (int i = 0; i < n2; ++i) if ((bp[i] += b[i]) >= p) bp[i] -= p;
		VL ab = mul(a, b, n2);
		VL a2b = mul(ap, bp, n2);
		VL a2b2 = mul(a2, b2, n2);
		for (int i = 0; i < n1; ++i) {
			if ((a2b[i] -= ab[i]) < 0) a2b[i] += p;
			if ((a2b[i] -= a2b2[i]) < 0) a2b[i] += p;
		}
		auto r = ab;
		r.emplace_back(0);
		r.insert(r.end(), a2b2.begin(), a2b2.end());
		for (int i = 0; i < n1; ++i) if ((r[i + n2] += a2b[i]) >= p) r[i + n2] -= p;
		return r;
	};
	int n = a.size(), m = b.size(), tot = std::max(1, n + m - 1);
	if (m < N || n / m * 2 > m) return mulS(a, b);
	int sz = 1 << std::__lg(tot * 2 - 1);
	while (sz < n) sz *= 2;
	a.resize(sz), b.resize(sz);
	auto r = mul(a, b, sz);
	r.resize(tot);
	return r;
} // 模板例题：https://www.luogu.com.cn/problem/P4245

// 任意模数多项式乘法 O(n^{\log_2 3}) 并行版（如果有无穷核心，那岂不是 $O(n \log n)$ 的）
using VL = std::vector<LL>;
VL KaratsubaParallel(VL a, VL b, LL p) {
	if (a.size() < b.size()) std::swap(a, b);
	auto mulS = [&](VL a, VL b) {
		int n = a.size(), m = b.size(), sz = n + m - 1;
		std::vector<__int128> c(sz);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				c[i + j] += a[i] * b[j];
			}
		}
		VL r(sz);
		for (int i = 0; i < sz; ++i) r[i] = c[i] % p;
		return r;
	};
	constexpr int N = 65;
	std::function<VL(VL, VL, int)> mul = [&](VL a, VL b, int n) -> VL {
		if (n < N) return mulS(a, b);
		int n2 = n / 2, n1 = n - 1;
		VL a2 = VL(a.begin() + n2, a.end());
		VL b2 = VL(b.begin() + n2, b.end());
		a.resize(n2); b.resize(n2);
		VL ap = a2, bp = b2;
		for (int i = 0; i < n2; ++i) if ((ap[i] += a[i]) >= p) ap[i] -= p;
		for (int i = 0; i < n2; ++i) if ((bp[i] += b[i]) >= p) bp[i] -= p;
		std::future<VL> abThread = std::async(mul, a, b, n2);
		VL a2b = mul(ap, bp, n2);
		VL ab = abThread.get();
		VL a2b2 = mul(a2, b2, n2);
		for (int i = 0; i < n1; ++i) {
			if ((a2b[i] -= ab[i]) < 0) a2b[i] += p;
			if ((a2b[i] -= a2b2[i]) < 0) a2b[i] += p;
		}
		auto r = ab;
		r.emplace_back(0);
		r.insert(r.end(), a2b2.begin(), a2b2.end());
		for (int i = 0; i < n1; ++i) if ((r[i + n2] += a2b[i]) >= p) r[i + n2] -= p;
		return r;
	};
	int n = a.size(), m = b.size(), tot = std::max(1, n + m - 1);
	if (m < N || n / m * 8 > m) return mulS(a, b);
	int sz = 1 << std::__lg(tot * 2 - 1);
	a.resize(sz), b.resize(sz);
	auto r = mul(a, b, sz);
	r.resize(tot);
	return r;
} // 模板例题：https://www.luogu.com.cn/problem/P4245，无法提交，CE。



// 二维区间型: f_{l, r} = \min_{l \leq k < r} f_{l, k} + f_{k + 1, r} + w(l, r) \qquad (1 \leq l < r \leq n)
template<typename T>
std::vector<std::vector<T>> quadrangleItvDp(std::vector<std::vector<T>> w, int n) {
	std::vector<std::vector<T>> f(n + 1, std::vector<T>(n + 1)), mf(n + 1, std::vector<T>(n + 1));
	for (int i = 1; i < n; ++i) {
		f[i][i + 1] = w[i][i + 1];
		mf[i][i + 1] = i;
	}
	auto const inf = std::numeric_limits<T>::max() / 2;
	for (int len = 2; len < n; ++len) {
		for (int l = 1, r = len + 1; r <= n; ++l, ++r) {
			f[l][r] = inf;
			for (int k = mf[l][r - 1]; k <= mf[l + 1][r]; ++k) {
				if (f[l][r] > f[l][k] + f[k + 1][r]) {
					f[l][r] = f[l][k] + f[k + 1][r];
					mf[l][r] = k;
				}
			}
			f[l][r] += w[l][r];
		}
	}
	return f;
}

// 二维滚动型: f_{i, j} = \min_{k < j} f_{i - 1, k} + w(k + 1, j) \quad (1 \leq i \leq n, 1 \leq j \leq m)
template<typename T>
std::vector<std::vector<T>> quadrangleRollDp(std::vector<std::vector<T>> w, int n, int m) {
// w 是 (n + 1, n + 1) 矩阵，答案是 (m + 1, n + 1) 矩阵
	std::vector<std::vector<T>> f(m + 1, std::vector<T>(n + 1)), mf(m + 1,  std::vector<T>(n + 2));
	auto const inf = std::numeric_limits<T>::max() / 2;
	for (int i = 1; i < n; ++i) f[0][i] = inf;
	for (int i = 1; i <= m; ++i) {
		mf[i][n + 1] = n;
		for (int j = n; j > 0; --j) {
			f[i][j] = inf;
			for (int k = std::max(i - 1, mf[i - 1][j]); k < j && k <= mf[i][j + 1]; ++k) {
				if (f[i][j] > f[i - 1][k] + w[k + 1][j]) {
					f[i][j] = f[i - 1][k] + w[k + 1][j];
					mf[i][j] = k;
				}
			}
		}
	}
	return f;
}
// https://www.luogu.com.cn/problem/P4767







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
	PolyMFTStrictly powModPoly(LL n, const PolyMFTStrictly &p) const {
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