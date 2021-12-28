#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n'
using ULL = unsigned long long;


// O(N \log N) smalleset prime factor(may be faster)
std::vector<int> spfS(int N) {
  std::vector<int> sp(N);
  std::iota(sp.begin(), sp.end(), 0);
  for(int i = 2; i * i < N; ++i) if(sp[i] == i) {
    for(int j = i * i; j < N; j += i) if(sp[j] == j) {
      sp[j] = i;
    }
  }
  return sp;
}

// $O(N)$ smallest prime factor
std::vector<int> spf(int N) {
  std::vector<int> sp(N), p{0, 2};
  p.reserve(N);
  for (int i = 2; i < N; i += 2) sp[i] = 2;
  for (int i = 1; i < N; i += 2) sp[i] = i;
  for (int i = 3; i < N; i += 2) {
    if (sp[i] == i) p.emplace_back(i);
    for (int j = 2, np = (int)p.size(); j < np && p[j] <= sp[i] && i * p[j] < N; ++j) {
      sp[i * p[j]] = p[j]; // Note that sp[x] is assigned only once foreach x
    }
  }
  return sp;
}

std::mt19937_64 rnd64(std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
  int n;
  std::cin >> n;
  auto sp = spf(n + 1);
  std::vector<ULL> hsh(n + 1);
  for (int i = 2; i <= n; ++i) {
    if (sp[i] == i) {
      hsh[i] = rnd64();
    } else {
      hsh[i] = hsh[i / sp[i]] ^ hsh[sp[i]];
    }
  }
  ULL ans = 0;
  for (int i = n; i > 1; i -= 2) ans ^= hsh[i];
  if (ans == 0) {
    std::cout << n << '\n';
    for (int i = 1; i <= n; ++i) std::cout << i << " \n"[i == n];
    return;
  }
  std::map<ULL, int> mp;
  for (int i = 2; i <= n; ++i) hsh[i] ^= hsh[i - 1];
  for (int i = 1; i <= n; ++i) mp[hsh[i]] = i;

  if (auto it = mp.find(ans); it != mp.end()) {
    std::cout << n - 1 << '\n';
    for (int i = 1; i <= n; ++i) {
      if (i != it->second) std::cout << i << ' ';
    }
    std::cout << '\n';
    return;
  }

  for (int i = 2; i <= n; ++i) {
    ULL need = ans ^ hsh[i];
    auto it = mp.find(need);
    if (it != mp.end()) {
      std::cout << n - 2 << '\n';
      for (int j = 1; j <= n; ++j) {
        if (j != it->second && j != i) {
          std::cout << j << ' ';
        }
      }
      std::cout << '\n';
      return;
    }
  }

  assert(n % 4 == 3);
  std::cout << n - 3 << '\n';
  std::cout << 1;
  for (int i = 3; i < n; ++i) {
    if (i != n / 2) std::cout << ' ' << i;
  }
  std::cout << '\n';
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