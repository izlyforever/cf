#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// 为了代码简洁，树的编号以 1 开始。
std::vector<int> dsuOnTree(std::vector<std::vector<int>>& e, int rt = 1) {
  int n = e.size();
  // 预处理出重儿子
  std::vector<int> sz(n), son(n);
  std::function<void(int, int)> pdfs = [&](int u, int fa) -> void {
    for (auto v : e[u]) if (v != fa) {
      pdfs(v, u);
      if (sz[v] > sz[son[u]]) son[u] = v;
    }
    sz[u] = sz[son[u]] + 1;
  };
  std::vector<int> ans(n);
  std::function<std::vector<int>(int, int)> dfs = [&](int u, int fa) -> std::vector<int> {
    if (son[u] == 0) {
      ans[u] = 0;
      return {1};
    }
    auto a = dfs(son[u], u);
    ans[u] = ans[son[u]];
    for (auto v : e[u]) if (v != fa && v != son[u]) {
      auto tmp = dfs(v, u);
      // 这里需要对齐
      for (int ai = a.size() - 1, ti = tmp.size() - 1; ti >= 0; --ti, --ai) {
        a[ai] += tmp[ti];
        if (a[ai] > a[ans[u]] || (a[ai] == a[ans[u]] && ai > ans[u])) {
          ans[u] = ai;
        }
      }
    }
    a.emplace_back(1);
    if (a[ans[u]] == 1) ans[u] = sz[u] - 1;
    return a;
  };
  pdfs(rt, 0);
  dfs(rt, 0);
  for (int i = 1; i < n; ++i) ans[i] = sz[i] - 1 - ans[i];
  return ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> e(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  auto r = dsuOnTree(e);
  for (int i = 1; i <= n; ++i) std::cout << r[i] << "\n";
  return 0;
}