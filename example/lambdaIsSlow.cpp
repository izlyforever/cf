#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

std::function<int(int)> getFun(std::vector<int> s) {
  return [s](int n) {
    return s[n];
  };
}
std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
class Timer final {
  std::chrono::high_resolution_clock::time_point start_;
  std::string name_;
 public:
  Timer(std::string name = {}) : start_(std::chrono::high_resolution_clock::now()), name_(name) {}
  ~Timer() {
    auto elapsedTime = std::chrono::high_resolution_clock::now() - start_;
    std::cerr << std::fixed << "[Time used: " << name_ << "] " << elapsedTime.count() / 1'000'000.0 << "ms\n";
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  const int N = 1e7 + 2;
  std::vector<int> s(N);
  for (auto &x : s) x = rnd();
  auto f = getFun(s);
  {
    Timer A; // 4.41ms
    LL sum = 0;
    for (auto x : s) sum += x;
    cerr(sum);
  }
  {
    Timer A; // 13.2ms
    LL sum = 0;
    for (int i = 0; i < N; ++i) sum += f(i);
    cerr(sum);
  }
  return 0;
}
