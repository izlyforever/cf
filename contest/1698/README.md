# [Codeforces Round #803 (Div. 2)](https://codeforces.com/contest/1698)

> 好好读题很难吗

## A

任选一项都是答案

## B

读题读错了，以为 $k$ 个连续的 1 总要找个地方放下，写起来老恶心了，还是写的太少，哎

``` cpp
#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (auto &x : a) std::cin >> x;

  auto chk = [&](int i) {
    return i > 0 && i + 1 < n && a[i] > a[i - 1] + a[i + 1];
  };
  auto chkEq = [&](int i) {
    return i > 0 && i + 1 < n && a[i] == a[i - 1] + a[i + 1];
  };

  int ans = 0;
  if (k == 1) {
    for (int i = 0; i < n; ++i) if (chk(i)) ++ans;
    for (int i = 0; i < n; ++i) if (chkEq(i)) return ++ans;
    return ans;
  }
  for (int i = 0; i < k; ++i) ++a[i];
  for (int i = 0; i < n; ++i) if (chk(i)) ++ans;
  int now = ans;
  for (int i = 1; i + k - 1 < n; ++i) {
    now -= chk(i - 2) + chk(i - 1) + chk(i) + chk(i + k - 2) + chk(i + k - 1) + chk(i + k);
    ++a[i + k - 1];
    --a[i - 1];
    now += chk(i - 2) + chk(i - 1) + chk(i) + chk(i + k - 2) + chk(i + k - 1) + chk(i + k);
    ans = std::max(ans, now);
  }
  return ans;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << '\n';
  }
  return 0;
}
```

## C

注意到超过 2 个正数 或者超过 2 个负数 出现，都不可能。然后再注意到超过 2 个 0，多出来的 0 没有意义，剩下的直接暴力即可

## D

这显然是二分查找，注意到查询 $[l, r]$ 时不在这个区间的数必然不是答案，然后我们只需看在这个区间的数的奇偶性就可以知道答案在哪个区间

