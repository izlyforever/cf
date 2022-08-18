#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

template<typename T>
class Trie01 {
  std::vector<std::array<int, 2>> ch_;
  std::vector<std::array<T, 2>> val_;
  void upmax(T& x, T y) {
    x = std::max(x, y);
  }
  void addNode(int fa, int c) {
    ch_[fa][c] = ch_.size();
    ch_.push_back({});
    val_.push_back({});
  }
 public:
  Trie01() : ch_(1), val_(1) {}
  void insert(int x, int y, T z) {
    for (int i = 30, p = 0; i >= 0; --i) {
      int c = x >> i & 1;
      if (ch_[p][c] == 0) addNode(p, c);
      p = ch_[p][c];
      upmax(val_[p][y >> i & 1], z);
    }
  }
  T query(T x, T y) {
    T ans = 0;
    for (int i = 30, p = 0; i >= 0; --i) {
      int c = x >> i & 1;
      upmax(ans, val_[ch_[p][!c]][y >> i & 1]);
      p = ch_[p][c];
      if (p == 0) break;
    }
    return ++ans;
  }
};

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  Trie01<int> A;
  std::vector<int> dp(n);
  for (int i = 0; i < n; ++i) {
    dp[i] = A.query(a[i] ^ i, i);
    A.insert(a[i] ^ i, a[i], dp[i]);
  }
  int ans = *std::max_element(dp.begin(), dp.end());
  std::cout << ans << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
