如果 detach 中所出现的 crash 一样，怎么避免这种情况的 用 lambda 转线程也会遇到这种问题，如何解决呢

根据同事的讨论，最后用 `enable_shared_from_this`，如果能使用 c++17 可以写的更加简洁，并且操作系统会自己回收资源，确实不错