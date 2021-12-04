#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class Timer {
  std::chrono::steady_clock::time_point start_;
 public:
  Timer() : start_(std::chrono::steady_clock::now()) {}
  void show() {
    auto elapsedTime = std::chrono::steady_clock::now() - start_;
    std::cerr << "Time used: " << (double)elapsedTime.count() / 1'000'000'000 << "s\n";
  }
};

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

LL f(int n) {
  std::vector<uint32_t> a;
  for (int i = 0; i < n; ++i) {
    a.emplace_back(rnd());
  }
  return std::accumulate(a.begin(), a.end(), 0LL);
}

int main() {
  int n = 1e7;
  Timer A;
  LL ans = f(n);
  A.show();
  cerr(ans);

  Timer B;
  auto b = new int[n];
  cerr(b[0]);   // 确保确实替换对了
  B.show();
}