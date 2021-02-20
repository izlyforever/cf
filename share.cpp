#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// 请确保最后一个元素为 0，且 a 中其它元素都是正整数，且最大值较小。
std::vector<int> SAIS(std::vector<int> a) {
	enum TYPE {L, S};
	int n = a.size() - 1, mx = *std::max_element(a.begin(), a.end()) + 1;
	std::vector<int> SA(n + 1, -1);
	std::vector<int> bucket(mx), lbucket(mx), sbucket(mx);
	for (auto x : a) ++bucket[x];
	for (int i = 1; i < mx; ++i) {
		bucket[i] += bucket[i - 1];
		lbucket[i] = bucket[i - 1];
		sbucket[i] = bucket[i] - 1;
	}
	// 确定 L, S 类型以及 * 型的位置
	std::vector<TYPE> type(n + 1);
	type[n] = S;
	for (int i = n - 1; i >= 0; --i) {
		type[i] = (a[i] < a[i + 1] ? S : (a[i] > a[i + 1] ? L : type[i + 1]));
	}
	// 诱导排序(从 * 型诱导到 L 型、从 L 型诱导到 S 型)
	auto inducedSort = [&]() {
		for (int i = 0; i <= n; ++i) {
			if (SA[i] > 0 && type[SA[i] - 1] == L) {
				SA[lbucket[a[SA[i] - 1]]++] = SA[i] - 1;
			}
		}
		for (int i = 1; i < mx; ++i) {
			sbucket[i] = bucket[i] - 1;
		}
		for (int i = n; i >= 0; --i) {
			if (SA[i] > 0 && type[SA[i] - 1] == S) {
				SA[sbucket[a[SA[i] - 1]]--] = SA[i] - 1;
			}
		}
	};
	// 首先根据诱导排序给出 LMS-prefix 的排序
	std::vector<int> pos;
	for (int i = 1; i <= n; ++i) {
		if (type[i] == S && type[i - 1] == L) {
			pos.emplace_back(i);
		}
	}
	for (auto x : pos) SA[sbucket[a[x]]--] = x;
	inducedSort();
	// 根据 LMS-prefix 的排序给出 LMS-substring 的命名，即得到 S1
	auto isLMSchar = [&](int i) {
		return i > 0 && type[i] == S && type[i - 1] == L;
	};
	auto equalSubstring = [&](int x, int y) {
		do {
			if (a[x] != a[y]) return false;
			++x; ++y;
		} while (!isLMSchar(x) && !isLMSchar(y));
		return a[x] == a[y];
	};
	// 注意到因为 LMS-prefix 排序会导致仅有相邻的 LMS-substring 才可能相等
	std::vector<int> name(n + 1, -1);
	int lx = -1, cnt = 0;
	bool flag = true; // 表示无相同的 LMS-substring
	for (auto x : SA) if (isLMSchar(x)) {
		if (lx >= 0 && !equalSubstring(lx, x)) ++cnt;
		if (lx >= 0 && cnt == name[lx]) flag = false;
		name[x] = cnt;
		lx = x;
	}
	std::vector<int> S1;
	for (auto x : name) if (x != -1) S1.emplace_back(x);
	auto getSA1 = [&]() {
		int n1 = S1.size();
		std::vector<int> SA1(n1);
		for (int i = 0; i < n1; ++i) SA1[S1[i]] = i;
		return SA1;
	};
	auto SA1 = flag ? getSA1() : SAIS(S1);
	// 再次诱导排序，根据 S1 的排序得到 SA
	lbucket[0] = sbucket[0] = 0;
	for (int i = 1; i < mx; ++i) {
		lbucket[i] = bucket[i - 1];
		sbucket[i] = bucket[i] - 1;
	}
	std::fill(SA.begin(), SA.end(), -1);
	// 这里是逆序扫描 SA1，因为 SA 中 S 型桶是倒序的
	for (int i = SA1.size() - 1; i >= 0; --i) {
		SA[sbucket[a[pos[SA1[i]]]]--] = pos[SA1[i]];
	}
	inducedSort();
	return SA;
}

std::vector<int> SAIS(const std::string &s) {
	// s 的字符集为小写字，则可使用下面函数。
	auto f = [](char x) -> int { return int(x - 'a') + 1;};
	std::vector<int> a;
	for (auto c : s) a.emplace_back(f(c));
	a.emplace_back(0);
	auto sa = SAIS(a);
	return std::vector<int>(sa.begin() + 1, sa.end());
}

int main() {
	//freopen("in", "r", stdin);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::string s;
	std::cin >> s;
	int n = s.size();
	auto sa = SAIS(s);
	std::vector<int> rk(n);
	for (int i = 0; i < n; ++i) rk[sa[i]] = i;
	// 可能从 1 开始编号会方便点，但是我不喜欢。
	std::vector<int> ht(n);
	for (int i = 0, k = 0; i < n; ++i) {
		if (k) --k;
		if (rk[i] == 0) k = 0;
		else {
			while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
			ht[rk[i]] = k;
		}
	}
	std::vector<LL> dcnt(n);
	for (int i = 0; i < n; ++i) dcnt[i] = (n - sa[i]);
	for (int i = 1; i < n; ++i) dcnt[i] += dcnt[i - 1] - ht[i];
	auto dsolve = [&](int k) -> std::string {
		int it = std::lower_bound(dcnt.begin(), dcnt.end(), k) - dcnt.begin();
		if (it == n) return "-1";
		int l = sa[it], r = sa[it] + ht[it] + (k - (it > 0 ? dcnt[it - 1] : 0));
		return s.substr(l, r);
	};
	auto solve = [&](int k)  -> std::string {
		if (k > LL(n + 1) * n / 2) return "-1";
		
	};
	int t, k;
	std::cin >> t >> k;
	std::cout << (t == 0 ? dsolve(k) : solve(k)) << std::endl;
	return 0;
}