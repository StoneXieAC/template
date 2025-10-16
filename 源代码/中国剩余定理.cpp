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

int CRT(vector<int> &a, vector<int> &r) {
    int n = 1, ans = 0;
    for (auto x: r) n *= x;
    for (int i = 0; i < r.size(); i++) {
        int m = n / r[i], inv, y;
        ex_gcd(m, r[i], inv, y);//求乘法逆元
        ans = (ans + a[i] * inv * m % n) % n;
    }
    return (ans % n + n) % n;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> r[i] >> a[i];
    }
    cout << CRT(a, r) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int _t = 1;
    for (int i = 1; i <= _t; i++) {
        solve();
    }
    return 0;
}