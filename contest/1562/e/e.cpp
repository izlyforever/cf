#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// suffix array: SA-IS in O(N)
// assume a.back() = 0 and other elements are small postiove integral
std::vector<int> SAIS(std::vector<int> a) {
  enum TYPE {L, S};
  int n = a.size() - 1, mx = *std::max_element(a.begin(), a.end()) + 1;
  std::vector<int> SA(n + 1, -1);
  std::vector<int> bucket(mx), lbucket(mx), sbucket(mx);
  for (auto x : a) ++bucket[x];
  for (int i = 1; i < mx; ++i) {
    bucket[i] += bucket[i - 1];
    lbucket[i] = bucket[i - 1];
    sbucket[i] = bucket[i] - 1;
  }
  // Determine the type of L, S and the position of type *
  std::vector<TYPE> type(n + 1);
  type[n] = S;
  for (int i = n - 1; i >= 0; --i) {
    type[i] = (a[i] < a[i + 1] ? S : (a[i] > a[i + 1] ? L : type[i + 1]));
  }
  // induce sort(from type * induces type L, from type L induce type S)
  auto inducedSort = [&]() {
    for (int i = 0; i <= n; ++i) {
      if (SA[i] > 0 && type[SA[i] - 1] == L) {
        SA[lbucket[a[SA[i] - 1]]++] = SA[i] - 1;
      }
    }
    for (int i = 1; i < mx; ++i) {
      sbucket[i] = bucket[i] - 1;
    }
    for (int i = n; i >= 0; --i) {
      if (SA[i] > 0 && type[SA[i] - 1] == S) {
        SA[sbucket[a[SA[i] - 1]]--] = SA[i] - 1;
      }
    }
  };
  // sort LMS-prefix according to induce sort
  std::vector<int> pos;
  for (int i = 1; i <= n; ++i) {
    if (type[i] == S && type[i - 1] == L) {
      pos.emplace_back(i);
    }
  }
  for (auto x : pos) SA[sbucket[a[x]]--] = x;
  inducedSort();
  // Give a name of LMS-substring(thus is S1) according to the order of LMS-prefix
  auto isLMSchar = [&](int i) {
    return i > 0 && type[i] == S && type[i - 1] == L;
  };
  auto equalSubstring = [&](int x, int y) {
    do {
      if (a[x] != a[y]) return false;
      ++x; ++y;
    } while (!isLMSchar(x) && !isLMSchar(y));
    return a[x] == a[y];
  };
  // Note: two LMS-substrings are the same only if they are adjacent since we have sort LMS-prefix
  std::vector<int> name(n + 1, -1);
  int lx = -1, cnt = 0;
  bool flag = true; // means no same LMS-substring
  for (auto x : SA) if (isLMSchar(x)) {
    if (lx >= 0 && !equalSubstring(lx, x)) ++cnt;
    if (lx >= 0 && cnt == name[lx]) flag = false;
    name[x] = cnt;
    lx = x;
  }
  std::vector<int> S1;
  for (auto x : name) if (x != -1) S1.emplace_back(x);
  auto getSA1 = [&]() {
    int n1 = S1.size();
    std::vector<int> SA1(n1);
    for (int i = 0; i < n1; ++i) SA1[S1[i]] = i;
    return SA1;
  };
  auto SA1 = flag ? getSA1() : SAIS(S1);
  // induce sort SA again according to the order of S1
  lbucket[0] = sbucket[0] = 0;
  for (int i = 1; i < mx; ++i) {
    lbucket[i] = bucket[i - 1];
    sbucket[i] = bucket[i] - 1;
  }
  std::fill(SA.begin(), SA.end(), -1);
  // scan SA1 in reverse order sicne S type is reorder in SA
  for (int i = SA1.size() - 1; i >= 0; --i) {
    SA[sbucket[a[pos[SA1[i]]]]--] = pos[SA1[i]];
  }
  inducedSort();
  return SA;
}

// the lexicographical smallest suffix is s[ans[0],...]
std::vector<int> SAIS(const std::string& s) {
  // If charset of s is lowercase letter, using th following f
  // auto f = [](char x) -> int { return int(x - 'a') + 1;};
  auto f = [](char x) -> int { return int(x) + 1;};
  std::vector<int> a;
  for (auto c : s) a.emplace_back(f(c));
  a.emplace_back(0);
  auto sa = SAIS(a);
  return std::vector<int>(sa.begin() + 1, sa.end());
}
// https://www.luogu.com.cn/problem/P3809


void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  auto sa = SAIS(s);
  std::vector<int> rk(n), ht(n);
  for (int i = 0; i < n; ++i) rk[sa[i]] = i;
  for (int i = 0, k = 0; i < n; ++i) {
    if (k) --k;
    if (rk[i] == 0) k = 0;
    else {
      // won't out of range
      while (s[i + k] == s[sa[rk[i] - 1] + k]) ++k;
      ht[rk[i]] = k;
    }
  }
  std::vector<int> dp(n);
  dp[0] = n - sa[0];
  for (int i = 1; i < n; ++i) {
    int len = n, mx = n - sa[i];
    dp[i] = mx;
    for (int j = i - 1; j >= 0; --j) {
      len = std::min(len, ht[j + 1]);
      if (sa[j] < sa[i]) dp[i] = std::max(dp[i], dp[j] + mx - len);
    }
  }
  std::cout << *std::max_element(dp.begin(), dp.end()) << '\n';
}

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    solve();
  }
  return 0;
}