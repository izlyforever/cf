#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
#define print(x) std::cout << (x) << std::endl
#define println std::cout << std::endl
using LL = long long;

const int N = 3;
LL dp[N][N];
void Floyd(int n){
  for(int k = 0; k != n; ++k)
    for(int i = 0; i != n; ++i)
      for(int j=0; j != n; ++j)
        dp[i][j] = std::min(dp[i][j],dp[i][k] + dp[k][j]);
}
int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas;
  std::cin >> cas;
  while (cas--) {
    LL x, y;
    std::cin >> x >> y;
    std::cin >> dp[0][1] >> dp[0][2] >> dp[1][2] >> dp[1][0] >> dp[2][0] >> dp[2][1];
    Floyd(3);
    LL r = 0;
    if (x == 0) {
      r += (y > 0 ? dp[0][2] * y : dp[2][0] * (-y));
    } else if (x > 0) {
      if (y >= x) r += dp[0][1] * x + dp[0][2] * (y - x);
      else if (y > 0) r += dp[0][1] * y + dp[2][1] * (x - y);
      else r += dp[2][1] * x + dp[2][0] * (-y);
    } else {
      if (y >= 0) r += dp[1][2] * (-x) + dp[0][2] * y;
      else if (y > x) r += dp[1][0] * (-y) + dp[1][2] * (y - x);
      else r += dp[1][0] * (-x) + dp[2][0] * (x - y);
    }
    print(r);
  }
  return 0;
}