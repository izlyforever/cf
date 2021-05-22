#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const int N = 1e5;
bool isp[N];
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

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	auto p = initPrime();
	auto f = [&](int n) {
		int ans = 0;
		for (int i = 1; p[i] * p[i] <= n; ++i) if (n % p[i] == 0) {
			++ans;
			while (n % p[i] == 0) n /= p[i];
		}
		return ans + (n > 1);
	};
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n;
		std::cin >> n;
		std::cout << f(n) + f(n + 1) << '\n';
	}
	return 0;
}