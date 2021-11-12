#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;
using namespace std;

void solve() {
#if defined(__FAST_MATH__)
  cout << "fast math mode" << endl;
#else
  cout << "NOT fast math mode" << endl;
#endif
  cout << "isnan(NaN) = " << std::isnan(NAN) << '\n'
              << "isnan(Inf) = " << std::isnan(INFINITY) << '\n'
              << "isnan(0.0) = " << std::isnan(0.0) << '\n';

  cout << "NAN == NAN:" << (NAN == NAN) << '\n'
       << "NAN != NAN:" << (NAN != NAN) << '\n'
       << "NAN > NAN:" << (NAN > NAN) << '\n'
       << "NAN < NAN:" << (NAN < NAN) << '\n'
       << "NAN < 0.1:" << (NAN < 0.1f) << '\n'
       << "NAN > 0.1:" << (NAN > 0.1f) << '\n';

    cout << "mynan(NaN) = " << mynan(NAN) << '\n';

}

class Timer {
  std::chrono::high_resolution_clock::time_point start;
 public:
  Timer() : start(std::chrono::high_resolution_clock::now()) {}
  void show(std::string s = {}) {
    auto elapsedTimeNs = (std::chrono::high_resolution_clock::now() - start).count();
    std::cerr << "[Time used: " << s << "] " << elapsedTimeNs / 1'000'000.0 << "ms\n";
  }
};

int main() {
  Timer A;
  cerr(__PRETTY_FUNCTION__);
  solve();
  cerr(__COUNTER__);
  cerr(__COUNTER__);
  cerr(__COUNTER__);
  cerr(__COUNTER__);
  // this_thread::sleep_for(std::chrono::milliseconds(111483));
  A.show();
  return 0;
}