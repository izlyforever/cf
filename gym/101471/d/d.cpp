#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
	// freopen("C:\\Users\\dna049\\cf\\in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> a(n), b(m);
	for (auto &[x, y] : a) std::cin >> x >> y;
	for (auto &[x, y] : b) std::cin >> x >> y;
	std::sort(a.begin(), a.end());
	int cnt = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i].second < a[cnt - 1].second) a[cnt++] = a[i];
	}
	a.resize(cnt);
	std::sort(b.begin(), b.end());
	cnt = 1;
	for (int i = 1; i < m; ++i) {
		while (cnt > 0 && b[i].second >= b[cnt - 1].second) --cnt;
		b[cnt++] = b[i];
	}
	b.resize(cnt);
	// 确保了始终能找到最优策略
	b.insert(b.begin(), {0, INT_MAX});
	LL ans = 0;
	std::function<void(int, int, int, int)> divideConquer = [&](int l, int r, int opl, int opr) {
		// 区间都是左闭右开的
		if (l >= r) return;
		int mid = (l + r) / 2;
		LL rm = INT64_MIN;
		int k = -1;
		// 一开始必然满足 b[opl].second > a[mid].second，因此 k 必然满足
		for (int i = opl; i < opr && b[i].second > a[mid].second; ++i) {
			LL tmp = LL(b[i].second - a[mid].second) * (b[i].first - a[mid].first);
			if (tmp > rm) {
				rm = tmp;
				k = i;
			}
		}
		ans = std::max(ans, rm);
		divideConquer(l, mid, opl, k + 1);
		// b[k].second > a[mid].second > ... > a[r - 1].second，从而没有 k = -1 出现的可能
		divideConquer(mid + 1, r, k, opr);
	};
	divideConquer(0, a.size(), 0, b.size());
	std::cout << ans << "\n";
	return 0;
}