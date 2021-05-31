#pragma once
#include <bits/stdc++.h>
#include "primary.hpp"
using LL = long long;

// 注意这里的 nthPrime 以 1 开始编号（其它地方以 0 开始）！即 p[1] = 2
namespace Prime {
// O(\sqrt{N}) 最基本的单次素数判断
bool isPrime(LL n) {
	if (n == 2) return true;
	if (n == 1 || n % 2 == 0) return false;
	for (LL i = 3; i * i <= n; i += 2){
		if (n % i == 0) return false;
	}
	return true;
}

// 预处理判断所有素数
constexpr int N = 1e7 + 2;
bool isp[N];
// 此算法复杂度为 O(N \log \log N)，实测 N < 1e9 时是最快的
std::vector<int> initPrime() {
	std::vector<int> p{0, 2};
	isp[2] = true;
	for (int i = 3; i < N; i += 2) isp[i] = true;
	int sq = int(std::sqrt(N + 0.1)) | 1;
	for (int i = 3; i <= sq; i += 2) if (isp[i]) {
		p.emplace_back(i);
		for (int j = i * i; j < N; j += i << 1) isp[j] = false;
	}
	for (int i = sq + 2; i < N; i += 2) if (isp[i]) p.emplace_back(i);
	return p;
}
// 此算法是 $O(N)$ 的，但实测不如上面算法快。
std::vector<int> initPrimeS() { // 放在此处仅供记录。
	std::vector<int> p{0, 2};
	isp[2] = true;
	for (int i = 3; i < N; i += 2) isp[i] = true;
	for (int i = 3; i < N; i += 2) {
		if (isp[i]) p.emplace_back(i);
		for (int j = 2, t = (N - 1) / i + 1, np = p.size(); j < np && p[j] < t; ++j) { // 用除号是防止溢出
			isp[i * p[j]] = false;
			// 不要下面的一步的话，复杂度 O(nloglogn), 但是不用除法，常数小
			if (i % p[j] == 0) break;
		}
	}
	return p;
}

// 计算 pi(x)，理论：https://dna049.com/computationOfPiX
// 这里预处理 N = 1e7, M = 7 是最好的（预处理 200ms）。
// 如果 x 特别大，例 1e13 < x < 1e15，建议 N = 1e8, M = 8（预处理耗时很大，2s）
constexpr int M = 7; // 请不要超过 8，M = 9 已经没有什么意义了。
int pi[N];
std::vector<int> p;
std::vector<std::vector<int>> phi(M + 1);
void init() {
	p = initPrime();
	pi[2] = 1;
	for (int i = 3; i < N; ++i) {
		pi[i] = pi[i - 1];
		if (isp[i]) ++pi[i];
	}
	std::vector<int> sz(M + 1, 1);
	for (int i = 1; i <= M; ++i) sz[i] = p[i] * sz[i - 1];
	phi[0] = {1}; // 注意这里 phi[0] 本质是无意义的
	// 对本质逻辑 phi[j][i] = phi[j][i - 1] - phi[j / p[i]][i - 1]; 的细节和空间优化
	for (int i = 1; i <= M; ++i) {
		phi[i].resize(sz[i]);
		for (int j = 0; j < p[i]; ++j) {
			for (int k = 0, jsz = j * sz[i - 1]; k < sz[i - 1]; ++k) {
				phi[i][jsz + k] = j * phi[i - 1].back() + phi[i - 1][k];
			}
		}
		for (int k = 0; k < sz[i - 1]; ++k) {
			for (int j = 0, kp = k * p[i]; j < p[i]; ++j) {
				phi[i][kp + j] -= phi[i - 1][k];
			}
		}
	}
}
LL primepi(LL x);
LL primephi(LL x, int s) {
	if (s <= M) return (x / phi[s].size()) * phi[s].back() + phi[s][x % phi[s].size()];
	if (x / p[s] <= p[s]) return primepi(x) - s + 1;
	if (x / p[s] / p[s] <= p[s] && x < N) {
		int s2x = pi[(int)(std::sqrt(x + 0.2))];
		LL ans = pi[x] - (s2x + s - 2) * (s2x - s + 1) / 2;
		for (int i = s + 1; i <= s2x; ++i) {
			ans += pi[x / p[i]];
		}
		return ans;
	}
	return primephi(x, s - 1) - primephi(x / p[s], s - 1);
}
LL primepi(LL x) {
	if (x < N) return pi[x];
	int ps2x = primepi(int(std::sqrt(x + 0.2)));
	int ps3x = primepi(int(std::cbrt(x + 0.2)));
	LL ans = primephi(x, ps3x) + 1LL * (ps2x + ps3x - 2) * (ps2x - ps3x + 1) / 2;
	for (int i = ps3x + 1, ed = ps2x; i <= ed; ++i) {
		ans -= primepi(x / p[i]);
	}
	return ans;
}

// 动态规划版 O(\frac{n}{\log n}) 计算 pi(x)，x < 10^12
LL primepiS(LL n) {
	int rn = std::sqrt(n + 0.2);
	std::vector<LL> R(rn + 1);
	for (int i = 1; i <= rn; ++i) R[i] = n / i - 1;
	int ln = n / (rn + 1) + 1;
	std::vector<LL> L(ln + 1);
	for (int i = 1; i <= ln; ++i) L[i] = i - 1;
	for (int p = 2; p <= rn; ++p) {
		if (L[p] == L[p - 1]) continue;
		for (int i = 1, tn = std::min(n / p / p, LL(rn)); i <= tn; ++i) {
			R[i] -= (i <= rn / p ? R[i * p] : L[n / i / p]) - L[p - 1];
		}
		for (int i = ln; i / p >= p; --i) {
			L[i] -= L[i / p] - L[p - 1];
		}
	}
	return R[1];
}

// 查看 (s - n, s] (请保证区间较小）内每个数是否为素数，确保 p.back() * p.back() >= r
std::vector<int> seive(LL s, int n) { // O(N log s)
	std::vector<int> isP(n, 1); // isP[i] = 1 表示 s - i 是素数
	for (int i = 1; 1LL * p[i] * p[i] <= s; ++i) {
		for (int j = s % p[i]; j < n; j += p[i]) isP[j] = 0;
	}
	return isP;
}

// 使用前先初始化，返回第 n 个素数，从 1 开始标号
LL nthPrime(LL n) { // Newton 梯度法
	if (n < (int)p.size()) return p[n];
	LL ans = n * log(n), err = log(n) / log(10);
	LL m = primepi(ans);
	while (m < n || m > n + err) {
		ans += (n - m) / (log(m) - 1) * log(m) * log(m);
		m = primepi(ans);
	}
	int sn = std::sqrt(N);
	while (1) {
		auto isP = seive(ans, sn);
		for (int i = 0; i < sn; ++i) if (isP[i]) {
			if (m-- == n) return ans - i;
		}
		ans -= sn;
	}
} // 原理：https://dna049.com/nthPrimeNumber/

} // namespace Prime

