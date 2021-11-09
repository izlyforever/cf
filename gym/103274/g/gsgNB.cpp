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

class MexS {
  static inline const int B = 64; // submit use 64bit
  using ULL = unsigned long long;
  std::vector<LL> cnt_;
  std::vector<std::vector<ULL>> a_;
  int ans_;
 public: 
  // the answer is at most n
  MexS(int n) : cnt_(n + 1), ans_(-1) {
    int x = cnt_.size();
    while (x > B) {
      a_.emplace_back(std::vector<ULL>((x + B - 1) / B, -1ULL));
      x /= B;
    }
    a_.emplace_back(std::vector<ULL>{-1ULL});
  }
  void insert(int id) {
    if (id < 0 || id >= cnt_.size() || cnt_[id]++) return;
    if (id == ans_) ans_ = -1;
    for (auto &x : a_) {
      int tid = id / B;
      x[tid] ^= 1ULL << id - tid * B;
      if (x[tid]) return;
      id = tid;
    }
  }
  void erase(int id) { // make sure id in this set
    if (id < 0 || id >= cnt_.size() || --cnt_[id]) return;
    if (id <= ans_) ans_ = id;
    for (auto &x : a_) {
      int tid = id / B;
      x[tid] ^= 1ULL << id - tid * B;
      if (x[tid] != -1ULL) return;
      id = tid;
    }
  }
  int solve() {
    if (ans_ == -1) {
      ans_ = 0;
      for (auto it = a_.crbegin(); it != a_.crend(); ++it) {
        ans_ = ans_ * B + __builtin_ctzll((*it)[ans_]);
      }
    }
    return ans_;
  }
};

// 为了用 __builtin_ctzll, mask 中 0 表示有，1 表示无
int sg(int n, int m) {
  RingBuffer<int> A(m);
  A.insert(0);
  MexS S(m);
  A.insert(0);
  S.insert(0);
  int mex = 1;
  for (int i = 1; i <= n; ++i) {
    int x = A.getCurrent();
    if (__builtin_parity(i)) { // 这种不可能出现，但是 RingBuffer 要跑呀
      A.insert(-1);
    } else {
      mex = S.solve();
      A.insert(mex);
      S.insert(mex);
    }
    if (i >= m) S.erase(x);
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
 
class Timer {
  std::chrono::steady_clock::time_point start_;
 public:
  Timer() : start_(std::chrono::steady_clock::now()) {}
  void show() {
    auto elapsedTime = std::chrono::steady_clock::now() - start_;
    std::cerr << "Time used: " << elapsedTime.count() / 1'000'000 << "ms\n";
  }
};

int main() {
  //freopen("in", "r", stdin);
  Timer X;
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "Pay the bill" : "Free snacks!") << '\n';
  }
  X.show();
  return 0;
}