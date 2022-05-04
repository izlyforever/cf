#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

uint64_t tick_ms() {
  return std::chrono::duration_cast<std::chrono::milliseconds>(
             std::chrono::steady_clock::now().time_since_epoch()).count();
}

template <typename T>
class PassiveDelayedTimeQueue {
 public:
  void setDelayedTime(uint32_t delay_ms) { delay_ms_ = delay_ms; }
  void clear() {
    std::lock_guard<std::mutex> lock(mutex_);
    std::queue<std::pair<uint64_t, T>>().swap(buffer_);
  }
  int size() {
    std::lock_guard<std::mutex> lock(mutex_);
    return static_cast<int>(buffer_.size());
  }
  void insert(T&& element) {
    uint64_t current_time = tick_ms();
    std::lock_guard<std::mutex> lock(mutex_);

    buffer_.emplace(current_time, std::move(element));
  }
  bool fetch(T& element) {
    std::lock_guard<std::mutex> lock(mutex_);
    uint64_t current_time = tick_ms();

    if (buffer_.empty() || buffer_.front().first + delay_ms_ > current_time) {
      return false;
    }
    element = std::move(buffer_.front().second);
    buffer_.pop();
    return true;
  }

 private:
  std::atomic<uint32_t> delay_ms_{0};
  std::queue<std::pair<uint64_t, T>> buffer_;
  mutable std::mutex mutex_;
};

template<typename T>
class A {
 public:
   A(T x) : x_(x) {}
   ~A() {
     std::cout << static_cast<uint64_t>(x_) << std::endl;
   }
  T x_;
};
using A1 = A<uint8_t>;
using A2 = A<uint16_t>;
using A4 = A<uint32_t>;
using A8 = A<uint64_t>;
using DA8 = PassiveDelayedTimeQueue<std::shared_ptr<A8>>;

void solve() {
  std::queue<A1> a1;
  std::queue<A2> a2;
  std::queue<A4> a3;
  std::queue<A8> a4;
  for (int i = 0; i < 16; ++i) {
    a1.emplace(i);
    a2.emplace(i);
    a3.emplace(i);
    a4.emplace(i);
  }
  for (int i = 0; i < 16; ++i) {
    std::cout << std::endl;
    std::cout << i << " a1: " << std::endl;
    a1.pop();
    std::cout << i << " a2: " << std::endl;
    a2.pop();
    std::cout << i << " a3: " << std::endl;
    a3.pop();
    std::cout << i << " a4: " << std::endl;
    a4.pop();
  }
  {
    DA8 x;
    x.setDelayedTime(100);
    for (int i = 0; i < 10; ++i) {
      x.insert(std::make_shared<A8>(i));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    auto u = std::make_shared<A8>(-1);
    for (int i = 0; i < 10; ++i) {
      bool flag = x.fetch(u);
    }
  }
  std::cout << "finish" << std::endl;
  {
    DA8 x;
    x.setDelayedTime(100);
    for (int i = 0; i < 10; ++i) {
      x.insert(std::make_shared<A8>(i));
    }
    x.clear();
  }
  std::cout << "end" << std::endl;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
