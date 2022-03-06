#include <bits/stdc++.h>
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  int ans = 1;
  for (int i = 1, j = 0; i < n && s[i] <= s[j]; ++i) {
    if (s[i] < s[j] || ++j == ans) {
      ans = i + 1;
      j = 0;
    }
  }
  for (int i = 0, j = 0; i < k; ++i, ++j) {
    if (j == ans) j = 0;
    std::cout << s[j];
  }
  std::cout << '\n';
  return 0;
}