// 单次求 Euler 函数
LL getPhi(LL n) {
	if (n % 2 == 0) n /= 2;
	LL r = n;
	while (n % 2 == 0) n /= 2;
	for (LL i = 3; i * i <= n; i += 2) {
		if (n % i  == 0) {
			r = r / i * (i - 1);
			while (n % i == 0) n /= i;
		}
	}
	if (n > 1) r = r / n * (n - 1);
	return r;
}

// O(N \log \log N) 预处理 Euler 函数（不推荐）
std::vector<int> initPhiS(int N) {
	std::vector<int> phi(N);
	for (int i = 1; i < N; i += 2) phi[i] = i;
	for (int i = 2; i < N; i += 2) phi[i] = i >> 1;
	for (int i = 3; i < N; i += 2) {
		if (phi[i] != i) continue;
		for (int j = i; j < N; j += i) phi[j] = phi[j] / i * (i - 1);
	}
	return phi;
}

// 函数 O(N) 预处理 Euler 函数
std::vector<int> initPhi(int N) {
	std::vector<int> phi(N), p{0, 2};
	for (int i = 1; i < N; i += 2) phi[i] = i;
	for (int i = 2; i < N; i += 2) phi[i] = i >> 1;
	for (int i = 3; i < N; i += 2) {
		if (phi[i] == i) p.emplace_back(i), --phi[i];
		for (int j = 2, t = (N - 1) / i + 1, np = p.size(); j < np && p[j] < t; ++j) {
			if (i % p[j] == 0) {
				phi[i * p[j]] = phi[i] * p[j];
				break;
			}
			phi[i * p[j]] = phi[i] * (p[j] - 1);
		}
	}
	for (int i = 2; i < N; i += 4) phi[i] = phi[i >> 1];
	for (int i = 4; i < N; i += 4) phi[i] = phi[i >> 1] << 1;
	return phi;
}

// 单次求 Mobius 函数（完全类似于单次欧拉函数）。
int getMu(LL n){
	if (n % 4 == 0) return 0;
	int r = (n % 2 ? 1 : -1);
	if (n % 2 == 0) n /= 2;
	for (LL i = 3; i * i <= n; i += 2){
		if (n % i == 0) {
			n /= i;
			if (n % i == 0) return 0;
			r = -r;
		}
	}
	return n > 1 ? -r : r;
}

