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

template<typename T>
class BitreePlus {
  int n_;
  // c[i] = a[i] - a[i - 1], b_i = (i - 1) * c_i
  Bitree<T> B, C;
  void add(int id, T p) {
    C.add(id, p);
    B.add(id, (id - 1) * p);
  }
 public:
  BitreePlus() {}
  BitreePlus(int n) : n_(n), B(n), C(n) {}
  void add(int l, int r, T p) {
    add(l, p);
    add(r + 1, -p);
  }
  T sum(int id) { return id * C.sum(id) - B.sum(id); }
  T sum(int l, int r) { return sum(r) - sum(l - 1); }
  T at(int id) { return sum(id, id); }
  int lower_bound(T x) {
    int l = 1, r = n_;
    while (l <= r) {
      int m = (l + r) / 2;
      if (at(m) >= x) r = m - 1;
      else l = m + 1;
    }
    return l;
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
  for (int i = 0; i < n; ++i) {
    d[a[i] - 'a'].emplace_back(i);
  }
  std::vector<BitreePlus<int>> bitree(26);
  for (int i = 0; i < 26; ++i) {
    bitree[i] = BitreePlus<int>((int)d[i].size());
    for (int j = 0; j < (int)d[i].size(); ++j) {
      bitree[i].add(j + 1, j + 1, d[i][j]);
    }
  }
  std::vector<int> index(26, 1);
  LL ans = INT64_MAX, cur = 0;
  for (int i = 0; i < n; ++i) {
    if (cur >= ans) break;
    for (char j = 'a'; j < b[i]; ++j) {
      if (index[j - 'a'] <= d[j - 'a'].size()) {
        ans = std::min(ans, bitree[j - 'a'].at(index[j - 'a']) + cur - i);
      }
    }
    if (index[b[i] - 'a'] > d[b[i] - 'a'].size()) break;
    int j = bitree[b[i] - 'a'].at(index[b[i] - 'a']);
    ++index[b[i] - 'a'];
    cur += j - i;
    for (char c = 'a'; c <= 'z'; ++c) {
      int it = bitree[c - 'a'].lower_bound(j);
      if (index[c - 'a'] < it) bitree[c - 'a'].add(index[c - 'a'], it - 1, 1);
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
