#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

class Timer {
  std::chrono::steady_clock::time_point start_;
 public:
  Timer() : start_(std::chrono::steady_clock::now()) {}
  void show() {
    auto elapsedTime = std::chrono::steady_clock::now() - start_;
    std::cout << "Time used: " << elapsedTime.count() / 1000 << "us\n";
  }
};

std::string password = "abcd";
bool ok(const std::string& x) {
  bool tmp = 0;
  for (int i = 0; i < 1000; ++i) {
    tmp |= (x == password);
  }
  return tmp;
}
void solve() {
  std::vector<std::string> ans = {"xbcd", "axcd", "abxd", "abcx", "abcd"};
  for (auto &x : ans) {
    Timer A;
    bool t = ok(x);
    A.show();
    std::cerr << x << ": " << t << '\n';
  }
}

int main() {
  //freopen("in", "r", stdin);
  solve();
  return 0;
}