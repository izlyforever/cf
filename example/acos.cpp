#include <bits/stdc++.h>
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

// https://github.com/ruuda/convector/blob/2f5f2428fa6c54002bd2ee8ce3d0f2188aab49f8/tools/approx_acos.py
// #max error:  0.0167244179117447796
float acosFast2(float x) {
  float xx = x * x;
  return 1.5707963267949f + x * (0.9217841528914573f * xx - 0.939115566365855f) / (1.0f + 0.295624144969963174f * xx * xx - 1.2845906244690837f * xx);
}
// https://stackoverflow.com/questions/3380628/fast-arc-cos-algorithm/36387954#36387954

// Handbook of Mathematical Functions by M. Abramowitz and I.A. Stegun, Ed.
// Absolute error <= 6.7e-5
float acosFast(float x) {
  bool flag = (x < 0);
  x = abs(x);
  float now = sqrt(1.0 - x) * (((0.0742610f - 0.0187293f * x) * x - 0.2121144f) * x + 1.5707288f);
  return flag ? 3.14159265358979f - now : now;
}
// Absolute error <= 6.7e-5
float asinFast(float x) {
  bool flag = (x < 0);
  x = abs(x);
  float now = sqrt(1.0 - x) * (((0.0742610f - 0.0187293f * x) * x - 0.2121144f) * x + 1.5707288f);
  return flag ? now - 1.5707963267949f : 1.5707963267949f - now;
}
// https://developer.download.nvidia.cn/cg

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
  const int N = 1e7;
  std::vector<double> x(N);
  std::uniform_real_distribution<double> unif(-1.0, 1.0);
  std::default_random_engine re;
  for (int i = 0; i < N; ++i) x[i] = unif(re);
  std::vector<double> ax(N), afx(N), atx(N), apfx(N), asx(N), asfx(N);
  {
    Timer A;
    for (int i = 0; i < N; ++i) ax[i] = acos(x[i]);
    A.show("acos");
  }
  init();
  {
    Timer A;
    for (int i = 0; i < N; ++i) atx[i] = arcCos(x[i]);
    A.show("acosTable");
  }
  {
    Timer A;
    for (int i = 0; i < N; ++i) apfx[i] = acosFast(x[i]);
    A.show("acosFast");
  }
  {
    Timer A;
    for (int i = 0; i < N; ++i) asx[i] = asin(x[i]);
    A.show("asin");
  }
  {
    Timer A;
    for (int i = 0; i < N; ++i) asfx[i] = asinFast(x[i]);
    A.show("asinFast");
  }
  for (int i = 0; i < N; ++i) afx[i] = abs(ax[i] - afx[i]);
  for (int i = 0; i < N; ++i) atx[i] = abs(ax[i] - atx[i] / 180 * __PI);
  for (int i = 0; i < N; ++i) apfx[i] = abs(ax[i] - apfx[i]);
  for (int i = 0; i < N; ++i) asfx[i] = abs(asx[i] - asfx[i]);
  cerr(*max_element(afx.begin(), afx.end()));
  cerr(*max_element(atx.begin(), atx.end()));
  cerr(*max_element(apfx.begin(), apfx.end()));
  cerr(*max_element(asfx.begin(), asfx.end()));
}

// Time used[acos]: 117ms
// Time used[acosTable]: 234ms
// Time used[acosFast]: 9ms
// Time used[asin]: 106ms
// Time used[asinFast]: 13ms
// *max_element(afx.begin(), afx.end()) is 0.0167799
// *max_element(atx.begin(), atx.end()) is 0.0174533
// *max_element(apfx.begin(), apfx.end()) is 6.77217e-05
// *max_element(asfx.begin(), asfx.end()) is 6.7678e-05