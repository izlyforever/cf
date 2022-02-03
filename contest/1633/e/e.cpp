#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using LL = long long;
const int N = 1e8 + 2;
std::bitset<N> bs;

struct Node {
  int x, y, w, val;
  bool operator<(const Node& A) const {
    return val > A.val;
  }
};

std::vector<int> Prim(std::vector<Node>& e, int n, int z) {
  for (auto& [x, y, w, val] : e) val = abs(w - z);

  std::vector<int> ans, p(n);
  std::iota(p.begin(), p.end(), 0);
  std::function<int(int)> find = [&](int x) {
    return x == p[x] ? x : p[x] = find(p[x]);
  };

  std::priority_queue<Node> Q(e.begin(), e.end());
  while (!Q.empty()) {
    auto [x, y, w, val] = Q.top();
    Q.pop();
    int fx = find(x), fy = find(y);
    if (fx != fy) {
      ans.emplace_back(w);
      p[fx] = fy;
    }
  }
  assert(ans.size() == n - 1);
  return ans;
}

void solve() {
  int n, m, sz;
  std::cin >> n >> m;
  std::vector<Node> e(m);
  std::vector<int> a;
  {
    std::set<int> tmp;
    for (auto &[x, y, w, val] : e) {
      std::cin >> x >> y >> w;
      --x; --y;
      tmp.insert(w);
    }
    sz = (int)tmp.size();
    std::vector<int> aa(tmp.begin(), tmp.end());
    tmp.clear();
    for (int i = 0; i < sz; ++i) {
      for (int j = i + 1; j < sz; ++j) {
        int x = (aa[i] + aa[j]) / 2;
        if (x * 2 == aa[i] + aa[j]) {
          tmp.insert(x - 1);
        }
        tmp.insert(x);
      }
    }
    a = std::vector<int>(tmp.begin(), tmp.end());
    a.emplace_back(N);
    sz = (int)a.size();
  }
  std::vector<std::vector<int>> ans(sz);
  for (int i = 0; i < sz; ++i) {
    ans[i] = Prim(e, n, a[i]);
  }
  {
    int p, k, a, b, c, x = 0;
    std::cin >> p >> k >> a >> b >> c;
    for (int i = 0; i < p; ++i) {
      std::cin >> x;
      bs[x] = !bs[x];
    }
    for (int i = p; i < k; ++i) {
      x = (1LL * x * a + b) % c;
      bs[x] = !bs[x];
    }
  }
  LL r = 0;
  for (int i = 0, j = 0; i < N; ++i) if (bs[i]) {
    while (a[j] < i) ++j;
    auto& w = ans[j];
    LL sum = 0;
    for (auto x : w) sum += abs(x - i);
    r ^= sum;
  }
  std::cout << r << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  // std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}