//  O(n log n) 预处理 Mobius 函数
std::vector<int> initMuS(int N) {
	std::vector<int> mu(N);
	mu[1] = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = i * 2; j < N; j += i) {
			mu[j] -= mu[i];
		}
	}
	return mu;
}

// O(n) 预处理版本 Mobius 函数 
std::vector<int> initMu(int N) {
	std::vector<int> mu(N), p{0, 2};
	for (int i = 1; i < N; i += 2) mu[i] = i;
	for (int i = 3; i < N; i += 2) {
		if (mu[i] == i) mu[i] = -1, p.emplace_back(i);
		for (int j = 2, t = (N - 1) / i + 1, np = p.size(); j < np && p[j] < t; ++j) {
			if (i % p[j] == 0) {
				mu[i * p[j]] = 0;
				break;
			}
			mu[i * p[j]] = -mu[i];
		}
	}
	for (int i = 2; i < N; i += 4) mu[i] = -mu[i >> 1];
	return mu;
}

// min_25 筛法 O(n^{\frac{2}{3}}) 求 Euler 函数前缀和 以及 Mobius 函数（绝对值）前缀和
namespace min_25 { //  请勿使用二维记忆化搜索的 map
constexpr int N = 5e6 + 2;

// Euler 函数前缀和
std::vector<LL> sumPhi(N);
std::unordered_map<LL, LL> mpPhi; // 可选 unordered_map 是因为这些都是确定的数不会被 hack
void initSumPhi() {
	auto phi = initPhi(N);
	for (int i = 1; i < N; ++i) sumPhi[i] = sumPhi[i - 1] + phi[i];
}
LL getSumPhi(LL n) {
	if (n < N) return sumPhi[n];
	if (mpPhi.count(n)) return mpPhi[n];
	LL r = (n + 1) * n / 2;
	for (LL i = 2, j; i <= n; i = j + 1) {
		j = n / (n / i);
		r -= (j - i + 1) * getSumPhi(n / i);
	}
	return mpPhi[n] = r;
}

// Mobius 函数（绝对值）前缀和
std::vector<int> mu(N), sumMu(N);
std::unordered_map<LL, int> mpMu; // 可选 unordered_map 是因为这些都是确定的数不会被 hack
void initSumMu() {
	mu = initMu(N);
	for (int i = 1; i < N; ++i) sumMu[i] = sumMu[i - 1] + mu[i];
}
// 当答案超过 int 时，n 已经大到没法计算了，因此可认为返回值为 int。
int getSumMu(LL n) {
	if (n < N) return sumMu[n];
	if (mpMu.count(n)) return mpMu[n];
	LL r = 1;
	for (LL i = 2, j; i <= n; i = j + 1) {
		j = n / (n / i);
		r -= (j - i + 1) * getSumMu(n / i);	
	}
	return mpMu[n] = r;
}
//  Mobius 函数绝对值前缀和
LL getAbsSum(LL n) { // Q(n) = Q(n-1) + |mu(n)|
	LL r = 0;
	for (LL i = 1; i * i < n; ++i) {
		r += mu[i] * (n / i / i);
	}
	return r;
}
} // namespace min_25
// 模板例题：https://www.luogu.com.cn/problem/P4213

// O(N) 预处理所有数的最小素因子
std::vector<int> spf(int N) {
	std::vector<int> sp(N), p{0, 2};
	for (int i = 2; i < N; i += 2) sp[i] = 2;
	for (int i = 1; i < N; i += 2) sp[i] = i;
	for (int i = 3; i < N; i += 2) {
		if (sp[i] == i) p.emplace_back(i);
		for (int j = 2, np = p.size(); j < np && p[j] <= sp[i] && i * p[j] < N; ++j) {
			sp[i * p[j]] = p[j]; // 注意到sp只被赋值一次
		}
	}
	return sp;
}

// O(N) 预处理所有数的(是否算重)素因子个数
std::pair<std::vector<int>, std::vector<int>> npf(int N) {
	std::vector<int> np(N, 1), nps(N, 1), p{0, 2};
	nps[0] = nps[1] = 0;
	np[0] = np[1] = 0;
	for (int i = 3; i < N; i += 2) {
		if (nps[i] == 1) p.emplace_back(i);
		for (int j = 2, t, pSize = p.size(); j < pSize && (t = i * p[j]) < N; ++j) {
			nps[t] = nps[i] + 1;
			np[t] = np[i];
			if (i % p[j] == 0) break;
			++np[t];
		}
	}
	for (int i = 2; i < N; i += 4) np[i] = np[i >> 1] + 1;
	for (int i = 4; i < N; i += 4) np[i] = np[i >> 1];
	for (int i = 2; i < N; i += 2) nps[i] = nps[i >> 1] + 1;
	return {np, nps};
}

