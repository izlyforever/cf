## [Codeforces Round #627 (Div. 3)](https://codeforces.com/contest/1324)

### F：经典换根 DP

题意：以树的某个节点为根的子树的白色节点减去黑色节点的个数的最大值

做法：首先以 1 为根预处理所有子树的答案，然后分情况状态转移。具体看子节点是否对父节点做了贡献。