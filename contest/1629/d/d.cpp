#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

bool solve() {
  int n;
  std::cin >> n;
  std::vector<std::string> a(n);
  for (auto &x : a) std::cin >> x;
  for (auto &x : a) {
    if (x.size() == 1 || x[0] == x.back()) return true;
  }
  std::vector<int> suf2(26 * 26), suf3(26 * 26 * 26);
  for (auto &x : a) {
    if (x.size() == 2) {
      ++suf2[(x[0] - 'a') * 26 + (x[1] - 'a')];
    } else {
      ++suf3[(x[0] - 'a') * 26 * 26 + (x[1] - 'a') * 26 + (x[2] - 'a')];
    }
  }
  for (auto &x : a) {
    if (suf2[(x[1] - 'a') * 26 + (x[0] - 'a')]) return true;
    if (x.size() == 2) {
      --suf2[(x[0] - 'a') * 26 + (x[1] - 'a')];
      for (int i = 0; i < 26; ++i) {
        if (suf3[i * 26 * 26 + (x[1] - 'a') * 26 + (x[0] - 'a')]) return true;
      }
    } else {
      --suf3[(x[0] - 'a') * 26 * 26 + (x[1] - 'a') * 26 + (x[2] - 'a')];
      if (suf3[(x[2] - 'a') * 26 * 26 + (x[1] - 'a') * 26 + (x[0] - 'a')]) return true;
    }
  }
  return false;
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