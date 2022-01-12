## [Codeforces Global Round 13](https://codeforces.com/contest/1491/)


### C：经典延迟更新问题

大致题意：给定初始数组 S, 每次经过 i 后，下一步就会到达 $i + S_i$ 直到值大于 n，然后 $S_i$ 减 1，且不会小于 1。问至少多少次可以使得所有的 S 都变成 1。

做法：显然从左往右贪心即可。但是要延迟更新，不然 TLE，延迟更新写的时候，记得只记录往后走的一步。具体来讲用 `b[i]` 表示 i 位置已被前面的位置走了 `b[i]` 次。因此 `ans += std::max(0, a[i] - b[i] - 1)`，然后 $i + 2, \cdots, i + a[i]$ 的 `b[i]` 都要加 1。直接这么做复杂度 $O(n^2)$，我们可以用线段树，或者 set，或者拓展树状数组优化到 $O(n \log n)$（不写了）。然而此问题可以优化到 $O(n)$（不可思议）做法本质和拓展树状数组思路一致。记 $c[i] = b[i] - b[i - 1]$ 即可。

``` C++
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<LL> a(n), b(n + 1);
    for (auto& x : a) std::cin >> x;
    LL r = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 2; j <= a[i] && i + j < n; ++j) ++b[i + j];
      if (b[i] >= a[i]) {
        b[i + 1] += b[i] - a[i] + 1;
      } else {
        r += a[i] - b[i] - 1;
      }
    }
    std::cout << r << "\n";
  }
  return 0;
}
```

[$O(n)$ 做法](https://codeforces.com/contest/1491/submission/108758256)：

``` C++
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int cas = 1;
  std::cin >> cas;
  while (cas--) {
    int n;
    std::cin >> n;
    std::vector<LL> a(n + 1), c(n + 1);
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    LL r = 0, b = 0;
    for (int i = 1; i <= n; ++i) {
      b += c[i];
      if (b >= a[i]) {
        if (i + 1 <= n) {
          c[i + 1] += b - a[i] + 1;
          if (i + 2 <= n) c[i + 2] -= b - a[i] + 1;
        }
      } else {
        r += a[i] - b - 1;
      }
      if (i + 2 <= n) ++c[i + 2];
      if (i + a[i] < n) --c[i + a[i] + 1];
    }
    std::cout << r << "\n";
  }
  return 0;
}
```

> 注意到这里前缀和是从左到右有序的算的，所以可以不用树状数组，常规操作就能做到 $O(n)$


### D：经典位运算问题

大致题意：u 到 $u + v$ 有一条有向边，当且仅当 $u \And v = v$。问 $x$ 能否到达 $y$。

做法：首先注意到若 $x > y$ 肯定不行，从 $x$ 出发的路径中二进制中 1 的个数只减不增。并且任何后缀的二进制中 1 的个数也是只减不增的。可以归纳证明此为 x 可达 y 的充要条件。


### E：经典树上问题，Fib 树

大致题意：一颗树 Fib 树当且仅当它的节点个数为 Fib 数且可以拆成两颗 Fib 树。

做法：首先所有节点个数必须是 Fib 数 $F_n$，且可以拆成有两颗 $F_{n - 1}$ 和 $F_{n- 2}$ 的子树。我们递归的看这两颗子树是不是 Fib 树即可。若有多种分拆方式，可以证明它们不会影响结果。（可画图看看就能理解，详细说明还挺麻烦）

> 比赛的时候知道这么做，但是怕递归超时就不敢这么写，哎！还想着怎么搞出更简洁的公式，实际上复杂度是 $O(n F_n)$ 的。

``` C++
#include <bits/stdc++.h>
#define watch(x) std::cout << (#x) << " is " << (x) << std::endl
using LL = long long;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<std::set<int>> e(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;
    e[u].insert(v);
    e[v].insert(u);
  }
  std::vector<int> fib{1, 1};
  while (fib.back() < n) fib.emplace_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
  if (fib.back() != n) {
    std::cout << "NO\n";
    return 0;
  }
  std::vector<int> sz(n), fa(n);
  bool flag = true;
  std::function<void(int, int)> solve = [&](int u, int i) {
    if (i <= 3 || !flag) return;
    int r = -1;
    std::function<void(int)> dfs = [&](int u) {
      sz[u] = 1;
      for (auto v : e[u]) if (v != fa[u]) {
        fa[v] = u;
        dfs(v);
        sz[u] += sz[v];
      }
      if (sz[u] == fib[i - 1] || sz[u] == fib[i - 2]) {
        r = u;
      }
    };
    fa[u] = -1;
    dfs(u);
    if (r == -1) {
      flag = false;
      return;
    }
    e[r].erase(fa[r]);
    e[fa[r]].erase(r);
    if (sz[r] == fib[i - 1]) {
      solve(fa[r], i - 2);
      solve(r, i - 1);
    } else {
      solve(fa[r], i - 1);
      solve(r, i - 2);
    }
  };
  solve(0, fib.size() - 1);
  std::cout << (flag ? "YES\n" : "NO\n");
  return 0;
}
```

> 上述代码可以通过打标记来删边，不一定要用 set 或 `unordered_set` 存边。