// 获取全部不同素因子
std::vector<int> factor(int n, const std::vector<int> &sp) {
	std::vector<int> ans;
	while (n > 1) {
		int pn = sp[n];
		ans.emplace_back(pn);
		while (n % pn == 0) n /= pn;
	}
	return ans;
}
// 获取全部素因子
std::vector<std::pair<int, int>> Factor(int n, const std::vector<int> &sp) {
	std::vector<std::pair<int, int>> ans;
	while (n > 1) {
		int pn = sp[n], cnt = 0;
		while (n % pn == 0) n /= pn, ++cnt;
		ans.emplace_back(pn, cnt);
	}
	return ans;
}

// 返回最小原根，无的话返回 0
int primitiveRoot(int n, const std::vector<int> &sp) {
	if (n < 2) return 0;
	if (n == 2 || n == 4) return n - 1;
	if (n % 4 == 0) return 0;
	int n2 = n % 2 == 0 ? n / 2 : n;
	int pn = sp[n2];
	while (n2 % pn == 0) n2 /= pn;
	if (n2 != 1) return 0;
	auto fp = factor(pn - 1, sp);
	auto check = [&](int i) {
		for (auto x : fp) {
			if (powMod(i, (pn - 1) / x, pn) == 1) return false;
		}
		return true;
	};
	int ans = 2;
	while (!check(ans)) ++ans;
	n2 = n % 2 == 0 ? n / 2 : n;
	if (n2 != pn) {
		int m = n2 / pn * (pn - 1);
		auto fm = factor(m, sp);
		for (auto x : fp) {
			if (powMod(ans, m / x, m) == 1) {
				ans += pn;
				break;
			}
		}
	}
	if (n2 != n && (ans % 2 == 0)) ans += n2;
	return ans;
}
// 返回所有原根，若无返回空
std::vector<int> primitiveRootAllS(int n, const std::vector<int> &sp) {
	int g = primitiveRoot(n, sp);
	if (g == 0) return {};
	if (n == 2 || n == 4) return {n - 1};
	int n2 = n & 1 ? n : n / 2;
	int pn = sp[n2], m = n2 / pn * (pn - 1), now = g;
	std::vector<int> ans{g};
	for (int i = 2; i < m; ++i) {
		now = 1LL * now * g % n;
		if (std::gcd(i, m) == 1) ans.emplace_back(now);
	}
	std::sort(ans.begin(), ans.end());
	return ans;
}

// 返回所有原根，若无返回空
std::vector<int> primitiveRootAll(int n, const std::vector<int> &sp) {
	if (n < 2) return {};
	if (n == 2 || n == 4) return {n - 1};
	if (n % 4 == 0) return {};
	int n2 = n % 2 == 0 ? n / 2 : n, pn = sp[n2];
	while (n2 % pn == 0) n2 /= pn;
	if (n2 != 1) return {};
	int m = (n & 1 ? n : n / 2) / pn * (pn - 1);
	std::vector<int> vis(n, -1), ans;
	for (int i = 2; i < n; ++i) if (vis[i] == -1 && std::gcd(i, n) == 1) {
		bool flag = true;
		int now = 1;
		for (int j = 1; j < m; ++j) {
			now = 1LL * now * i % n;
			if (now == 1) {
				flag = false;
				break;
			}
			if (std::gcd(j, m) == 1) vis[now] = i;
			else vis[now] = 0;
		}
		if (flag) { // 此时 i 必然是最小原根
			for (int j = 0; j < n; ++j) if (vis[j] == i) {
				ans.emplace_back(j);
			}
			return ans;
		}
	}
	return {};
} // 模板例题：https://www.luogu.com.cn/problem/P6091

