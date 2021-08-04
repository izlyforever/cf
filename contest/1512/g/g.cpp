#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  const int N = 1e7 + 2;
  std::vector<int> a(N), r(N, -1);
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      a[j] += i;
    }
  }
  // watch(*std::max_element(a.begin(), a.end()));
  for (int i = N - 1; i > 0; --i) if (a[i] < N) r[a[i]] = i;
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::cout << r[n] << '\n';
  }
  return 0;
}