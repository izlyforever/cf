#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
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

double acosFast(double x) {
  static const double halfPI = acos(0.0);
  static const double a = -0.939115566365855;
  static const double b = 0.9217841528914573;
  static const double c = -1.2845906244690837;
  static const double d = 0.295624144969963174;
  double xx = x * x;
  return halfPI + x * (a + b * xx) / (1.0 + c * xx + d * xx * xx);
}
 
#define COS_TABLE_SIZE 181
#define __PI 3.14159265

static double cosTable[COS_TABLE_SIZE];

void init() {
  for (int i = 0; i < COS_TABLE_SIZE; ++i) {
    cosTable[i] = cos(static_cast<double>(i) * __PI / 180.0);
  }
}

int arcCos(double cos) {
  int l = 0;
  int r = COS_TABLE_SIZE - 1;
  int m = 0;
  while (l < r) {
    m = (l + r) / 2;
    // table is in descend order
    if (cosTable[m] > cos) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return r;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  const int N = 1e7;
  std::vector<double> x(N);
  std::uniform_real_distribution<double> unif(-1.0, 1.0);
  std::default_random_engine re;
  for (int i = 0; i < N; ++i) x[i] = unif(re);
  std::vector<double> ax(N), afx(N), atx(N);
  {
    Timer A;
    for (int i = 0; i < N; ++i) ax[i] = acos(x[i]);
    A.show("acos");
  }
  {
    Timer A;
    for (int i = 0; i < N; ++i) afx[i] = acosFast(x[i]);
    A.show("acosFast");
  }
  init();
  {
    Timer A;
    for (int i = 0; i < N; ++i) atx[i] = arcCos(x[i]);
    A.show("acosTable");
  }
  for (int i = 0; i < N; ++i) afx[i] = abs(ax[i] - afx[i]);
  for (int i = 0; i < N; ++i) atx[i] = abs(ax[i] - atx[i] / 180 * __PI);
  cerr(*max_element(afx.begin(), afx.end()));
  cerr(*max_element(atx.begin(), atx.end()));
}
