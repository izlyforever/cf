#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

template<typename T>
class RingBuffer {
  int m_, id_;
  std::vector<T> a_;
 public: 
  RingBuffer(int m) : m_(m), id_(0), a_(m, -1) {};
  T getCurrent() const {
    return a_[id_];
  }
  void insert(T x) {
    a_[id_++] = x;
    if (id_ == m_) id_ = 0;
  }
};

// m <= 64，为了用 __builtin_ctzll, mask 中 0 表示有，1 表示无
int sg(int n, int m) {
  RingBuffer<int> A(m);
  std::vector<int> cnt(m + 1);
  A.insert(0);
  ++cnt[0];
  unsigned long long mask = -1ULL ^ 1;
  int mex = 1;
  for (int i = 1; i <= n; ++i) {
    int x = A.getCurrent();
    if (__builtin_parity(i)) { // 这种不可能出现，但是 RingBuffer 要跑呀
      A.insert(-1);
    } else {
      mex = __builtin_ctzll(mask);
      A.insert(mex);
      if (cnt[mex]++ == 0) mask ^= 1ULL << mex;
    }
    if (i >= m && x != -1) {
      if (--cnt[x] == 0) mask |= 1ULL << x;
    }
  }
  return mex;
}

bool solve() {
  int k = 1;
  // std::cin >> k;
  int ans = 0;
  for (int i = 0; i < k; ++i) {
    int n, m;
    std::cin >> n >> m;
    ans ^= sg(n, m);
  }
  return ans;
}
 
int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Pay the bill" : "Free snacks!") << '\n';
  }
  return 0;
}