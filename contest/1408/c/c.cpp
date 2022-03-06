#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n, l;
    std::cin >> n >> l;
    std::vector<double> a(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    a.emplace_back(double(l));
    n += 2;
    std::vector<double> la(n), ra(n);
    a[0] = la[0] = ra[n - 1] = 0;
    for (int i = 1; i < n; ++i) {
      la[i] = la[i - 1] + (a[i] - a[i - 1]) / i;
    }
    for (int i = n - 2; i >= 0; --i) {
      ra[i] = ra[i + 1] + (a[i + 1] - a[i]) / (n - i - 1);
    }
    int id = 0;
    while (la[id] <= ra[id]) ++id;
    double t = id * la[id - 1] + (n - id) * ra[id] + a[id] - a[id - 1];
    std::cout.precision(15);
    std::cout << std::fixed << t / n << std::endl;
  }
  return 0;
}
