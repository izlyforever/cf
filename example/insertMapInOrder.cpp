#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

class Timer {
  std::chrono::steady_clock::time_point start;
 public:
  Timer() : start(std::chrono::steady_clock::now()) {}
  void show(std::string s = {}) {
    auto elapsedTime = std::chrono::steady_clock::now() - start;
    std::cerr << "Time used[" << s << "]: " << elapsedTime.count() / 1000000 << "ms\n";
  }
};
std::mt19937_64 rnd64(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  const int N = 1e7 + 2;
  using ULL = unsigned long long;
  std::vector<LL> a(N);
  std::iota(a.begin(), a.end(), 0);
  auto b = a;
  std::reverse(b.begin(), b.end());

  {
    Timer A;
    std::set<int> mp;
    for (auto &x : a) mp.insert(x);
    cerr(mp.size());
    A.show("decrease on by one");
  }

  {
    Timer A;
    std::set<int> mp;
    for (auto &x : b) mp.insert(x);
    cerr(mp.size());
    A.show("decrease on by on");
  }

  {
    Timer A;
    std::set<int> mp(a.begin(), a.end());
    cerr(mp.size());
    A.show("increase");
  }

  {
    Timer A;
    std::set<int> mp(b.begin(), b.end());
    cerr(mp.size());
    A.show("decrease");
  }

  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(a.begin(), a.end(), g);
  {
    Timer A;
    std::set<int> mp(a.begin(), a.end());
    cerr(mp.size());
    A.show("shuffle");
  }
  {
    Timer A;
    std::set<int> mp;
    for (auto &x : a) mp.insert(x);
    cerr(mp.size());
    A.show("shuffle on by one");
  }
}

// 挺不能接受的，为什么一个个的丢比整个的丢快，而且两个顺序还是反的
// mp.size() is 10000002
// Time used[decrease on by one]: 1073ms
// mp.size() is 10000002
// Time used[decrease on by on]: 913ms
// mp.size() is 10000002
// Time used[increase]: 948ms
// mp.size() is 10000002
// Time used[decrease]: 1202ms
// mp.size() is 10000002
// Time used[shuffle]: 7941ms
// mp.size() is 10000002
// Time used[shuffle on by one]: 7682ms
