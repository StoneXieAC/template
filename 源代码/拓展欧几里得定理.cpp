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

int ex_gcd(int a, int b, int &x, int &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
    int ans = ex_gcd(b, a % b, x, y);
    int tmp = x;
    x = y;
    y = tmp - a / b * y;
    return ans;
}

void solve() {
    int x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    int W = n - m, S = x - y;
    if (W < 0) {
        W = -W;
        S = -S;
    }
    int k, z;
    int gcd = ex_gcd(W, L, k, z);
    if (S % gcd) {
        cout << "Impossible\n";
        return;
    }
    int mod = L / gcd;
    cout << ((k * S / gcd) % mod + mod) % mod;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int _t = 1;
    for (int i = 1; i <= _t; i++) {
        solve();
    }
    return 0;
}
