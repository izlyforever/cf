#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int N = 17;
using Node = std::array<int, N>;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::vector<Node> c(1 << N);
  Node tmp{};
  for (int i = 1; i < (1 << N); ++i) {
    for (int j = 0; j < N; ++j) {
      if (i & (1 << j)) ++tmp[j];
      c[i][j] = tmp[j];
    }
  }

  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int l, r;
    std::cin >> l >> r;
    Node b = c[r];
    if (l > 1) {
      Node t = c[l - 1];
      for (int i = 0; i < N; ++i) {
        b[i] -= t[i];
      }
    }
    Node d{};
    int mx = 0;
    std::vector<int> input;
    input.reserve(r - l + 1);
    for (int i = l; i <= r; ++i) {
      int x;
      std::cin >> x;
      input.emplace_back(x);
      mx = std::max(mx, x);
      for (int j = 0; j < N; ++j) {
        if (x & (1 << j)) ++d[j];
      }
    }
    int len = r - l + 1;
    auto check = [&](int x) {
      for (int i = 0; i < N; ++i) {
        if (x & (1 << i)) {
          if (b[i] != len - d[i]) return false;
        } else {
          if (b[i] != d[i]) return false;
        }
      }
      for (auto t : input) if ((x ^ t) > r || (x ^ t) < l) return false;
      return true;
    };
    for (auto x : input) {
      if (check(x ^ l)) {
        std::cout << (x ^ l) << '\n';
        break;
      }
    }
  }
  return 0;
}
