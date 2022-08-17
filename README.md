# [cpplib](https://github.com/izlyforever/cpplibforCP)

- Think twice, code once
- 如果没有本质修改，且没有发现问题，大概率题意理解错了。

## Code by [izlyforever](https://codeforces.com/profile/izlyforever)

Source Code In Codeforces and other OJs.

## Use [cf-tool](https://github.com/izlyforever/cf-tool)

my config:

``` shell
g++ $%full%$ -o $%file%$.out -std=c++17 -D_GLIBCXX_DEBUG -Wall -Wshadow -Wno-error -g
```

``` json
// .vscode/launch.json need vscode extension: codelldb and replace 1719 with current contest id
// clang++ main.cpp -o main.out -std=c++17 -D_GLIBCXX_DEBUG -Wall -Wshadow -Wno-error -g
{
  // Use IntelliSense to learn about possible attributes.
  // Hover to view descriptions of existing attributes.
  // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
  "version": "0.2.0",
  "configurations": [
    {
      "type": "lldb",
      "request": "launch",
      "name": "c",
      "program": "${workspaceFolder}/contest/1719/c/c.out",
      "args": [],
      "cwd": "${workspaceFolder}/contest/1719/c",
    },
    {
      "type": "lldb",
      "request": "launch",
      "name": "main",
      "program": "${workspaceFolder}/main.out",
      "args": [],
      "cwd": "${workspaceFolder}",
    },
  ]
}
```

## Genius

- [tourist](https://codeforces.com/profile/tourist): legend
- [jiangly](https://codeforces.com/profile/jiangly): clear ideal, nice code style
- [rainboy](https://codeforces.com/profile/rainboy): C
- [clyring](https://codeforces.com/submissions/clyring): Haskell
- [Haskell_for_a_pint](https://codeforces.com/profile/Haskell_for_a_pint): Haskell
