#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n, a, b, c;
  std::cin >> n >> a >> b >> c;
  struct Node {
    int x, y, z;
    bool operator<(const Node& A) const {
      return y - x < A.y - A.x;
    }
  };
  std::vector<Node> A(n);
  for (auto& [x, y, z] : A) std::cin >> x >> y >> z;
  std::sort(A.begin(), A.end());
  std::vector<LL> ans(n + 1, INT64_MIN);
  ans[0] = 0;
  for (int i = 0; i < n; ++i) {
    int mx = std::min(c, i + 1);
    for (int j = mx; j >= 0; --j) {
      ans[j] = std::max((j > 0 ? ans[j - 1] + A[i].z : 0LL), ans[j] + (i - j < a ? A[i].x : A[i].y));
    }
  }
  std::cout << ans[c] << '\n';
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
