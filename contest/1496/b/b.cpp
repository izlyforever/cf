#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  std::set<int> S;
  for (auto& x : a) {
    std::cin >> x;
    S.insert(x);
  }
  int mex = 0;
  while (S.count(mex)) ++mex;
  if (k == 0 || *S.rbegin() < mex) return S.size() + k;
  S.insert((mex + *S.rbegin() + 1) / 2);
  return S.size();
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << solve() << "\n";
  }
  return 0;
}