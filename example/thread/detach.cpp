#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
template<typename T>
void debug(std::vector<T> a){
  for (auto& i : a) std::cout << i << ' ';
  std::cout << std::endl;
}

class Deng {
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
    std::thread t(&Deng::process, this, std::ref(x));
    t.detach();
  }
  std::vector<int> getValue() {
    return x_;
  }
};

int main() {

{
  Deng qiming;
  std::vector<int> x{1, 3, 2, 5};
  qiming.f(x);
  debug(x);
  debug(qiming.getValue());
}
std::this_thread::sleep_for(std::chrono::seconds(2));
}