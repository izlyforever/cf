# [2021 ICPC Gran Premio de Mexico 1ra Fecha](https://codeforces.com/gym/103274)

## G

这不是 SG 问题，只是简单的逻辑推导问题，只考虑 $0, 1$ 的情况，因此只需看前 $m$ 个值中有无 0 即可，所以只需记录最后一个 0 的位置即可。然后用 `__builtin_popcount` 即可，但是其实用 `BitCount5` 更快，当然直接使用 `__builtin_parity` 最快