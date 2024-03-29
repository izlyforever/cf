#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

using Node = std::array<int, 5>;
int solve() {
  int n;
  std::cin >> n;
  std::vector<Node> a(n);
  for (auto& x : a) for (auto& i : x) std::cin >> i;
  auto cmp = [](const Node& A, const Node& B) -> bool {
    int ans = 0;
    for (int x = 0; x < 5; ++x) if (A[x] < B[x]) ++ans;
    return ans < 3;
  };
  auto mx = std::max_element(a.begin(), a.end(), cmp);
  for (auto it = a.begin(); it != a.end(); ++it) if (it != mx) {
    if (cmp(*mx, *it)) return -1;
  }
  return mx - a.begin() + 1;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}
