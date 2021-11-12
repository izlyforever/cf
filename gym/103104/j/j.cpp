#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

// 抄一下 cxy004 的做法（用复数在处理几乎问题也太帅了吧）：
LL divAbs(LL x, LL y) {
  LL d = x / y, r = x - d * y;
  // 相当于按照余数绝对值最小来除
  if (2 * r >= y) ++d;
  else if (2 * r <= -y) --d; // 这里是注意到负数的除法是向 0 取余
  return d;
}
using CL = std::complex<LL>;
CL divCAbs(CL x, CL y) { // 这就是标准的两个复数除法
  x *= std::conj(y);
  LL normY = std::norm(y);
  return {divAbs(x.real(), normY), divAbs(x.imag(), normY)};
}
CL gcd(CL x, CL y) {
  return std::norm(y) == 0 ? x : gcd(y, x - divCAbs(x, y) * y);
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    LL x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    std::complex<LL> x(x2 - x1, y2 - y1), y(x3 - x1, y3 - y1);
    auto d = gcd(x, y);
    x = divCAbs(x, d);
    y = divCAbs(y, d);
    std::cout << "0 0 " << x.real() << ' ' << x.imag() << ' ' << y.real() << ' ' << y.imag() << '\n';
  }
  return 0;
}