#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// 常规树状数组（编号从 1 开始，单点更新，区间求和，提供搜索）
struct Bitree {
  std::vector<LL> s;
  Bitree() {}
  Bitree(int n) : s(n + 1) {}
  int lowbit(int n) { return n & (-n); }
  void add(int id, int p) {
    while (id < s.size()) {
      s[id] += p;
      id += lowbit(id);
    }
  }
  LL sum(int id) {
    LL r = 0;
    while (id) {
      r += s[id];
      id -= lowbit(id);
    }
    return r;
  }
};

// 加强版树状数组（编号从 1 开始，区间更新，区间求和）
class BitreePlus {
  int n;
  // c[i] = a[i] - a[i - 1], b_i = (i - 1) * c_i
  Bitree B, C;
  void add(int id, int p) {
    C.add(id, p);
    B.add(id, (id - 1) * p);
  }
 public:
  BitreePlus() {}
  BitreePlus(int _n) : n(_n), B(n), C(n) {}
  void add(int l, int r, int p) {
    add(l, p);
    add(r + 1, -p);
  }
  LL sum(int id) { return id * C.sum(id) - B.sum(id); }
  LL sum(int l, int r) { return sum(r) - sum(l - 1); }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  BitreePlus A(2 * n);
  int k = 1;
  while (k <= n && a[k] == 0) ++k;
  if (k > 1) A.add(1, k - 1, 1);
  for (int i = 1, j = 0, x; i <= n; ++i) {
    std::cin >> x;
    if (x) {
      j = k++;
      while (k <= n && a[k] == 0) ++k;
    }
    if (j > n) continue;
    A.add(i + j, i + k - 1, 1);
  }
  std::cout << "1 ";
  for (int i = 1; i <= 2 * n; ++i) std::cout << A.sum(i, i) << " \n"[i == 2 * n];
  return 0;
}
