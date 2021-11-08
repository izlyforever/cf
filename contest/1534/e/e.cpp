#include <bits/stdc++.h>
using LL = long long;

void out(int x) {
  std::cout << "! " << x << std::endl;
}
void solve() {
  int n, k;
  std::cin >> n >> k;
  auto query = [&](int l, int r) {
    for (int i = l; i <= r; ++i) {
      std::cout << (i > n ? i - n : i) << ' ';
    }
  };
  if (k % 2 == 0 && n % 2 == 1) {
    std::cout << -1 << std::endl;
    return;
  }
  int a = n / k, b = n % k;
  if (b) {
    if (k % 2 == 1) {
      if (b % 2 == 1) {
        --a;
        b += k;
      }
    } else {
      if (a > 1) {
        --a;
        b += k;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < a; ++i) {
    std::cout << "? ";
    query(i * k + 1, (i + 1) * k);
    std::cout << std::endl;
    int tmp;
    std::cin >> tmp;
    ans ^= tmp;
  }
  if (a > 0) {
    if (b > 0) {
      b /= 2;
      int x = k - b;
      for (int i = 0; i < 2; ++i) {
        std::cout << "? ";
        query(1, x);
        query(a * k + b * i + 1, a * k + b * (i + 1));
        std::cout << std::endl;
        int tmp;
        std::cin >> tmp;
        ans ^= tmp;
      }
    }
  } else { // 此时只可能 k 为奇数，n 为偶数 且 k < n < 2k
    int x = 2 * (n - k);
    int t = n / x;
    for (int i = 0; i < t; ++i) {
      for (int j = 0; j < 2; ++j) {
        std::cout << "? ";
        query(i * x + j * x / 2 + 1, i * x + (j + 1) * x / 2);
        query((i + 1) * x + 1, (i + 1) * x + k - x / 2);
        std::cout << std::endl;
        int tmp;
        std::cin >> tmp;
        ans ^= tmp;
      }
    }
    int y = n % x;
    if (y) {
      for (int j = 0; j < 2; ++j) {
        std::cout << "? ";
        query(t * x + j * y / 2 + 1, t * x + (j + 1) * y / 2);
        query(t * x + y + 1, t * x + y + k - y / 2);
        std::cout << std::endl;
        int tmp;
        std::cin >> tmp;
        ans ^= tmp;
      }
    }
  }
  out(ans);
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas; // 根据情况注释掉
  while (cas--) {
    solve();
  }
  return 0;
}