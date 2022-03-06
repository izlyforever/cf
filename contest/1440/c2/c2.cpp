#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> s(n);
    for (auto& x : s) std::cin >> x;
    std::vector<std::pair<int, int>> r;
    auto f = [](char& x) {x = (x == '0' ? '1' : '0');};
    for (int i = n - 1; i > 1; --i) {
      for (int j = m - 1; j >= 0; --j) if (s[i][j] == '1') {
        r.emplace_back(i, j);
        r.emplace_back(i - 1, j);
        f(s[i - 1][j]);
        if (j > 0) {
          r.emplace_back(i - 1, j - 1);
          f(s[i - 1][j - 1]);
        } else {
          r.emplace_back(i - 1, j + 1);
          f(s[i - 1][j + 1]);
        }

      }
    }
    for (int j = m - 1; j > 1; --j) {
      for (int i = 0; i < 2; ++i) {
        if (s[i][j] == '1') {
          r.emplace_back(i, j);
          r.emplace_back(i, j - 1);
          r.emplace_back(1 - i, j - 1);
          f(s[i][j - 1]);
          f(s[1 - i][j - 1]);
        }
      }
    }
    std::deque<std::pair<int, int>> t[2];
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        t[s[i][j] - '0'].emplace_back(i, j);
      }
    }
    auto g = [&](int i) {
      r.emplace_back(t[i].back());
      t[1 - i].emplace_front(t[i].back());
      t[i].pop_back();
    };
    if (t[1].size() == 4) {
      for (int i = 0; i < 3; ++i) g(1);
    }
    if (t[1].size() == 1) {
      g(1);
      for (int i = 0; i < 2; ++i) g(0);
    }
    if (t[1].size() == 2) {
      g(1);
      for (int i = 0; i < 2; ++i) g(0);
    }
    if (t[1].size() == 3) {
      for (int i = 0; i < 3; ++i) g(1);
    }
    std::cout << r.size() / 3 << std::endl;
    for (int i = 0; i * 3 < r.size(); ++i) {
      for (int j = 0; j < 3; ++j) {
        std::cout << r[i * 3 + j].first + 1 << " " << r[i * 3 + j].second + 1 << " \n"[j == 2];
      }
    }
  }
  return 0;
}
