#include <bits/stdc++.h>
std::condition_variable cv;
std::mutex cv_m;
bool finish = false;
using namespace std::chrono_literals;

const int N = 1e6 + 2;
std::vector<int> mu(N);
void initMu() {
  mu[1] = 1;
  for (int i = 1; i < N; ++i) {
    for (int j = i + i; j < N; j += i) {
      mu[j] -= mu[i];
    }
  }
  std::cout << "finish" << std::endl;
  {
    std::lock_guard<std::mutex> _(cv_m);
    finish = true;
  }
  cv.notify_all();
}

int main() {
  std::thread t(initMu);
  std::unique_lock<std::mutex> _(cv_m);
  // if (cv.wait_for(_, std::chrono_literals::100ms, []{ return finish;})) {
  if (cv.wait_for(_, 10ms, []{ return finish;})) {
    std::cout << "So fast!\n";
  } else {
    std::cout << "TimeOut!\n";
  }
  _.unlock();
  t.join();
  return 0;
}
