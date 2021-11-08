#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

int bitCount0(unsigned x) {
  static const unsigned mask = 0x01010101;
  return  ((mask & x) + (mask & (x >> 1))
  + (mask & (x >> 2)) + (mask & (x >> 3))
  + (mask & (x >> 4)) + (mask & (x >> 5))
  + (mask & (x >> 6)) + (mask & (x >> 7))) % 255;
}

int bitCount1(unsigned x) {
  static const unsigned mask = 010101010101;
  return  ((mask & x) + (mask & (x >> 1))
  + (mask & (x >> 2)) + (mask & (x >> 3))
  + (mask & (x >> 4)) + (mask & (x >> 5))) % 63;
}

int bitCount2(unsigned x) {
  static const unsigned mask = 011111111111;
  unsigned tmp = (mask & x) + (mask & (x >> 1)) + (mask & (x >> 2));
  return  ((tmp + (tmp >> 3)) & 030707070707) % 63;
}

int bitCount(unsigned n) {
  unsigned tmp = n - ((n >> 1) & 033333333333) - ((n >> 2) & 011111111111);
  return ((tmp + (tmp >> 3)) & 030707070707) % 63;
}

// MIT HAKMEM: about two times faster than __builtin_popcountll(), run with 64bit
int bitCountll(unsigned long long n) {
  unsigned long long tmp = n - ((n >> 1) & 0x7777777777777777ULL)
                             - ((n >> 2) & 0x3333333333333333ULL)
                             - ((n >> 3) & 0x1111111111111111ULL);
  return ((tmp + (tmp >> 4)) & 0x0f0f0f0f0f0f0f0fULL) % 255;
}
// https://www.cnblogs.com/lukelouhao/archive/2012/06/12/2546267.html

// faster than bitCount
int bitCountTable(unsigned n) { 
  static int table[256] =  { 
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
    3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 
    4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8, 
  }; 
  return table[n & 0xff] + table[(n >> 8) & 0xff] +
         table[(n >> 16) & 0xff] + table[n >> 24];
}
// slow than bitCountll
int bitCountTableLL(unsigned long long n) {
  return bitCountTable(n >> 32) + bitCountTable(n & 0xffffffff);
}
// https://www.cnblogs.com/graphics/archive/2010/06/21/1752421.html

bool solve() {
  int n, m;
  std::cin >> n >> m;
  int last = 0; // 我们需要记录最后一个为 0 的值
  // for (int i = 1; i <= n; ++i) if (bitCount(i) % 2 == 0) {
  for (int i = 1; i <= n; ++i) if (!__builtin_parity(i)) {
    if (i - m > last) last = i;
  }
  return last != n;
}

class Timer {
  std::chrono::steady_clock::time_point start_;
 public:
  Timer() : start_(std::chrono::steady_clock::now()) {}
  void show() {
    auto elapsedTime = std::chrono::steady_clock::now() - start_;
    std::cerr << "Time used: " << elapsedTime.count() / 1'000'000 << "ms\n";
  }
};

int main() {
  //freopen("in", "r", stdin);
  Timer X;
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Pay the bill" : "Free snacks!") << '\n';
  }
  X.show();
  return 0;
}