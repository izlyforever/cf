#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 1e9 + 7;
LL powMod(LL x, LL n) {
	LL r = 1;
	while (n) {
		if (n & 1) r = r * x % M;
		n >>= 1;   x = x * x % M;
	}
	return r;
}
const int N = 3e5 + 2;
LL fac[N], ifac[N];
void init() {
	fac[0] = 1;
	for (int i = 1; i < N; ++i) fac[i] = fac[i - 1] * i % M;
	ifac[N - 1] = powMod(fac[N - 1], M - 2);
	for (int i = N - 1; i; --i) ifac[i - 1] = ifac[i] * i % M;
}
LL binom(int n, int k) {
	//if (n < k || n < 0) return 0;
	return fac[n] * ifac[k] % M * ifac[n - k] % M;
}

LL solve(int n, int a, int c) {
	LL r = 0;
	for (int i = 0; i <= n; ++i) {
		r += binom(n, i) * powMod(c, i + a) % M; 
	}
	return r % M;
}
int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	std::string s;
	int c;
	std::cin >> s >> c;
	if (c == 0) {
		std::cout << "1\n";
		return 0;
	}
	init();
	LL r = 0;
	int a = 0;
	for (int i = 0; i < s.size(); ++i) if (s[i] == '1') {
		r += solve(s.size() - i - 1, a++, c);
	}
	r += powMod(c, a);
	std::cout << r % M << std::endl;
	return 0;
}