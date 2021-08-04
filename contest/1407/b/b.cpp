#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
using LL = long long;
const int N = 1e3 + 2;
int gcd[N][N];
void init() {
  for (int i = 0; i < N; ++i) gcd[i][0] = gcd[0][i] = i;
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; ++j) gcd[i][j] = gcd[j % i][i];
    for (int j = 1; j <= i; ++j) gcd[i][j] = gcd[j][i];
  }
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  init();
  int cas;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    int a[n];
    bool v[n] = {};
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int id = std::max_element(a, a + n) - a;
    std::vector<int> ans;
    ans.push_back(a[id]);
    v[id] = 1;
    int now = a[id];
    while (ans.size() != n) {
      int mx = 0;
      for (int i = 0; i < n; ++i) if (!v[i]) {
        mx = std::max(mx, gcd[now][a[i]]);
      }
      for (int i = 0; i < n; ++i) if (!v[i]) {
        if(mx == gcd[now][a[i]]) {
          ans.push_back(a[i]);
          v[i] = 1;
        }
      }
      now = mx;
    }
    for (auto x : ans) std::cout << x << " ";
    std::cout << std::endl;
  }
  return 0;
}