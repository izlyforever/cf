#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// 求字典序最小的 Euler 路，没有的话输出 空（允许重边）
// std::stack<int> EulerPathS(std::vector<std::multiset<int>> e) {
std::stack<int> EulerPathS(std::vector<std::set<int>> e) {
	int cnt = std::count_if(e.begin(), e.end(), [](auto x) {
		return x.size() % 2 == 1;
	});
	if (cnt > 2) return std::stack<int>();
	std::stack<int> ans;
	std::function<void(int)> Hierholzer = [&](int u) {
		while (!e[u].empty()) {
			int v = *e[u].begin();
			e[u].erase(e[u].begin());
			e[v].erase(e[v].find(u));
			Hierholzer(v);
		}
		ans.push(u);
	};
	for (int i = 0; i < e.size(); ++i) {
		if (!e[i].empty() && ((e[i].size() & 1) || (cnt == 0))) {
			Hierholzer(i);
			break;
		}
	}
	return ans;
}

// 求 rt 开头的字典序 Euler 路（保证存在且不允许重边）
std::stack<int> EulerPath(std::vector<std::set<int>> e, int rt) {
	std::stack<int> ans;
	std::function<void(int)> Hierholzer = [&](int u) {
		while (!e[u].empty()) {
			int v = *e[u].begin();
			e[u].erase(e[u].begin());
			e[v].erase(e[v].find(u));
			Hierholzer(v);
		}
		ans.push(u);
	};
	Hierholzer(rt);
	return ans;
}

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::set<int>> e(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v;
		std::cin >> u >> v;
		e[u].insert(v);
		e[v].insert(u);
	}
	std::set<int> odd;
	for (int i = 0; i < e.size(); ++i) if (e[i].size() & 1) {
		odd.insert(i);
	}
	if (odd.size() <= 2) {
		auto r = EulerPathS(e);
		std::cout << r.size() << "\n";
		while (!r.empty()) {
			std::cout << r.top() << " ";
			r.pop();
		}
		return 0;
	}
	for (int u = 1; u <= n; ++u) {
		auto oddu = odd;
		oddu.erase(u);
		std::vector<int> uv;
		for (auto v : e[u]) if (e[v].size() & 1) {
			oddu.erase(v);
			uv.emplace_back(v);
		}
		if (oddu.size() > 1) continue;
		int rt = u;
		if (oddu.empty()) {
			int t = -1;
			for (auto v : uv) if (e[v].size() > 1) {
				t = v;
				break;
			}
			if (t != -1) {
				oddu.insert(t);
				uv.erase(std::find(uv.begin(), uv.end(), t));
			}
		}
		for (auto v : uv) {
			e[u].erase(v);
			e[v].erase(u);
		}
		if (oddu.size() == 1) rt = *oddu.begin();
		auto r = EulerPath(e, rt);
		if (r.size() + uv.size() != m + 1) {
			for (auto v : uv) {
				e[u].insert(v);
				e[v].insert(u);
			}
			continue;
		}
		std::cout << r.size() + 1 + 2 * uv.size() << "\n";
		while (!r.empty()) {
			std::cout << r.top() << " ";
			r.pop();
		}
		std::cout << "-1 ";
		for (auto v : uv) std::cout << v << " " << u << " ";
		return 0;
	}
	std::cout << "0\n";
	return 0;
}