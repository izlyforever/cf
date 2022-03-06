#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;
// #include "include/izlyforever.hpp"

// a 单调递增，且最大值小于 mx。a 变成下一个字典序大于自身的序列
bool next(std::vector<int>& a, int mx) {
  int n = a.size(), i = 1;
  while (i <= n && a[n - i] == mx - i) ++i;
  if (i > n) return false;
  ++a[n - i];
  for (int j = 1; j < i; ++j) {
    a[n - j] = a[n - i] + (i - j);
  }
  return true;
}

class ECC {
  std::vector<std::vector<int>> a; // 原始数据 n 个 m 维向量
  int k; // 容许的最大不同个数
  std::vector<std::vector<int>> bad; // 与 r 不同的个数
  int n, m, mxId;
  void updateMxId(int i) { if (bad[i].size() > bad[mxId].size()) mxId = i;}
  bool dfs(int c) { // 当前 r 剩余可改变的次数
    auto bd = bad[mxId];
    if (bd.size() <= k) return true;
    if (bd.size() - k > c) return false;
    // 注意到此时 bd 是 O(k) 的而不是 O(m) 的
    std::vector<int> f(bd.size() - k);
    iota(f.begin(), f.end(), 0);
    int tMxId = mxId;
    do {
      mxId = tMxId;
      std::queue<int> tmp;
      for (auto x : f) {
        tmp.push(r[bd[x]]);
        for (int i = 0; i < n; ++i) {
          if (a[i][bd[x]] == r[bd[x]]) {
            bad[i].emplace_back(bd[x]);
          }
          if (a[i][bd[x]] == a[mxId][bd[x]]) {
            bad[i].erase(std::find(bad[i].begin(), bad[i].end(), bd[x]));
          }
        }
        r[bd[x]] = a[mxId][bd[x]];
      }
      for (int i = 0; i < n; ++i) updateMxId(i);
      if (dfs(c - f.size())) return true;
      for (auto x : f) {
        for (int i = 0; i < n; ++i) {
          if (a[i][bd[x]] == r[bd[x]]) {
            bad[i].emplace_back(bd[x]);
          }
          if (a[i][bd[x]] == tmp.front()) {
            bad[i].erase(std::find(bad[i].begin(), bad[i].end(), bd[x]));
          }
        }
        r[bd[x]] = tmp.front();
        tmp.pop();
      }
    } while (next(f, bd.size()));
    return false;
  }
 public:
  std::vector<int> r; // m 维向量，表示当前答案
  ECC(std::vector<std::vector<int>> _a) : a(_a), r(a[0]) {
    n = a.size(); m = r.size();
    bad.resize(n);
    mxId = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) if (a[i][j] != r[j]) {
        bad[i].emplace_back(j);
      }
      updateMxId(i);
    }
  }
  void setK(int _k) { k = _k;}
  bool solve() { return dfs(k);}
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (auto& x : a) for (auto& i : x) std::cin >> i;
  ECC A(a);
  A.setK(2);
  if (A.solve()) {
    std::cout << "Yes\n";
    for (auto x : A.r) std::cout << x << " ";
    std::cout << "\n";
  } else {
    std::cout << "No\n";
  }
  return 0;
}
