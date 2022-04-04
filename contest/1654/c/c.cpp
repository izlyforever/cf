#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  LL sm = 0;
  std::map<LL, int> S;
  for (int i = 0; i < n; ++i) {
    LL x;
    std::cin >> x;
    ++S[x];
    sm += x;
  }
  std::map<LL, int> Q;
  Q.insert({-sm, 1});
  while (!Q.empty()) {
    auto [nu, c] = *Q.begin();
    Q.erase(Q.begin());
    auto u = -nu;
    auto u2 = u / 2;
    if (u < S.rbegin()->first) return false;
    auto it = S.find(u);
    auto nc = c;
    if (it != S.end()) {
      nc -= it->second;
      if (nc >= 0) S.erase(it->first);
    }
    if (nc > 0) {
      Q[-u2] += nc;
      Q[u2 - u] += nc;
    }
  }
  return true;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
