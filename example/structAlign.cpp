#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

#if defined(_MSC_VER)
#define _ALIGN(x) __declspec(align(x))
#define __PRETTY_FUNCTION__ __FUNCTION__
#elif defined(__GNUC__) || defined(__clang__)
#define _ALIGN(x) __attribute__((__aligned__(x)))
#else
#error "unsupported compiler"
#endif

struct AlignTest {
  uint64_t time_stamp;

  _ALIGN(8) const char* name;

  uint32_t event : 8;
  // Count of arguments

  uint32_t argc : 2;

  // Reserved bites for future usage and compatibility
  uint32_t reserved : 22;
};

struct Node1 {
  uint16_t c;
  uint8_t a;
};

struct Node2 {
  uint8_t a;
  uint16_t c;
};

struct structAlign {
  uint32_t b;
  Node1 x;
  Node2 y;
  uint16_t c;
};

#pragma pack(1)
struct structAlign1 {
  uint32_t b;
  Node1 x;
  Node2 y;
  uint16_t c;
};
#pragma pack()

void solve() {
  cerr(sizeof (AlignTest));  // 24
  cerr(sizeof (Node1));  // 4
  cerr(sizeof (Node2));  // 4
  cerr(sizeof (structAlign));  // 16
  cerr(sizeof (structAlign1)); // 14

  std::cout << "Please input a integer!" << std::endl;
  AlignTest A{};
  int x;
  std::cin >> x;
  // is equivalence to A.argc = x & ((1 << lengthOf(argc)) - 1)
  A.argc = x;
  cerr(A.event);
  cerr(A.argc);
  cerr(A.reserved);
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
