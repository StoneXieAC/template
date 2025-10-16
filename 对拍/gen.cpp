// 数据生成器
#include <bits/stdc++.h>

using ll = long long;
std::mt19937_64 gen(std::random_device{}());

void solve() {
    std::uniform_int_distribution<ll> dis(1, 100);
    std::cout << dis(gen) << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int _t = 1;
//    std::cin >> _t;
    while (_t--) {
        solve();
    }
    return 0;
}
