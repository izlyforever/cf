#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// O(N) 预处理所有数的最小素因子
std::vector<int> spf(int N) {
	std::vector<int> sp(N), p{0, 2};
	for (int i = 2; i < N; i += 2) sp[i] = 2;
	for (int i = 1; i < N; i += 2) sp[i] = i;
	for (int i = 3; i < N; i += 2) {
		if (sp[i] == i) p.emplace_back(i);
		for (int j = 2; j < p.size() && p[j] <= sp[i] && i * p[j] < N; ++j) {
			sp[i * p[j]] = p[j]; // 注意到sp只被赋值一次
		}
	}
	return sp;
}
// 返回最小原根，无的话返回 0
int primitiveRoot(int n, const std::vector<int> &sp) {
	if (n < 2) return 0;
	if (n == 2 || n == 4) return n - 1;
	if (n % 4 == 0) return 0;
	int n2 = n % 2 == 0 ? n / 2 : n;
	int pn = sp[n2];
	while (n2 % pn == 0) n2 /= pn;

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
		LL now = 1;
		for (int j = 1; j < m; ++j) {
			now = now * i % n;
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
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	auto sp = spf(1e6 + 2);
	int cas = 1;
	std::cin >> cas;
	while (cas--) {
		int n, d;
		std::cin >> n >> d;
		auto ans = primitiveRootAll(n, sp);
		// debug(ans);
		std::cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); ++i) if ((i + 1) % d == 0) {
			std::cout << ans[i] << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}