#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,abm,mmx,avx,avx2,popcnt,tune=native")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<std::pair<LL, int>, null_type, std::less<>, rb_tree_tag, tree_order_statistics_node_update>

#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
using LL = long long;
#include "include/izlyforever.hpp"

template<typename T>
void debug(std::vector<T> a){
	for (auto &i : a) std::cout << i << ' ';
	std::cout << std::endl; 
}

int main() {
	//freopen("in", "r", stdin);
	//freopen("out", "w", stdout);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	// 概率问题永不 TLE 的技巧
	auto begin = std::chrono::steady_clock::now();
	while ((std::chrono::steady_clock::now() - begin).count() < 5e8) {
		// do something
	}
	auto start = std::clock();
	
	std::clog << "Time used: " << (std::clock() - start) << "ms" << std::endl;
	return 0;
}

// ## 准备

// - 闹钟
// - 草稿纸 和 SageMath
// - 创建比赛文件夹和 md 文件（记录当前场次可能的 hack 点，以及题解）
// - cd path（根据题号提前写好）
// - cf race ***
// - cf test and cf submit
// - ./*.exe
// 通用 hack 点：答案超了 long long，用 ceil 向上取整。注意有些狗喜欢 `#define int long long`）