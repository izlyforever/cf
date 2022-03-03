#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
std::shared_timed_mutex m;

int x = 1;


uint64_t now_ms() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(
             std::chrono::system_clock::now().time_since_epoch())
      .count();
}

void read() {
  std::shared_lock<std::shared_timed_mutex> _(m);
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  auto ms = now_ms();
  std::cout << " read: " << ms << ", x: " << x << std::endl;
}

void write() {
  std::lock_guard<std::shared_timed_mutex> _(m);
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  auto ms = now_ms();
  x = 2;
  std::cout << "write: " << ms << ", x: " << x << std::endl;
}

void solve() {
  std::vector<std::thread> a;
  std::thread w;
  for (int i = 0; i < 10; ++i) {
    a.emplace_back(std::thread(read));
    std::this_thread::sleep_for(std::chrono::milliseconds(400));
    if (i == 0) w = std::move(std::thread(write));
  }
  w.join();
  for (auto &x : a) x.join();
}

int main() {
  // std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}