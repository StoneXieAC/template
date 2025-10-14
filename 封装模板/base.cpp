#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#define debug(x) std::cout << "debug: " << #x << " " << x << std::endl
#else
#define debug(...) (void)0
#endif
// #define endl '\n'
// #define int long long

#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define drep(i, a, b) for (int i = (a); i >= (b); --i)
#define frep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

namespace pbds = __gnu_pbds;

template<typename T1, typename T2>
using unmap = std::unordered_map<T1, T2>;
template<typename T>
using unset = std::unordered_set<T>;
template<typename T>
using MINQ = std::priority_queue<T, std::vector<T>, std::greater<T> >;
template<typename T>
using MAXQ = std::priority_queue<T, std::vector<T>, std::less<T> >;
template<typename T>
using rb_tree = pbds::tree<T, pbds::null_type, std::less<T>, pbds::rb_tree_tag, pbds::tree_order_statistics_node_update>;

using pii = std::pair<int, int>;
using vi = std::vector<int>;
using vii = std::vector<vi>;
using viii = std::vector<vii>;
using i128 = __int128;
using u128 = unsigned __int128;
using ll = long long;
using ull = unsigned long long;
using lf = double;

std::istream &operator>>(std::istream &in, __int128 &x) {
    x = 0;
    bool neg = false;
    char c = in.get();
    while (!isdigit(c) && c != '-') c = in.get();
    if (c == '-') neg = true, c = in.get();
    while (isdigit(c)) x = x * 10 + (c - '0'), c = in.get();
    if (neg) x = -x;
    return in;
}

std::ostream &operator<<(std::ostream &out, __int128 x) {
    if (x == 0) return out << '0';
    if (x < 0) out << '-', x = -x;
    static char buf[40];
    int i = 0;
    while (x) buf[i++] = x % 10 + '0', x /= 10;
    while (i--) out << buf[i];
    return out;
}

template<typename T1, typename T2>
std::istream &operator>>(std::istream &is, std::pair<T1, T2> &x) {
    is >> x.first >> x.second;
    return is;
}

template<typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, std::pair<T1, T2> &x) {
    os << x.first << " " << x.second;
    return os;
}

template<typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &vec) {
    for (auto &x: vec) is >> x;
    return is;
}

template<typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> &vec) {
    for (auto &x: vec) os << x << " ";
    return os;
}

void solve() {

}

void init() {
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cout << std::fixed << std::setprecision(10);

    int _t = 1;
    std::cin >> _t;

#ifndef ONLINE_JUDGE
    const auto START = std::chrono::high_resolution_clock::now();
#endif

    init();
    for (int i = 1; i <= _t; i++) {
        solve();
    }

#ifndef ONLINE_JUDGE
    const auto END = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double, std::milli> duration = END - START;
    std::cout << std::fixed << std::setprecision(1) << "Running Time: " << duration.count() << " ms";
#endif

    return 0;
}
/*
       _____   _                           __   __  _
      / ____| | |                          \ \ / / (_)
     | (___   | |_    ___    _ __     ___   \ V /   _    ___
      \___ \  | __|  / _ \  | '_ \   / _ \   > <   | |  / _ \
      ____) | | |_  | (_) | | | | | |  __/  / . \  | | |  __/
     |_____/   \__|  \___/  |_| |_|  \___| /_/ \_\ |_|  \___|

*/