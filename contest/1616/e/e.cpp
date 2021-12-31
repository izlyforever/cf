#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;

template<typename T>
struct Bitree {
  std::vector<T> s_;
  Bitree() {}
  Bitree(int n) : s_(n + 1) {}
  int lowbit(int n) { return n & (-n); }
  void add(int id, T p) {
    int ns = s_.size();
    while (id < ns) {
      s_[id] += p;
      id += lowbit(id);
    }
  }
  T sum(int id) {
    T r = 0;
    while (id) {
      r += s_[id];
      id -= lowbit(id);
    }
    return r;
  }
};

LL solve() {
  int n;
  std::string a, b;
  std::cin >> n >> a >> b;
  std::vector<int> cnt(26);
  for (int i = 0; i < n; ++i) ++cnt[a[i] - 'a'];
  std::vector<std::vector<int>> d(26);
  for (int i = 0; i < 26; ++i) d[i].reserve(cnt[i]);
  for (int i = n - 1; i >= 0; --i) {
    d[a[i] - 'a'].emplace_back(i);
  }
  Bitree<int> bitree(n);
  LL ans = INT64_MAX, cur = 0;
  for (int i = 0; i < n; ++i) {
    if (cur >= ans) break;
    for (char j = 'a'; j < b[i]; ++j) {
      int id = j - 'a';
      if (!d[id].empty()) {
        ans = std::min(ans, cur + d[id].back() + bitree.sum(n - d[id].back()) - i);
      }
    }
    int bi = b[i] - 'a';
    if (d[bi].empty()) break;
    cur += d[bi].back() + bitree.sum(n - d[bi].back()) - i;
    bitree.add(n - d[bi].back(), 1);
    d[bi].pop_back();
  }
  return ans == INT64_MAX ? -1 : ans;
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
