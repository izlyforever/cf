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
    std::vector<int> a(n), id(n);
    std::string s(n, '0');
    for (auto& x : a) std::cin >> x;
    for (auto& c : s) std::cin >> c;
    std::iota(id.begin(), id.end(), 0);
    std::sort(id.begin(), id.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    std::vector<int> A[2], ans(n);
    for (auto x : id) {
      int bit = a[x] & 1;
      if (s[x] == 'R') A[bit].emplace_back(x);
      else if (!A[bit].empty() && s[A[bit].back()] == 'R') {
        ans[A[bit].back()] = ans[x] = (a[x] - a[A[bit].back()]) / 2;
        A[bit].pop_back();
      } else A[bit].emplace_back(x);
    }
    for (int bit = 0; bit < 2; ++bit) {
      while ((int)A[bit].size() > 1) {
        int x = A[bit].back();
        A[bit].pop_back();
        if (s[x] == 'R' && s[A[bit].back()] == 'R') {
          ans[x] = ans[A[bit].back()] = m - (a[x] + a[A[bit].back()]) / 2;
          A[bit].pop_back();
        } else {
          A[bit].emplace_back(x);
          break;
        }
      }
      int now = 0;
      for (; now + 1 < (int)A[bit].size() && s[A[bit][now + 1]] == 'L'; now += 2) {
        ans[A[bit][now]] = ans[A[bit][now + 1]] = (a[A[bit][now]] + a[A[bit][now + 1]]) / 2;
      }
      if (A[bit].size() & 1) ans[A[bit].back()] = -1;
      else if (!A[bit].empty() && s[A[bit].back()] == 'R') {
        ans[A[bit][now]] = ans[A[bit][now + 1]] = m + (a[A[bit][now]] - a[A[bit][now + 1]]) / 2;
      }
    }
    for (auto x : ans) std::cout << x << ' ';
    std::cout << '\n';
  }
  return 0;
}
