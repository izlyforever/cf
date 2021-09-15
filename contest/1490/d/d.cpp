#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

struct Node {
  int id, val, par, ch[2];
  void init(int _id, int _val, int _par) {
    id = _id, val = _val, par = _par, ch[0] = ch[1] = 0;
  }
};
int cartesian_build(std::vector<Node>& tree, int n) {
  for (int i = 1; i <= n; ++i) {
    int k = i - 1;
    while (tree[k].val < tree[i].val) k = tree[k].par;
    tree[i].ch[0] = tree[k].ch[1];
    tree[k].ch[1] = i;
    tree[i].par = k;
    tree[tree[i].ch[0]].par = i;
  }
  return tree[0].ch[1];
}

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<Node> tree(n + 1);
    tree[0].init(0, INT_MAX, 0);
    for (int i = 1, x; i <= n; ++i) {
      std::cin >> x;
      tree[i].init(i, x, 0);
    }
    int root = cartesian_build(tree, n);
    std::vector<int> d(n + 1);
    std::function<void(int)> dfs = [&](int x) {
      for (int i = 0; i < 2; ++i) if (tree[x].ch[i]) {
        d[tree[x].ch[i]] = d[x] + 1;
        dfs(tree[x].ch[i]);
      }
    };
    dfs(root);
    for (int i = 1; i <= n; ++i) std::cout << d[i] << " \n"[i == n];
  }
  return 0;
}