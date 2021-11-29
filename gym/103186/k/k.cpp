#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::map<std::vector<int>, int> sg;
  std::function<int(std::vector<int>)> dfs = [&](const std::vector<int>& a) -> int {
    std::vector<int> b;
    for (auto x : a) if (x) b.emplace_back(x);
    std::sort(b.begin(), b.end());
    if (sg.count(b)) return sg[b];
    std::set<int> S;
    for (int i = 1, nb = b.size(); i < nb; ++i) {
      for (int j = 0; j < i; ++j) {
        --b[i];
        --b[j];
        S.insert(dfs(b));
        ++b[i];
        ++b[j];
      }
    }
    for (auto& x : b) {
      --x;
      S.insert(dfs(b));
      ++x;
    }
    int ans = 0;
    while (S.count(ans)) ++ans;
    return sg[b] = ans;
  };
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      std::string s;
      std::cin >> s;
      int cnt[26]{};
      for (auto x : s) ++cnt[x - 'a'];
      std::vector<int> a;
      for (int i = 0; i < 26; ++i) if (cnt[i]) a.emplace_back(cnt[i]);
      ans ^= dfs(a);
    }
    std::cout << (ans ? "Alice" : "Bob") << '\n';
  }
  return 0;
}