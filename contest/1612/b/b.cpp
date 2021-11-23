#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

void solve() {
  int n, a, b;
  std::cin >> n >> a >> b;
  if (a > b + 1) {
    std::cout << "-1\n";
    return;
  }
  std::vector<int> cnt(n + 1, 1);
  std::vector<int> l{a}, r{b};
  cnt[a] = cnt[b] = 0;
  for (int i = 1; i < a; ++i) if (cnt[i]) {
    cnt[i] = 0;
    r.emplace_back(i);
  }
  for (int i = b + 1; i <= n; ++i) if (cnt[i]) {
    cnt[i] = 0;
    l.emplace_back(i);
  }
  if (l.size() > n / 2 || r.size() > n / 2) {
    std::cout << "-1\n";
  } else {
    int now = 1;
    while (l.size() < n / 2) {
      while (cnt[now] == 0) ++now;
      cnt[now] = 0;
      l.emplace_back(now);
    }
    for (int i = now; i <= n; ++i) if (cnt[i]) {
      cnt[i] = 0;
      r.emplace_back(i);
    }
    assert(l.size() == n / 2);
    assert(r.size() == n / 2);
    for (auto x : l) std::cout << x << ' ';
    for (auto x : r) std::cout << x << ' ';
    std::cout << '\n';
  }
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