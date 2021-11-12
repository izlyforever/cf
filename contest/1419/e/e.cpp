#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

std::vector<int> pfactor(int n) {
  std::vector<int> r;
  for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
    r.emplace_back(i);
    while (n % i == 0) n /= i;
  }
  if (n > 1) r.emplace_back(n);
  return r;
}

std::set<int> factor(int n) {
  std::set<int> S{1};
  for (int i = 2; i * i <= n; ++i) if (n % i == 0) {
    S.insert(i);
    S.insert(n / i);
  }
  return S;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    auto p = pfactor(n);
    auto S = factor(n);
    if (p.size() == 2 && S.size() == 3) {
      std::cout << p[0] << ' ' << p[1] << ' ' << n << "\n1\n";
      continue;
    }
    if (p.size() > 1) for (int i = 0; i < p.size(); ++i) S.erase(p[i] * p[(i + 1) % p.size()]);
    for (int i = 0; i < p.size(); ++i) {
      auto pS = factor(n / p[i]);
      for (auto x : pS) if (int j = x * p[i]; S.count(j)) {
        S.erase(j);
        std::cout << j << ' ';
      }
      if (p.size() > 2 || i + 1 != p.size()) std::cout << p[i] * p[(i + 1) % p.size()] << ' ';
    }
    std::cout << n << "\n0\n";
  }
  return 0;
}