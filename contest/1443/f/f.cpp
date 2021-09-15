#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

const LL M = 998244353;
int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n), left(n), right(n), b(k), p(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      --a[i];
      p[a[i]] = i;
    }
    std::map<int, int> mp;
    for (auto& x : b) {
      std::cin >> x;
      --x;
      ++mp[x];
    }
    for (int i = 0; i < n; ++i) left[i] = i - 1, right[i] = i + 1;
    LL r = 1;
    for (int i = 0; i < k; ++i) {
      int now = p[b[i]], t = 0;
      bool fl = left[now] >= 0 && mp[a[left[now]]] == 0;
      bool fr = right[now] < n && mp[a[right[now]]] == 0;
      if (!fl && !fr) {
        r = 0;
        break;
      } else if (fl && fr) {
        r = r * 2 % M;
        int t = left[left[now]];
        left[now] = left[left[now]];
        if (t >= 0) right[t] = now;
      } else if (fl) {
        int t = left[left[now]];
        left[now] = left[left[now]];
        if (t >= 0) right[t] = now;
      } else {
        int t = right[right[now]];
        right[now] = t;
        if (t < n) left[t] = now;
      }
      --mp[b[i]];
      // watch(r);
    }
    std::cout << r << std::endl;
  }
  return 0;
}