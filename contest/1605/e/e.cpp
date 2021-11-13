#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

class Node {
  static inline constexpr double INF = DBL_MAX / 2;
  static inline constexpr double EPS = 1e-6;
 public:
  LL x_, y_;
  Node(LL x = 0, LL y = 0) : x_(x), y_(y) {}
  double getVal() const {
    if (x_ == 0) return INF;
    return -1.0 * y_ / x_;
  }
  Node operator-() const {
    return Node(-x_, -y_);
  }
  bool operator<(const Node& rhs) const {
    return getVal() + EPS < rhs.getVal();
  }
  Node operator-(const Node& rhs) const {
    return Node(x_ - rhs.x_, y_ - rhs.y_);
  }
  Node operator+(const Node& rhs) const {
    return Node(x_ + rhs.x_, y_ + rhs.y_);
  }
  Node& operator+=(const Node& rhs) {
    x_ += rhs.x_;
    y_ += rhs.y_;
    return *this;
  }
};
 
void solve() {
  int n;
  std::cin >> n;
  std::vector<Node> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; ++i) {
    LL x;
    std::cin >> x;
    a[i] = Node(0, x);
  }
  for (int i = 1; i <= n; ++i) {
    LL x;
    std::cin >> x;
    b[i] = Node(0, x);
  }
  b[1] = {1, 0};
  std::vector<Node> ans(n + 1);
  for (int i = 1; i <= n; ++i) {
    ans[i] = b[i] - a[i];
    for (int j = i; j <= n; j += i) {
      a[j] += ans[i];
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (ans[i].x_ < 0) ans[i] = -ans[i];
    else if (ans[i].x_ == 0) ans[i].y_ = -abs(ans[i].y_);
  }
  std::sort(ans.begin() + 1, ans.end());
  auto pre = ans, suf = ans;
  for (int i = 2; i <= n; ++i) pre[i] += pre[i - 1];
  for (int i = n; i >= 2; --i) suf[i - 1] += suf[i];
  suf.emplace_back(Node(0, 0));
  auto getAns = [&](LL x) -> LL {
    int id = std::lower_bound(ans.begin() + 1, ans.end(), Node(-1, x)) - ans.begin();
    return pre[id - 1].x_ * x + pre[id - 1].y_ - suf[id].x_ * x - suf[id].y_;
  };
  int q;
  std::cin >> q;
  while (q--) {
    LL x;
    std::cin >> x;
    std::cout << getAns(x) << '\n';
  }
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
