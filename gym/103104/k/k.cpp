#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// 第二分块
class BlockAbs {
  int l, r; // l, r 表示当前值域 fa, sz 的区间 [l, r]
  int f, d; // x \in [l, r] 它真实的值是 f x - d, f = 1, -1
  std::vector<int> fa;
  int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
  }
  void merge(int x, int y) { // merge x to y
    fa[find(x)] = find(y);
  }
 public:
  BlockAbs(int mx) : l(0), r(mx), f(1), d(0), fa(mx + 1) {
    std::iota(fa.begin(), fa.end(), 0);
  }
  void add(int x) { // |fi - d - x| = | i - (x + d) f|
    x = (x + d) * f;
    if ((l + r) < 2 * x) {
      f = -1;
      d = -x;
      if (x < r) {
        for (int i = r; i > x; --i) merge(i, 2 * x - i);
        r = x;
      }
    } else {
      f = 1;
      d = x;
      if (x > l) {
        for (int i = l; i < x; ++i) merge(i, 2 * x - i);
        l = x;
      }
    }
  }
  int query(int x) {
    return find(x) * f - d;
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  // 可以离线公用同一个 BlockAbs 省空间！如果强制在线的话，空间就不知道怎么省了
  int sn = sqrt(n);
  std::vector<BlockAbs> block;
  for (int i = 0; i < n; i += sn) {
    BlockAbs tmp(1e5 + 2);
    for (int j = i; j < n && j < i + sn; ++j) {
      tmp.add(a[j]);
    }
    block.emplace_back(tmp);
  }
  int ans = 0;
  while (m--) {
    int l, r, val;
    std::cin >> l >> r >> val;
    l ^= ans, r ^= ans, val ^= ans;
    --l;
    int bl = l / sn, br = r / sn;
    if (bl == br) {
      for (int i = l; i < r; ++i) val = abs(val - a[i]);
    } else {
      for (int i = l, tl = bl * sn + sn; i < tl; ++i) val = abs(val - a[i]);
      for (int i = bl + 1; i < br; ++i) val = block[i].query(val);
      for (int i = br * sn; i < r; ++i) val = abs(val - a[i]);
    }
    ans = val;
    std::cout << ans << '\n';
  }
  return 0;
}