#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), cnt(n + 1), b(n + 1);
  std::vector<std::set<int>> s(n + 1);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
    s[a[i]].insert(i);
  }
  for (int i = 1; i <= n; ++i) if (s[i].size() == 0) {
    int x = i, y = a[i];
    while (y != 0) {
      b[x] = y;
      for (auto t : s[y]) a[t] = 0;
      x = y;
      y = a[y];
    }
  }
  for (int i = 0; i <= n; ++i) if (a[i]) b[i] = a[i];
  int ans = 0;
  for (int i = 0; i <= n; ++i) if (b[i]) {
    ++cnt[b[i]];
    ++ans;
  }
  std::vector<int> tmp;
  for (int i = 1, x = 1; i <= n; ++i) if (b[i] == 0) {
    while (x <= n && cnt[x]) ++x;
    b[i] = x++;
    tmp.emplace_back(i);
  }
  for (int i = 0, ti = tmp.size(); i < ti; ++i) if (b[tmp[i]] == tmp[i]) {
    std::swap(b[tmp[i]], b[tmp[i - 1]]);
  }
  std::cout << ans << '\n';
  for (int i = 1; i <= n; ++i) std::cout << b[i] << " \n"[i == n];
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

// #include <bits/stdc++.h>
// #define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
// using LL = long long;

// // 根据情况换成 bool
// void solve() {
//   int n;
//   std::cin >> n;
//   std::vector<int> a(n + 1), cnt(n + 1), b(n + 1);
//   std::vector<std::set<int>> s(n + 1);
//   for (int i = 1; i <= n; ++i) {
//     std::cin >> a[i];
//     s[a[i]].insert(i);
//   }
//   for (int i = 1; i <= n; ++i) if (s[i].size() == 0) {
//     int x = i, y = a[i];
//     while (y != 0) {
//       b[x] = y;
//       for (auto t : s[y]) a[t] = 0;
//       x = y;
//       y = a[y];
//     }
//   }
//   int ans = 0;
//   for (int i = 0; i <= n; ++i) if (b[i]) {
//     ++cnt[b[i]];
//     ++ans;
//   }
//   std::vector<int> tmp;
//   for (int i = 1, x = 1; i <= n; ++i) if (b[i] == 0) {
//     while (x <= n && cnt[x]) ++x;
//     b[i] = x++;
//     tmp.emplace_back(i);
//   }
//   auto check = [&]() -> bool {
//     for (auto x : tmp) if (b[x] == x) return 0;
//   };
//   while (1) {
//     for (int i = 0, ti = tmp.size(); i < ti; ++i) if (b[tmp[i]] == tmp[i]) {
//       std::swap(b[tmp[i]], b[tmp[i - 1]]);
//     }
//   }
//   std::cout << ans << '\n';
//   for (int i = 1; i <= n; ++i) std::cout << b[i] << " \n"[i == n];
// }

// int main() {
//   std::cin.tie(nullptr)->sync_with_stdio(false);
//   int cas = 1;
//   std::cin >> cas;
//   while (cas--) {
//     solve();
//   }
//   return 0;
// }
// // 6
// // 3 3 4 3 6 5