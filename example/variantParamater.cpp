#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

void write2(int level, const char* fmt, ...) {
}

void write(int level, const char* fmt, ...) {
  if (!fmt || !*fmt) {
    return;
  }
  va_list ap;
  va_start(ap, fmt);
  auto size = vsnprintf(nullptr, 0, fmt, ap);
  va_end(ap);
  if (size <= 0) {
    return;
  }
  write2(level, ap);
}

void solve() {
  write(12, "%d", 13);
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
