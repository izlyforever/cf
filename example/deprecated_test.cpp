#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

#if defined(_MSC_VER)
  #define DEPRECATED __declspec(deprecated)
#elif defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
  #define DEPRECATED __attribute__((deprecated))
#else
  #define DEPRECATED
#endif

DEPRECATED int f(int x) {
  return x * 2 + 3;
}

void solve() {
  int x = 3;
  std::cout << f(x) << '\n';
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
