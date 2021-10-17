#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

bool isPrime(int n) {
  if (n == 2) return true;
  if (n % 2 == 0) return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

// 根据情况换成 bool
void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;
  int s = std::accumulate(a.begin(), a.end(), 0);
  if (!isPrime(s)) {
    std::cout << n << '\n';
    for (int i = 1; i <= n; ++i) std::cout << i << " \n"[i == n];
  } else {
    std::cout << n - 1 << '\n';
    int it = std::min_element(a.begin(), a.end()) - a.begin();
    if (isPrime(s - a[it])) {
      a[it] = INT_MAX;
      it = std::min_element(a.begin(), a.end()) - a.begin();
    }
    ++it;
    for (int i = 1; i <= n; ++i) if (i != it) {
      std::cout << i << ' ';
    }
    std::cout << '\n';
  }
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}