#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
const int N = 1.1e5 + 2;
bool isp[N];
std::vector<int> p{0, 2};
void initPrime() {
	for (int i = 3; i < N; i += 2) isp[i] = true;
	int sq = int(std::sqrt(N + 0.1)) | 1;
	for (int i = 3; i <= sq; i += 2) if (isp[i]) {
		p.emplace_back(i);
		for (int j = i * i; j < N; j += i << 1) isp[j] = false;
	}
	for (int i = sq + 2; i < N; i += 2) if (isp[i]) p.emplace_back(i);
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	initPrime();
	int n, q;
	std::cin >> n >> q;
	std::vector<int> a(n);
	for (auto &x : a) std::cin >> x;
	std::vector<std::vector<int>> pp(N);
	for (int i = 1; i < p.size(); ++i) {
		for (int j = p[i]; j < N; j += p[i]) pp[j].emplace_back(p[i]);
	}
	std::vector<std::vector<int>> pa(n);
	for (int i = 0; i < n; ++i) pa[i] = pp[a[i]];
	std::vector<int> dp(n, n), last(N, n);
	for (auto x : pa[n - 1]) last[x] = n - 1;
	for (int i = n - 2; i >= 0; --i) {
		int mn = dp[i + 1];
		for (auto x : pa[i]) {
			mn = std::min(mn, last[x]);
			last[x] = i;
		}
		dp[i] = mn;
	}
	std::vector<std::vector<int>> ans(n);
	for (int i = 0; i < n; ++i) ans[i].emplace_back(dp[i]);
	for (int st = 1; st <= n; st *= 2) {
		for (int i = 0; i < n; ++i) if (ans[i].back() != n) {
			ans[i].emplace_back(ans[ans[i].back()].back());
		}
	}
	while (q--) {
		int l, r;
		std::cin >> l >> r;
		--l; --r;
		int res = 0;
		while (l <= r) {
			if (ans[l][0] > r) {
				++res;
				break;
			}
			int now = std::upper_bound(ans[l].begin(), ans[l].end(), r) - ans[l].begin() - 1;
			l = ans[l][now];
			res += 1 << now;
		}
		std::cout << res << '\n';
	}
	return 0;
}