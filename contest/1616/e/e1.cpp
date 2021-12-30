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
  // find minimal index s.t. sum(id) >= x, sum must be increased
  int search(T val) {
    T sum = 0;
    int id = 0;
    for (int i = std::__lg(s_.size()); ~i; --i) {
      if (id + (1 << i) < (int)s_.size() && sum + s_[id + (1 << i)] < val) {
        id += (1 << i);
        sum += s_[id];
      }
    }
    return ++id;
  }
};

LL solve() {
  int n;
  std::string a, b;
  std::cin >> n >> a >> b;
  if (a < b) return 0;
  {
    auto c = a;
    std::sort(c.begin(), c.end());
    if (c >= b) return -1;
  }
  std::vector<std::vector<int>> d(26);
  std::vector<int> last(26);
  for (int i = 0; i < n; ++i) {
    int id = a[i] - 'a';
    d[id].emplace_back(i - last[id]);
    last[id] = i;
  }
  std::vector<Bitree<int>> bitree(26);
  for (int i = 0; i < 26; ++i) {
    bitree[i] = Bitree<int>((int)d[i].size());
    for (int j = 0; j < (int)d[i].size(); ++j) {
      bitree[i].add(j + 1, d[i][j]);
    }
  }
  std::vector<int> index(26, 1);
  LL ans = INT64_MAX, cur = 0;
  for (int i = 0; i < n; ++i) {
    if (cur >= ans) break;
    for (char j = 'a'; j < b[i]; ++j) {
      int id = j - 'a';
      if (index[id] <= d[id].size()) {
        ans = std::min(ans, bitree[id].sum(index[id]) + cur - i);
      }
    }
    int bi = b[i] - 'a';
    if (index[bi] > d[bi].size()) break;
    int j = bitree[bi].sum(index[bi]);
    ++index[bi];
    cur += j - i;
    for (char c = 'a'; c <= 'z'; ++c) {
      int id = c - 'a';
      int it = bitree[id].search(j);
      if (index[id] < it) {
        bitree[id].add(index[id], 1);
        bitree[id].add(it, -1);
      }
    }
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
