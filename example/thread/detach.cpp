#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
template<typename T>
void debug(std::vector<T> a){
  for (auto& i : a) std::cout << i << ' ';
  std::cout << std::endl;
}

class Deng : public std::enable_shared_from_this<Deng> {
  std::vector<int> x_;
 public:
  Deng() : x_{2, 4, 6, 8} {}
  void process(std::vector<int>& x) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    cerr("process");
    x_.insert(x_.end(), x.begin(), x.end());
    x.clear();
  }
  void f(std::vector<int>& x) {
    // std::thread t(&Deng::process, this, std::ref(x));

    std::thread t([this, &x]() {
      this->process(x);
    });

    // std::weak_ptr<Deng> weak_this = shared_from_this();
    // std::thread t([weak_this, &x]() {
    //   auto shared_this = weak_this.lock();
    //   if (!shared_this) {
    //     return;
    //   }
    //   shared_this->process(x);
    // });

    t.detach();
  }
  std::vector<int> getValue() {
    return x_;
  }
};

int main() {
  {
    auto qiming = std::make_shared<Deng>();
    std::vector<int> x{1, 3, 2, 5};
    int timers = 1024;
    while (timers--) {
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      qiming->f(x);
    }
    debug(x);
    debug(qiming->getValue());
  }
  std::this_thread::sleep_for(std::chrono::seconds(2));
  return 0;
}