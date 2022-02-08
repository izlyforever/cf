#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int query(int i, int j, int k) {
  std::cout << "? " << i << ' ' << j << ' ' << k << std::endl;
  int x;
  std::cin >> x;
  return x;
}

bool isEqual(const std::vector<int>& a, int x = 0) {
  auto mx = *std::max_element(a.begin(), a.end());
  for (int i = a.size() - 1; i > 1; --i) if (i != x) {
    if (a[i] != mx) return false;
  }
  return true;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 3; i <= n; ++i) {
    a[i] = query(1, 2, i);
  }
  int id = std::max_element(a.begin(), a.end()) - a.begin();
  b[2] = a[id];
  for (int i = 3; i <= n; ++i) if (i != id) {
    b[i] = query(1, i, id);
  }
  int di = std::max_element(b.begin(), b.end()) - b.begin();
  if (a[id] == b[di] && isEqual(a, 2)) {
    std::cout << "! " << 1 << ' ' << 2 << std::endl;
  } else if (isEqual(b, id)) {
    std::cout << "! " << 1 << ' ' << id << std::endl;
  } else {
    int t = 2;
    while (t == di || t == id) ++t;
    int tmp = query(t, di, id);
    if (tmp >= b[di]) std::cout << "! " << di << ' ' << id << std::endl;
    else std::cout << "! " << 1 << ' ' << di << std::endl;
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
