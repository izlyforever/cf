#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int query(int a, int b, int c) {
  std::cout << "? " << a << ' ' << b << ' ' << c << std::endl;
  int x;
  std::cin >> x;
  return x;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> type(n + 1, -1); // 1 for good
  n /= 3;
  std::vector<int> ans(n);
  for (int i = 0; i < n; ++i) ans[i] = query(i * 3 + 1, i * 3 + 2, i * 3 + 3);
  int g = std::find(ans.begin(), ans.end(), 1) - ans.begin();
  int b = std::find(ans.begin(), ans.end(), 0) - ans.begin();
  std::vector<int> a{g * 3 + 1, g * 3 + 2, g * 3 + 3, b * 3 + 1, b * 3 + 2, b * 3 + 3};
  int id = 0;
  if (query(a[1], a[2], a[3])) {
    if (query(a[2], a[3], a[4])) {
      id = 2;
    } else {
      id = 1;
    }
  }
  int x = a[id], y = a[id + 3];
  type[x] = 1;
  type[y] = 0;
  type[a[id + 1]] = query(x, y, a[id + 1]);
  type[a[id + 2]] = !type[a[id + 1]];
  for (auto t : a) {
    if (type[t] == -1) {
      type[t] = query(x, y, t);
    }
  }
  for (int i = 0; i < n; ++i) if (i != g && i != b) {
    if (ans[i]) {
      if (query(y, 3 * i + 1, 3 * i + 2)) {
        type[3 * i + 1] = type[3 * i + 2] = 1;
        type[3 * i + 3] = query(x, y, 3 * i + 3);
      } else {
        type[3 * i + 3] = 1;
        type[3 * i + 1] = query(x, y, 3 * i + 1);
        type[3 * i + 2] = !type[3 * i + 1];
      }
    } else {
      if (query(x, 3 * i + 1, 3 * i + 2)) {
        type[3 * i + 3] = 0;
        type[3 * i + 1] = query(x, y, 3 * i + 1);
        type[3 * i + 2] = !type[3 * i + 1];
      } else {
        type[3 * i + 1] = type[3 * i + 2] = 0;
        type[3 * i + 3] = query(x, y, 3 * i + 3);
      }
    }
  }
  std::vector<int> r;
  r.reserve(n * 2);
  for (int i = 1; i <= 3 * n; ++i) if (type[i] == 0) r.emplace_back(i);
  std::cout << "! " << r.size();
  for (auto x : r) std::cout << ' ' << x;
  std::cout << std::endl;
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