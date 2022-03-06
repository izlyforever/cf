#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto& x : a) std::cin >> x;
  auto f = [&]() -> std::vector<int> {
    std::vector<int> pre(n, -1);
    std::stack<int> Q;
    for (int i = 0; i < n; ++i) {
      while (!Q.empty() && a[Q.top()] >= a[i]) Q.pop();
      if (!Q.empty()) pre[i] = Q.top();
      Q.push(i);
    }
    return pre;
  };
  auto g = [&]() -> std::vector<int> {
    std::vector<int> nxt(n, n);
    std::stack<int> Q;
    for (int i = n - 1; i >= 0; --i) {
      while (!Q.empty() && a[Q.top()] >= a[i]) Q.pop();
      if (!Q.empty()) nxt[i] = Q.top();
      Q.push(i);
    }
    return nxt;
  };
  auto pre = f(), suf = g();
  std::vector<LL> b(n), c(n);
  for (int i = 0; i < n; ++i) {
    b[i] = LL(i - pre[i]) * a[i] + (pre[i] == -1 ? 0 : b[pre[i]]);
  }
  for (int i = n - 1; i >= 0; --i) {
    c[i] = LL(suf[i] - i) * a[i] + (suf[i] == n ? 0 : c[suf[i]]);
  }
  LL r = 0;
  int id = 0;
  for (int i = 0; i < n; ++i) {
    if (b[i] + c[i] - a[i] > r) {
      r = b[i] + c[i] - a[i];
      id = i;
    }
  }
  for (int i = id; i != -1; i = pre[i]) {
    for (int j = i - 1; j != pre[i]; --j) a[j] = a[i];
  }
  for (int i = id; i != n; i = suf[i]) {
    for (int j = i + 1; j != suf[i]; ++j) a[j] = a[i];
  }
  for (int i = 0; i < n; ++i) std::cout << a[i] << " \n"[i == n - 1];
  return 0;
}
