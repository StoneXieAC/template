//
#include<bits/stdc++.h>

#define mem(x, y) memset(x,y,sizeof(x))
#define endl '\n'
#define int long long
#define pb emplace_back
//#define INF
using namespace std;
typedef long long lld;
typedef long double llf;
typedef pair<int, int> pii;
const int N = 1e6 + 5;
bool lowprime[N];//[0,sqrt(b)]
bool highprime[N];//[a,b]
vector<int> zone_prime(int a, int b) {
    mem(lowprime, 1);
    mem(highprime, 1);
    for (int i = 2; i * i <= b; i++) {
        if (lowprime[i]) {
            for (int j = 2 * i; j * j <= b; j += i)
                lowprime[j] = false;
            for (int j = max(2LL, (a - 1) / i + 1) * i; j <= b; j += i)
                highprime[j - a] = false;
        }
    }
    vector<int> res;
    for (int i = 0; i <= b - a; i++) {
        if (highprime[i]) {
            if (i + a == 1) continue;
            res.pb(i + a);
        }
    }

    return res;
//	999999995000 1000000000000
}

int l, r;

void solve() {
    auto res = zone_prime(l, r);
    for (auto x: res) {
        cout << x << " ";
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while (cin >> l >> r) {
        solve();
    }
    return 0;
}
