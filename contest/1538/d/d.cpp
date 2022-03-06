#include <bits/stdc++.h>
using LL = long long;

const int N = 1e5 + 2;
bool isp[N];
// 此算法复杂度为 O(N \log \log N)，实测 N < 1e9 时是最快的
std::vector<int> initPrime() {
  std::vector<int> p{0, 2};
  isp[2] = true;
  for (int i = 3; i < N; i += 2) isp[i] = true;
  int sq = int(std::sqrt(N + 0.1)) | 1;
  for (int i = 3; i <= sq; i += 2) if (isp[i]) {
    p.emplace_back(i);
    for (int j = i * i; j < N; j += i << 1) isp[j] = false;
  }
  for (int i = sq + 2; i < N; i += 2) if (isp[i]) p.emplace_back(i);
  return p;
}
auto p = initPrime();
int d(int n) {
  int ans = 0;
  for (int i = 1; p[i] * p[i] <= n; ++i) {
    while (n % p[i] == 0) n /= p[i], ++ans;
  }
  return ans + (n > 1);
}

bool solve() {
  int a, b, k;
  std::cin >> a >> b >> k;
  if (k == 1) return ((a % b == 0 || b % a == 0) && a != b);
  return d(a) + d(b) >= k;
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    std::cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}
