#include <bits/stdc++.h>
using LL = long long;

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::string s;
    std::cin >> s;
    int n = s.size();
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) a[i] = std::string("ANOT").find(s[i]);
    std::vector<int> p{0, 1, 2, 3}, cnt(4);
    for (auto x : a) ++cnt[x];
    std::vector<std::vector<int>> sum(4, std::vector<int>(n));
    for (int i = 0; i < 4; ++i) {
      int now = 0;
      for (int j = 0; j < n; ++j) {
        if (a[j] == i) ++now;
        sum[i][j] = now;
      }
    }
    LL mx = -1;
    std::string ans;
    do {
      LL t = 0;
      std::vector<int> rp(4);
      for (int i = 0; i < 4; ++i) rp[p[i]] = i;
      for (int j = 0; j < n; ++j) {
        for (int i = rp[a[j]] + 1; i < 4; ++i) {
          t += sum[p[i]][j];
        }
      }
      if (t > mx) {
        mx = t;
        ans.clear();
        for (auto x : p) ans += std::string(cnt[x], "ANOT"[x]);
      }
    } while (std::next_permutation(p.begin(), p.end()));
    std::cout << ans << '\n';
  }
  return 0;
}