// 大素数 Miller-Rabin 概率判别法 和 大整数的最 大/小 因子分解
namespace PollardRho {
std::mt19937_64 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
LL powModll(LL x, LL n, LL p) {
	LL r = 1;
	while (n) {
		if (n&1) r = __int128(r) * x % p;
		n >>= 1; x = __int128(x) * x % p;
	}
	return r;
}
// 1 < a < n，若 n 是素数，那么 a^(n - 1) = 1 mod n
// m - 1 = m * 2 ^ t，返回 false 表示判断失败
bool witness(LL a, LL n, LL m, int t) {
	LL x = powModll(a, m, n);
	if (x == 1 || x == n - 1) return false;
	while (t--) {
		x = __int128(x) * x %  n;
		if (x == n - 1) return false;
	}
	return true;
}
constexpr int TIMES = 52;
bool rabin(LL n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	LL m = n - 1;
	int t = __builtin_ctzll(m);
	m >>= t;
	for (int cnt = 0; cnt < TIMES; ++cnt) {
		LL a = rnd() % (n - 1) + 1;
		if (witness(a, n, m, t)) return false;
	}
	return true;
}
LL pollardrho(LL n) {
	LL x = 0, y = 0, z = 1, i = 1, k = 2, c = rnd() % (n - 1) + 1;
	while (true) {
		x = (__int128(x) * x + c) % n;
		z = __int128(y - x + n) * z % n;
		// 累计 gcd 一次计算！太猛了啊 茶茶白
		if (++i == k) {
			LL d = std::__gcd(z, n);
			if (d > 1) return d;
			y = x;
			if (k > n) return n;
			k <<= 1;
		}
	}
}
LL spf(LL n) {
	if (rabin(n) || n == 1) return n;
	LL d = n;
	while (d == n) d = pollardrho(n);
	return std::min(spf(d), spf(n / d));
}
LL gpf(LL n, LL mxf = 1) {
	if (rabin(n)) return n;
	if (n <= mxf) return 1;
	LL d = n;
	while (d == n) d = pollardrho(n);
	LL res = gpf(d, mxf);
	return std::max(res, gpf(n / d, std::max(res, mxf)));
}
} // namespace PollardRho

// 离散对数：返回最小的 x 使得 a^x = b mod p，p 为素数，无解输出 -1。
int babyStepGiantStep(int a, int b, int p) {
	a %= p, b %= p;
	if (a == 0) return b % p ? -1 : 1;
	if (b == 1) return 0;
	int cnt = 0, t = 1;
	for (int g = std::gcd(a, p); g != 1; g = std::gcd(a, p)) {
		if (b % g) return -1;
		p /= g, b /= g, t = 1LL * t * (a / g) % p;
		++cnt;
		if (b == t) return cnt;
	}
	std::map<int, int> mp;
	int m = std::sqrt(p + 0.1) + 1;
	int base = b;
	for (int i = 0; i != m; ++i) {
		mp[base] = i;
		base = 1LL * base * a % p;
	}
	base = powMod(a, m, p);
	for (int i = 1; i <= m + 1; ++i) {
		t = 1ll * t * base % p;
		if (mp.count(t)) return (1LL * i * m - mp[t] + cnt) % p;
	}
	return -1;
}
// 模板例题：https://www.luogu.com.cn/problem/P3846

// 模开方：返回 x 使得 x^2 = a mod p, 无解输出 -1。复杂度 $O(\log^2 p)$
int sqrtModp(int a, int p) { // p 为素数，0 <= a < p < INT_MAX。
	if (a == 0 || p == 2) return a;
	auto pow = [p](int x, int n) {
		int r = 1;
		while (n) {
			if (n&1) r = 1LL * r * x % p;
			n >>= 1; x = 1LL * x * x % p;
		}
		return r;
	};
	int q = (p - 1) / 2;
	if (pow(a, q) != 1) return -1;
	if (q & 1) return pow(a, (q + 1) / 2);
	int b; // 寻找一个非二次剩余
	std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
	while (pow(b = rnd() % (p - 1) + 1, q) == 1);
	int c = __builtin_ctzll(q);
	q >>= c; // p - 1 = q << (c + 1)
	b = pow(b, q);
	int x = pow(a, (q + 1) / 2), t = pow(a, q);
	// 始终保持 x^2 = a t, t^{2^c} = 1, b^{2^c} = -1
	while (t != 1) {
		// 返回最小的 r 使得 u^{2^r} = -1 
		int cc = [p](int u) {
			int r = 0;
			while ((u = 1LL * u * u % p) != 1) ++r;
			return r;
		}(t);
		int d = pow(b, 1LL << (c - cc - 1)); // d^{2^{cc + 1}} = -1
		// (xd)^2 = a t d^2, (t d^2)^{2^{cc}} = 1, (d^2)^{2^cc} = -1
		x = 1LL * x * d % p;
		b = 1LL * d * d % p;
		t = 1LL * t * b % p;
		c = cc;
	}
	return x;
}
// 模板例题：https://www.luogu.com.cn/problem/P5491