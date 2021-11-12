#include <bits/stdc++.h>
#define cerr(x) std::cerr << (#x) << " is " << (x) << '\n';
using LL = long long;

int solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int d = 0, ans = 0;
    for (auto& x : a) {
        std::cin >> x;
        d = std::gcd(d, x);
    }
    auto check = [&]() {
        for (int i = 0; i < n; ++i) if (a[i] != d) return false;
        return true;
    };
    auto f = [&]() {
        auto p = a, q = a;
        bool flag = true;
        int x = -1;
        while (flag) {
            std::swap(p, q);
            flag = false;
            ++x;
            for (int i = 0; i < n; ++i) {
                p[i] = std::gcd(q[i], q[(i + (1 << x)) % n]);
                if (p[i] != d) flag = true;
            }
        }
        if (x == 0) {
            a = std::move(p);
            ++x;
        } else {
            a = std::move(q);
        }
        ans += (1 << x) - 1;
    };
    while (!check()) f();
    return ans;
}

int main() {
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int cas = 1;
    std::cin >> cas;  // 根据情况注释掉
    while (cas--) {
        std::cout << solve() << '\n';
    }
    return 0;
}
