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
const int N = 1e5 + 10;
struct Node {
    signed fa, len, s[26];
} t[N * 2];
int n, las = 1, tot = 1;
int ans[N * 2];

void add(int nex) {
    int p = las, np = las = ++tot;
    t[np].len = t[p].len + 1;
    for (; p && !t[p].s[nex]; p = t[p].fa) t[p].s[nex] = np;
    if (!p) {
        t[np].fa = 1;
        return;
    }
    int v = t[p].s[nex];
    if (t[v].len == t[p].len + 1) {
        t[np].fa = v;
        return;
    }
    int nv = ++tot;
    t[nv] = t[v];
    t[nv].len = t[p].len + 1;
    t[v].fa = t[np].fa = nv;
    for (; p && t[p].s[nex] == v; p = t[p].fa) t[p].s[nex] = nv;
}

int dfs(int v) {
    if (ans[v]) return ans[v];
    for (int i = 0; i < 26; i++) {
        if (t[v].s[i]) {
            ans[v] += dfs(t[v].s[i]) + 1;
        }
    }
    return ans[v];
}

void solve() {
    string s;
    cin >> n >> s;
    for (auto c: s) {
        add(c - 'a');
    }
    cout << dfs(1);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int _t = 1;
    for (int i = 1; i <= _t; i++) {
        solve();
    }
    return 0;
}
