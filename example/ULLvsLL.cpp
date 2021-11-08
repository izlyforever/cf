#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

class Timer {
  std::chrono::steady_clock::time_point start;
 public:
  Timer() : start(std::chrono::steady_clock::now()) {}
  void show(std::string s = {}) {
    auto elapsedTime = std::chrono::steady_clock::now() - start;
    std::cerr << "Time used[" << s << "]: " << elapsedTime.count() / 1000000 << "ms\n";
  }
};
std::mt19937_64 rnd64(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  const int N = 1e8 + 2;
  using ULL = unsigned long long;
  std::vector<LL> a(N), b(N);
  for (int i = 0; i < N; ++i) a[i] = rnd64();
  for (int i = 0; i < N; ++i) {
    b[i] = rnd64();
    if (b[i] == 0) ++b[i];
  }
  std::vector<ULL> ua(N), ub(N);
  for (int i = 0; i < N; ++i) ua[i] = a[i];
  for (int i = 0; i < N; ++i) ub[i] = b[i];
{
  Timer A;
  LL ans = 0;
  for (int i = 0; i < N; ++i) ans += ua[i] / ub[i];
  cerr(ans);
  A.show("ULL");
}
{
  Timer A;
  LL ans = 0;
  for (int i = 0; i < N; ++i) ans += a[i] / b[i];
  cerr(ans);
  A.show("LL");
}
}
// This example tell us there are no difference between ULL and LL
