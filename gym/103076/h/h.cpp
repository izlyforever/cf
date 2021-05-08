#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

class Game {
public:
Game(int x) : val(x) {
	ToMatrix(val);
	dist = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			val = val * 10 + dp[i][j];
			dist += (i + j + 1 != dp[i][j]);
		}
	}
}
int dp[3][3], val, i0, j0, dist;
void ToMatrix(int x) {
	for (int i = 2; i >= 0; --i) {
		for (int j = 2; j >= 0; --j) {
			dp[i][j] = x % 10;
			x /= 10;
			if (dp[i][j] == 0) {
				i0 = i;
				j0 = j;
			}
		}
	}
}
void updateVal() {
	val = 0, dist = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			val = val * 10 + dp[i][j];
			dist += (i * 3 + j + 1 != dp[i][j]);
		}
	}
}
bool operator<(const Game &A) const {
	return dist > A.dist;
}
bool operator==(const Game &A) const {
	return val == A.val;
}
};

const int N = 123456780;
int c[9];
std::vector<std::pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
Game over(N);
std::map<Game, LL> mp;
bool check(int x, int y) {
	return x >= 0 && x < 3 && y >= 0 && y < 3;
}
void bfs(Game A) {
	std::priority_queue<Game> Q;
	Q.push(A);
	while (!Q.empty()) {
		Game now = Q.top();
		Q.pop();
		for (auto [x, y] : dir) if (check(now.i0 + x, now.j0 + y)) {
			Game cur = now;
			std::swap(cur.dp[cur.i0][cur.j0], cur.dp[cur.i0 + x][cur.j0 + y]);
			int cost = c[cur.dp[cur.i0][cur.j0]];
			cur.i0 += x;
			cur.j0 += y;
			cur.updateVal();
			if (mp.count(cur) == 0) {
				mp[cur] = mp[now] + cost;
				Q.push(cur);
				if (cur == over) return;
			}
		}
	}
}

LL solve() {
	int val = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0, x; j < 3; ++j) {
			std::cin >> x;
			val = val * 10 + x;
		}
	}
	for (int i = 1; i < 9; ++i) std::cin >> c[i];
	Game A(val);
	mp[A] = 0;
	bfs(A);
	return mp[over];
}
int main() {
	freopen("in", "r", stdin);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	std::cout << solve() << '\n';
	return 0;
}