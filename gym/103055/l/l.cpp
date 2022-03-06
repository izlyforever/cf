#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::string s;
  std::cin >> s;
  for (int i = 1; i < n; ++i) if (s[i] == s[0]) {
    std::cout << "Wrong Answer\n";
    return 0;
  }
  std::cout << "Correct\n";
  return 0;
}
