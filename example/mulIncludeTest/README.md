本例子情况下，调用

``` shell
g++ main.cpp b.cpp c.cpp  -std=c++17 -o main
```

会编译出错，这是因为相当于 add 有两种实现

所以如果全部只用 .h，仅有一个 main.cpp 也是没问题的。但是还是推荐 .h 中只写声明

但是会看到一些 .h 中有实现，实际是因为 它们被 inline 了，所以没有编译错误
