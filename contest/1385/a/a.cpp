#include <bits/stdc++.h>

int main(){
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    int x, y, z;
    std::cin >> x >> y >> z;
    if (x < y) std::swap(x,y);
    if (x < z) std::swap(x,z);
    if (y < z) std::swap(y,z);
    if (x > y) {
      std::cout << "NO" << std::endl;
    } else {
      std::cout << "YES" << std::endl;
      std::cout << x << " " << z << " " << z << std::endl;
    }
  }
  return 0;
}
