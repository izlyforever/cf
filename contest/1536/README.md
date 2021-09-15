迟了三分钟，打的话觉得亏了，就没打

## [Codeforces Round #724 (Div. 2)](https://codeforces.com/contest/1536)

### A：观察到不能有负数，然后如果所有的数都取肯定可以

### B：题意有点问题，但是无所谓

我们就一直搜索即可，例如先搜 $a, \cdots, z$，再搜 $aa, ab, \cdots, zz$，那我们就跟处理 26 进制一样搞就行了。

### C：比例问题

我们把比例化成最简形式，用 map 存一下当前值即可

### D：中位数

题意：定义数组 $a_1, \cdots, a_{2n - 1}$ 的 OmkArray 为数组 $b_1 \cdots, b_n$，其中 $b_i$ 为 $a_1, \cdots, a_{2i - 1}$ 的中位数。现在给定 $b$，问是否存在 $a$ 使得 $b$ 是 $a$ 的 OmkArray。（若是，找出其中一个 $a$）

[官方题解](https://codeforces.com/blog/entry/91520)：假设 $k < n$，$b_1, \cdots, b_k$ 是 $a_1, \cdots, a_{2k - 1}$ 的 OmkArray。我们要加两个数 $a_{2k}, a_{2k + 1}$ 使得 $b_1, \cdots, b_{k + 1}$ 是 $a_1, \cdots, a_{2k + 1}$ 的 OmkArray。不妨假设 $c$ 是当前 $a$ 排序的结果。

> 注意到：$b_k = c_{k}$

若 $b_{k + 1} \geq b_k$，$a$ 中仅有 $k - 2$ 个元素大于等于 $c_{k + 1}$（我们先不考虑有相等的情况，或者说我们可以打一个 tag 变成 pair，即使相等，我们也可以让它不等），因此无论 $a_{2k}, a_{2k + 1}$ 多大，最多只有 $k$ 个元素大于等于 $c_{k + 1}$，因此 $b_{k + 1} \leq c_{k + 1}$，同理看小于等于的情况，我们知道 $b_{k + 1} \geq c_{k - 1}$。

注意到 $b_1, \cdots, b_k$ 中的元素在 $a$ 中至少出现一次，因此若 $b_i, b_j$ 分别为小于等于 $b_k$ 中最大的，大于等于 $b_k$ 中最小的，那么 $c_{k + 1} \leq b_j, c_{k - 1} \geq b_i$。这等价于说：不存在 $j < i$ 使得 $b_j$ 在 $b_i$ 和 $b_{i + 1}$ 之间（不包含边界）。其实这也是充分的条件。

- $a_1 = b_1$
- if $b_{i + 1} = b_j$（其中 $b_j \leq b_i$），令 $a_{2k - 2} = a_{2k - 1} = -\infty$
- else if $b_{i + 1} < b_i$，令 $a_{2k - 2} = -\infty, a_{2k - 1} = b_{i + 1}$
- if $b_{i + 1} = b_j$（其中 $b_j \leq b_i$），令 $a_{2k - 2} = a_{2k - 1} = \infty, a_{2k - 1}$
- else if $b_{i + 1} > b_i$，令 $a_{2k - 2} = \infty, a_{2k - 1} = b_{i + 1}$
- else $b_{i + 1} = b_i$，令 $a_{2k - 2} = -infty, a_{2k - 1} = -infty$

简洁的 $O(n \log n)$ 的实现：

``` C++
bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> b(n);
  for (auto& x : b) std::cin >> x;
  std::set<int> S{b[0]};
  for (int i = 1; i < n; ++i) {
    auto [x, y] = std::minmax(b[i - 1], b[i]);
    auto it = S.upper_bound(x);
    if (it != S.end() && *it < y) return false;
    S.insert(b[i]);
  }
  return true;
}
```

线性的实现：

```
bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> b(n);
  for (auto& x : b) std::cin >> x;
  std::stack<int> l, r;
  for (int i = 1; i < n; ++i) if (b[i] != b[i - 1]) {
    if (b[i] > b[i - 1]) {
      if (!r.empty() && b[i] > r.top()) return false;
      if (!r.empty() && b[i] == r.top()) r.pop();
      if (l.empty() || l.top() != b[i - 1]) l.push(b[i - 1]);
    } else {
      if (!l.empty() && b[i] < l.top()) return false;
      if (!l.empty() && b[i] == l.top()) l.pop();
      if (r.empty() || r.top() != b[i - 1]) r.push(b[i - 1]);
    }
  }
  return true;
}
```

带 a 的线性做法：

``` C++

bool solve() {
  int n;
  std::cin >> n;
  std::vector<int> b(n), a(2 * n - 1);
  for (auto& x : b) std::cin >> x;
  a[0] = b[0];
  std::stack<int> l, r;
  for (int i = 1; i < n; ++i) {
    if (b[i] == b[i - 1]) {
      a[i * 2 - 1] = INT_MIN;
      a[i * 2] = INT_MAX;
    } else if (b[i] > b[i - 1]) {
      if (!r.empty() && b[i] > r.top()) return false;
      a[i * 2 - 1] = INT_MAX;
      if (!r.empty() && b[i] == r.top()) {
        r.pop();
        a[i * 2] = INT_MAX;
      } else {
        a[i * 2] = b[i];
      }
      if (l.empty() || l.top() != b[i - 1]) l.push(b[i - 1]);
    } else {
      if (!l.empty() && b[i] < l.top()) return false;
      a[i * 2 - 1] = INT_MIN;
      if (!l.empty() && b[i] == l.top()) {
        l.pop();
        a[i * 2] = INT_MIN;
      } else {
        a[i * 2] = b[i];
      }
      if (r.empty() || r.top() != b[i - 1]) r.push(b[i - 1]);
    }
  }
  for (auto x : a) std::clog << x << ' ';
  std::clog << '\n';
  return true;
}
```