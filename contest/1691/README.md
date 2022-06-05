# [CodeCraft-22 and Codeforces Round #795 (Div. 2)](https://codeforces.com/contest/1691)

## A

奇数和偶数个数的最小值

## B

相同元素个数都大于 1 即可

## C

显然中间的 1 对答案贡献是 11，左边的 1 贡献 10，右边的 1 贡献 1。因此优先把 1 移动到最右边，还有多余的 1 就再移动到最左边

## D

看上去是要用单调栈的，但是没看出来怎么对没个区间处理。然后用了一个很水的做法，PE，最后竟然没 FST，服了

被自己的一下代码 hack 了 <https://codeforces.com/contest/1691/submission/159068891>

``` cpp
#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cout << 1 << '\n';
  int n = 2e5;
  std::cout << n << '\n';
  std::cout << 2 << ' ' << -1 << ' ' << 2 << ' ' << -3;
  for (int i = 4; i < n; i += 2) {
    std::cout << ' ' << i / 2 << ' ' << -(i / 2);
  }
  std::cout << '\n';
  return 0;
}
```

## E

区间 DSU
