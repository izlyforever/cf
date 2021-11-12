#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::string s;
    std::cin >> n >> s;
    int s1 = std::count(s.begin(), s.end(), '1');
    if (s[0] == '0' || s.back() == '0' || s1 % 2) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      std::string a(s.size(), '('), b(s.size(), '(');
      a.back() = b.back() = ')';
      int p0 = -1;
      for (int i = 0; i < s.size(); ++i) if (s[i] == '0') {
        if (p0 == -1) p0 = i;
        else {
          a[p0] = b[i] = ')';
          p0 = -1;
        }
      }
      s1 /= 2;
      for (int i = 0; i < s.size(); ++i) if (s[i] == '1') {
        if (s1) {
          a[i] = b[i] = '(';
          --s1;
        } else {
          a[i] = b[i] = ')';
        }
      }
      std::cout << a << '\n';
      std::cout << b << '\n';
    }
  }
  return 0;
}