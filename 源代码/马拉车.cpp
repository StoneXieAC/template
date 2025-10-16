//
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>

#define mem(x, y) memset(x,y,sizeof(x))
#define endl '\n'
#define int long long
#define pb emplace_back
//#define INF
using namespace std;
typedef long long lld;
typedef long double llf;
typedef pair<int, int> pii;
const int N = 110005 * 2;
char str[N], s[N];
int dp[N];

void solve() {
    int len = 0;
    int idx = 0, mx = 0, ans = 0;
    s[len++] = '@';
    s[len++] = '#';
    for (int i = 0; str[i]; i++) {
        s[len++] = str[i];
        s[len++] = '#';
    }
    s[len++] = '%';
    for (int i = 1; i < len; i++) {
        if (i < mx) dp[i] = min(dp[2 * idx - i], mx - i);
        else dp[i] = 1;
        while (s[i - dp[i]] == s[i + dp[i]]) dp[i]++;
        if (mx < i + dp[i]) {
            idx = i;
            mx = i + dp[i];
        }
        ans = max(ans, dp[i] - 1);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    while (cin >> str) solve();
    return 0;
}
