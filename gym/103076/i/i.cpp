#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

class PstSegTree {
  const inline static LL inf = 1e18 + 2;
  struct Node {
    int l, r, val;
  };
  int newNode() {
    int sz = tree.size();
    tree.emplace_back(Node());
    return sz;
  }
  std::vector<Node> tree;
  void add(LL x, int val, LL l, LL r, int p) {
    tree[p].val += val;
    if (r - l > 1) {
      LL m = (l + r) / 2;
      if (x < m) {
        if (tree[p].l == 0) tree[p].l = newNode();
        add(x, val, l, m, tree[p].l);
      } else {
        if (tree[p].r == 0) tree[p].r = newNode();
        add(x, val, m, r, tree[p].r);
      }
    }
  }
  int query(LL k, LL l, LL r, int p) {
    if (tree[p].val == 0) return 0;
    if (k < l) return tree[p].val;
    if (r - l == 1) return tree[p].val;
    LL m = (l + r) / 2;
    int ans = 0;
    if (tree[p].r != 0) ans += query(k, m, r, tree[p].r);
    if (m > k + 1 && tree[p].l != 0) ans += query(k, l, m, tree[p].l);
    return ans;
  }
 public:
  PstSegTree() {
    newNode();
  }
  void add(LL x, int val) {
    add(x, val, 0, inf, 0);
  }
  int query(LL k) {
    return query(k, 0, inf, 0);
  }
};

int main() {
  //freopen("in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, q;
  std::cin >> q >> n;
  std::vector<LL> a(n);
  PstSegTree A;
  A.add(0, n);
  while (q--) {
    int op;
    std::cin >> op;
    LL k;
    if (op == 1) {
      int id;
      std::cin >> id >> k;
      A.add(a[id], -1);
      a[id] += k;
      A.add(a[id], 1);
    } else {
      std::cin >> k;
      std::cout << A.query(k) << '\n';
    }
  }
  return 0;
}