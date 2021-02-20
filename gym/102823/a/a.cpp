#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

std::vector<std::pair<int, int>> f(std::vector<LL> &a, std::vector<LL> &s) {
	// 从小到大一层一层的 push 数字只会越来越大! 大致懂了
	int n = a.size();
	std::stack<int> Q;
	Q.push(0);
	for (int i = 1; i < n; ++i) {
		if (s[i] - s[Q.top()] <= a[i] * (i - Q.top())) {
			int t = Q.top();
			Q.pop();
			while (!Q.empty() && (s[t] - s[Q.top()]) * (i + 1 - t) <= (s[i + 1] - s[t]) * (t - Q.top())) {
				t = Q.top();
				Q.pop();
			}
			Q.push(t); 
		} else Q.push(i);
	}
	std::vector<std::pair<int, int>> r;
	int now = n;
	while (!Q.empty()) {
		r.emplace_back(Q.top(), now);
		now = Q.top();
		Q.pop();
	}
	return r;
}

LL solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<LL> a(n), b(m);
	for (auto &x : a) std::cin >> x;
	for (auto &x : b) std::cin >> x;
	std::vector<LL> sa(n + 1), sb(m + 1);
	for (int i = 0; i < n; ++i) sa[i + 1] = sa[i] + a[i];
	for (int i = 0; i < m; ++i) sb[i + 1] = sb[i] + b[i];
	auto fa = f(a, sa), fb = f(b, sb);
	std::vector<LL> c;
	while (!fa.empty() && !fb.empty()) {
		auto [la, ra] = fa.back();
		auto [lb, rb] = fb.back();
		if ((sa[ra] - sa[la]) * (rb - lb) >= (sb[rb] - sb[lb]) * (ra - la)) {
			fa.pop_back();
			for (int i = la; i < ra; ++i) c.emplace_back(a[i]);
		} else {
			fb.pop_back();
			for (int i = lb; i < rb; ++i) c.emplace_back(b[i]);
		}
	}
	if (fa.empty()) {
		for (int i = fb.back().first; i < m; ++i) c.emplace_back(b[i]);
	} else {
		for (int i = fa.back().first; i < n; ++i) c.emplace_back(a[i]);
	}
	LL ans = 0;
	for (int i = 0; i < n + m; ++i) ans += c[i] * (i + 1);
	return ans;
}

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int cas = 1;
	std::cin >> cas;
	for (int T = 1; T <= cas; ++T) {
		std::cout << "Case " << T << ": " << solve() << "\n";
	}
	return 0;
}