#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
  // freopen("in","r",stdin)
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int b, k;
  cin >> b >> k;
  int a[k + 1];
  for (int i = 1; i <= k; ++i) cin >> a[i];
  bool r = a[k] & 1;
  if (b & 1) {
    for (int i = 1; i < k; ++i) {
      if (a[i] & 1) r = !r;
    }
  }
  cout << (r ? "odd" : "even") << endl;
  return 0;
}
