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
      tree[i].init(i, -x, 0);
    }
    int root = cartesian_build(tree, n);
    // 下面是求以 a[i] 为最小值且包含 i 的最大区间
    std::vector<int> l(n + 1), r(n + 1);
    std::function<void(int)> getinterval = [&](int x) {
      if (x == 0) return;
      if (tree[tree[x].par].ch[0] == x) {
        r[x] = tree[x].par - 1;
        l[x] = l[tree[x].par];
      } else {
        l[x] = tree[x].par + 1;
        r[x] = r[tree[x].par];
      }
      getinterval(tree[x].ch[0]);
      getinterval(tree[x].ch[1]);
    };
    l[root] = 1;
    r[root] = n;
    getinterval(tree[root].ch[0]);
    getinterval(tree[root].ch[1]);
    // 要考虑有相同值的情形，必须要分两次搞，不然有bug
    std::function<void(int)> updateinterval = [&](int x) {
      if (x == 0) return;
      if (tree[tree[x].par].ch[0] == x) {
        if (tree[x].val == tree[tree[x].par].val) r[x] = r[tree[x].par];
      } else {
        if (tree[x].val == tree[tree[x].par].val) l[x] = l[tree[x].par];
      }
      updateinterval(tree[x].ch[0]);
      updateinterval(tree[x].ch[1]);
    };
    updateinterval(tree[root].ch[0]);
    updateinterval(tree[root].ch[1]);
    // for (int i = 1; i <= n; ++i) {
    //   std::cout << l[i] << " " << r[i] << std::endl;
    // }
    std::vector<int> a(n + 1), b(n + 1, INT_MAX);
    for (int i = 1; i <= n; ++i) {
      int val = -tree[i].val;
      a[val] = std::max(a[val], r[i] - l[i] + 1);
    }
    // for (int i = 1; i <= n; ++i) std::cout << a[i] << " \n"[i == n];
    for (int i = 1; i <= n; ++i) b[i] = std::min(b[i - 1], a[i]);
    std::string s;
    for (int i = 1; i <= n; ++i) {
      s += (b[n + 1 - i] >= i ? '1' : '0');
    }
    std::cout << s << std::endl;
  }
  return 0;
}