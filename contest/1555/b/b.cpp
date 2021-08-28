#include <bits/stdc++.h>
#define clog(x) std::clog << (#x) << " is " << (x) << '\n';
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

// 根据情况换成 bool
int solve() {
  int W, H, x1, y1, x2, y2, w, h;
  std::cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
  int dx = x2 - x1, dy = y2 - y1;
  if (dx + w > W && dy + h > H) return -1;
  int ans = INT_MAX;
  if (dx + w <= W) {
    ans = std::min(ans, std::max(0, std::min(w - x1, w - (W - x2))));
  }
  if (dy + h <= H) {
    ans = std::min(ans, std::max(0, std::min(h - y1, h - (H - y2))));
  }
  return ans;
}

int main() {
	//freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int cas = 1;
	std::cin >> cas; // 根据情况注释掉
	while (cas--) {
		std::cout << solve() << '\n';
	}
	return 0;
}