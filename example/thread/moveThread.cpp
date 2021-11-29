#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
template<typename T>
void debug(std::vector<T> a){
  for (auto& i : a) std::cout << i << ' ';
  std::cout << std::endl;
}
void f1() {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  cerr("moveThread1");
}
void f2() {
  std::this_thread::sleep_for(std::chrono::seconds(1));
  cerr("moveThread2");
}

int main() {
  auto t = std::thread(f1);
  cerr(t.get_id());
  if (std::thread::id() != t.get_id()) {
    cerr("unfinish");
  }
  t.detach();
  std::this_thread::sleep_for(std::chrono::seconds(2));
  if (std::thread::id() == t.get_id()) {
    cerr("finish");
  }
  cerr(t.get_id());
  t = std::thread(f2);
  cerr(t.get_id());
  t.detach();
  std::this_thread::sleep_for(std::chrono::seconds(2));
  return 0;
}