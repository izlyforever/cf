#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

struct Bitree {
  std::vector<LL> s;
  Bitree() {}
  Bitree(int n) { init(n); }
  void init(int n) {
    s.resize(n + 1);
    std::fill(s.begin(), s.end(), 0);
  }
  int lowbit(int n) {
    return n & (-n);
  }
  void add(int id, int p) {
    while (id < s.size()) {
      s[id] += p;
      id += lowbit(id);
    }
  }
  LL sum(int id) {
    LL r = 0;
    while (id) {
      r += s[id];
      id -= lowbit(id);
    }
    return r;
  }
  // find minimal index s.t. sum(id) >= x, sum must be increased
  int search(LL val) {
    LL sum = 0;
    int id = 0;
    for (int i = std::__lg(s.size()); ~i; --i) {
      if (id + (1 << i) < s.size() && sum + s[id + (1 << i)] < val) {
        id += (1 << i);
        sum += s[id];
      }
    }
    return ++id;
  }
};

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  std::string s;
  std::cin >> n >> s;
  std::vector<int> tmp[26];
  int now = 0;
  for (int i = s.size() - 1; i >= 0; --i) tmp[s[i] - 'a'].emplace_back(++now);
  // for (int i = 0; i < 26; ++i) if (tmp[i].size()) {
  //   for (auto x : tmp[i]) std::cout << x << " ";
  //   char t = 'a' + i;
  //   print(t);
  // }
  std::vector<int> a(n + 1), p(n + 1);
  for (int i = n; i > 0; --i) {
    a[i] = tmp[s[i - 1] - 'a'].back();
    tmp[s[i - 1] - 'a'].pop_back();
  }
  for (int i = 1; i <= n; ++i) p[a[i]] = i;
  Bitree A(n);
  LL r = 0;
  for (int i = n; i > 0; --i) {
    r += A.sum(p[i]);
    A.add(p[i], 1);
  }
  print(r);
  return 0;
}
