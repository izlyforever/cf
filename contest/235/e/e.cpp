#include <bits/stdc++.h>
using UL = unsigned;

const int N = 2e3 + 10086;
bool isp[N]{};
std::vector<int> p{0, 2}; // p.back() > n
void initPrime() {
  isp[2] = true;
  for (int i = 3; i < N; i += 2) isp[i] = true;
  int sq = int(std::sqrt(N + 0.1)) | 1;
  for (int i = 3; i <= sq; i += 2) if (isp[i]) {
    p.emplace_back(i);
    for (int j = i * i; j < N; j += i << 1) isp[j] = false;
  }
  for (int i = sq + 2; i < N; i += 2) if (isp[i]) p.emplace_back(i);
}

template<typename T>
void Mobius(std::vector<T>& a, int n) {   // new_a[n] = \sum_{d | n} old_a[d]
  for (int i = 1; p[i] <= n; ++i) {
    for (int j = 1; j * p[i] <= n; ++j) {
      a[j * p[i]] += a[j];
    }
  }
}
template<typename T>
void MobiusInv2(std::vector<T>& a, int n) { // old_a[n] = \sum_{d | n} new_a[d]
  for (int i = p.size() - 2; i; --i) {
    for (int j = n / p[i]; j; --j) {
      a[j * p[i]] -= a[j];
    }
  }
}
template<typename T>
void MobiusInv(std::vector<T>& a, int n) {
  for (int i = 1; i <= n; ++i) {
    for (int j = i * 2; j <= n; j += i) {
      a[j] -= a[i];
    }
  }
}
template<typename T>
void MobiusTFalse(std::vector<T>& a, int n) {
  for (int i = 1; p[i] <= n; ++i) {
    for (int j = 1; j * p[i] <= n; ++j) {
      a[j] += a[j * p[i]];
    }
  }
}

template<typename T>
void MobiusT(std::vector<T>& a, int n) {
  for (int i = 1; p[i] <= n; ++i) {
    for (int j = n / p[i]; j; --j) {
      a[j] += a[j * p[i]];
    }
  }
}

// total complex: $O(n \sqrt{n} \log n)$
UL solve() {
  int aa, bb, cc;
  std::cin >> aa >> bb >> cc;
  int n = std::max({aa, bb, cc});
  std::cin >> n;
  initPrime();
  p.resize(std::upper_bound(p.begin(), p.end(), n) - p.begin() + 1);
  std::vector<UL> a(n + 1), b(n + 1), c(n + 1), d(n + 1), e(n + 1), f(n + 1);
  for (int i = 1; i <= n; ++i) a[i] = aa / i;
  for (int i = 1; i <= n; ++i) b[i] = bb / i;
  for (int i = 1; i <= n; ++i) c[i] = cc / i;
  d[1] = e[1] = f[1] = 1;
  MobiusInv(e, n);
  MobiusInv(f, n);
  MobiusT(c, n);
  std::vector<UL> p(n + 1), q(n + 1), r(n + 1), s(n + 1), t(n + 1), w(n + 1), u(n + 1), v(n + 1);
  UL ans = 0;
  for (int i = 1; i <= n; ++i) { // d has been used
    int m = n / i;
    for (int j = 1; j <= m; ++j) {
      p[j] = e[j * i];
      q[j] = f[j * i];
      r[j] = c[j * i];
      s[j] = a[j * i];
      t[j] = b[j * i];
      w[j] = d[j * i];
    }
    MobiusInv(w, m);
    // if x * x > m, we conside y as x
    for (int x = 1; x * x <= m; ++x) {
      std::fill(u.begin(), u.begin() + m + 1, 0);
      std::fill(v.begin(), v.begin() + m + 1, 0);
      // only consider multiply of x
      for (int j = x; j <= m; j += x) {
        u[j] = s[j];
        v[j] = t[j];
      }
      MobiusT(u, m);
      MobiusT(v, m);
      for (int j = 1; j <= m; ++j) {
        u[j] *= w[j];
        v[j] *= w[j];
      }
      Mobius(u, m);
      Mobius(v, m);
      for (int j = 1; j <= m; ++j) {
        u[j] *= t[j];
        v[j] *= s[j];
      }
      for (int y = x; x * y <= m; ++y) if (std::gcd(x, y) == 1) {
        UL s1 = 0, s2 = 0;
        for (int j = y; j <= m; j += y) {
          s1 += u[j];
          s2 += v[j];
        }
        ans += s1 * p[x] * q[y] * r[x * y];
        if (x != y) ans += s2 * p[y] * q[x] * r[x * y];
      }
    }
  }
  return ans % 1073741824;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << solve() << '\n';
  return 0;
}