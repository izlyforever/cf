#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl;
using LL = long long;

int main() {;
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int a, b, c, d;
    std::cin >> a >> b >> c >> d;
    int f1 = a + d;
    int f2 = b + c;
    int f3 = (a + b) % 2;
    if (f3) {
      std::cout << (f1 ? "Ya " : "Tidak ");
      std::cout << (f2 ? "Ya " : "Tidak ");
      std::cout << "Tidak Tidak";
    } else {
      std::cout << "Tidak Tidak ";
      std::cout << (f2 ? "Ya " : "Tidak ");
      std::cout << (f1 ? "Ya" : "Tidak");
    }
    println;
  }
  return 0;
}
