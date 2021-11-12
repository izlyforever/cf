#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

#include <cstdio>
#include <algorithm>
#include <vector>

const int P = 998244353;

void add(int& x, int y) {
    (x += y) >= P && (x -= P);
}
void sub(int& x, int y) {
    (x -= y) < 0 && (x += P);
}
struct FWT {
    int extend(int n) {
        int N = 1;
        for (; N < n; N <<= 1);
        return N;
    }
    void FWTor(std::vector<int>& a, bool rev) {
        int n = a.size();
        for (int l = 2, m = 1; l <= n; l <<= 1, m <<= 1) {
            for (int j = 0; j < n; j += l) for (int i = 0; i < m; i++) {
                if (!rev) add(a[i + j + m], a[i + j]);
                else sub(a[i + j + m], a[i + j]);
            }
        }
    }
    void FWTand(std::vector<int>& a, bool rev) {
        int n = a.size();
        for (int l = 2, m = 1; l <= n; l <<= 1, m <<= 1) {
            for (int j = 0; j < n; j += l) for (int i = 0; i < m; i++) {
                if (!rev) add(a[i + j], a[i + j + m]);
                else sub(a[i + j], a[i + j + m]);
            }
        }
    }
    void FWTxor(std::vector<int>& a, bool rev) {
        int n = a.size(), inv2 = (P + 1) >> 1;
        for (int l = 2, m = 1; l <= n; l <<= 1, m <<= 1) {
            for (int j = 0; j < n; j += l) for (int i = 0; i < m; i++) {
                int x = a[i + j], y = a[i + j + m];
                if (!rev) {
                    a[i + j] = (x + y) % P;
                    a[i + j + m] = (x - y + P) % P;
                } else {
                    a[i + j] = 1LL * (x + y) * inv2 % P;
                    a[i + j + m] = 1LL * (x - y + P) * inv2 % P;
                }
            }
        }
    }
    std::vector<int> Or(std::vector<int> a1, std::vector<int> a2) {
        int n = std::max(a1.size(), a2.size()), N = extend(n);
        a1.resize(N), FWTor(a1, false);
        a2.resize(N), FWTor(a2, false);
        std::vector<int> A(N);
        for (int i = 0; i < N; i++) A[i] = 1LL * a1[i] * a2[i] % P;
        FWTor(A, true);
        return A;
    }
    std::vector<int> And(std::vector<int> a1, std::vector<int> a2) {
        int n = std::max(a1.size(), a2.size()), N = extend(n);
        a1.resize(N), FWTand(a1, false);
        a2.resize(N), FWTand(a2, false);
        std::vector<int> A(N);
        for (int i = 0; i < N; i++) A[i] = 1LL * a1[i] * a2[i] % P;
        FWTand(A, true);
        return A;
    }
    std::vector<int> Xor(std::vector<int> a1, std::vector<int> a2) {
        int n = std::max(a1.size(), a2.size()), N = extend(n);
        a1.resize(N), FWTxor(a1, false);
        a2.resize(N), FWTxor(a2, false);
        std::vector<int> A(N);
        for (int i = 0; i < N; i++) A[i] = 1LL * a1[i] * a2[i] % P;
        FWTxor(A, true);
        return A;
    }
} fwt;

int main() {;
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n);
  for (auto& x : a) std::cin >> x;
  std::vector<int> c(1 << n), g(1 << n);
  for (int i = 0; i < m; ++i) {
    int r = 0;
    for (int j = 0; j < n; ++j) {
      r |= (a[j][i] - '0') << j;
    }
    ++c[r];
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (1 << n); ++j) {
      if (j & (1 << i)) ++g[j];
    }
  }
  for (int i = 0; i < (1 << n); ++i) {
    g[i] = std::min(g[i], n - g[i]);
  }
  auto f = fwt.Xor(c, g);
  print(*std::min_element(f.begin(), f.end()));
  return 0;
}