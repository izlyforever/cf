#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
#undef _GLIBCXX_DEBUG
using LL = long long;

// xor version of Gauss-Jordan Elimination with 0-1-matrix A
template <typename T>
std::vector<T> GaussXor(std::vector<std::vector<T>> A, std::vector<T> b) {
  int n = (int)A.size(), m = (int)A[0].size();
  std::vector<T> x(m);
  std::vector<int> p(m);
  std::iota(p.begin(), p.end(), 0);
  auto triangleGauss = [&](int sz) { // A[i][i] = 1
    std::vector<T> x(sz);
    for (int i = sz - 1; i >=0; --i) {
      x[i] = b[i];
      for (int row = 0; row < i; ++row) if (A[row][i]) {
        b[row] ^= x[i];
      }
    }
    x.resize(m);
    return x;
  };
  auto findNonZero = [&](int i) {
    for (int row = i; row < n; ++row) if (A[row][i]) return row;
    return n;
  };
  int sz = n;
  for (int i = 0, row = 0; i < n; ++i) {
    while (i < m) {
      row = findNonZero(i);
      if (row != n) break;
      for (int j = 0; j < n; ++j) A[j][i] = A[j][m - 1];
      std::swap(p[i], p[--m]);
    }
    if (i == m) {
      for (int row = m; row < n; ++row) if (b[row]) {
        // std::cout << "\nNo answer\n";
        return {};
      }
      sz = i;
      break;
    }
    if (row != i) {
      std::swap(A[i], A[row]);
      std::swap(b[i], b[row]);
    }
    for (int row = i + 1; row < n; ++row) if (A[row][i]) {
      b[row] ^= b[i];
      for (int j = m - 1; j >= i; --j) A[row][j] ^= A[i][j];
    }
  }
  // if (sz != m) std::cout << "\nInfinite answer\n";
  auto xt = triangleGauss(sz);
  for (int t = 0; t < m; ++t) x[p[t]] = xt[t];
  return x;
}

template<typename T>
void xorVector(std::vector<T>& a, const std::vector<T>& b) {
  for (int i = 0, n = (int)a.size(); i < n; ++i) {
    a[i] ^= b[i];
  }
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> a(n + 2, std::vector<int>(n + 2));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cin >> a[i][j];
    }
  }
  // // coefficient
  // std::vector<std::vector<int>> c(n + 2, std::vector<int>(n + 3));
  // auto cc = c;
  // for (int i = 1; i <= n; ++i) c[i][i] = 1;
  // for (int i = 1; i <= n; ++i) {
  //   auto cn = std::vector<std::vector<int>>(n + 2, std::vector<int>(n + 3));
  //   for (int j = 1; j <= n; ++j) {
  //     cn[j].back() = a[i][j];
  //     xorVector(cn[j], c[j - 1]);
  //     xorVector(cn[j], c[j + 1]);
  //     xorVector(cn[j], cc[j]);
  //   }
  //   std::swap(c, cc);
  //   std::swap(c, cn);
  // }
  auto aa = a;
  // {
  //   std::vector<std::vector<int>> A(n, std::vector<int>(n));
  //   std::vector<int> b(n);
  //   for (int i = 0; i < n; ++i) {
  //     b[i] = c[i + 1].back();
  //     for (int j = 0; j < n; ++j) {
  //       A[i][j] = c[i + 1][j + 1];
  //     }
  //   }
  //   auto cur = GaussXor<int>(std::move(A), std::move(b));
  //   for (int i = 0; i < n; ++i) {
  //     aa[1][i + 1] = cur[i];
  //   }
  // }
  aa[1] = std::vector<int>(n + 2);
  for (int i = 1; i <= n; ++i) {
    auto now = a[i];
    for (int j = 1; j <= n; ++j) {
      now[j] ^= aa[i - 1][j];
    }
    for (int j = 1; j <= n; ++j) {
      now[j] ^= aa[i][j - 1] ^ aa[i][j + 1];
    }
    std::swap(aa[i + 1], now);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      ans ^= aa[i][j];
    }
  }
  std::cout << ans << '\n';
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

