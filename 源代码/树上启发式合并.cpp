#include<bits/stdc++.h>

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define unmap unordered_map
#define unset unordered_set
#define MAXQ priority_queue
using namespace std;
template<typename T> using MINQ = priority_queue <T, vector<T>, greater<T>>;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;

//const int INF=
const int N = 1e5 + 10;
vi E[N];
int son[N], siz[N], ans[N];
int cnt[N], col[N], maxn, sum, su;

void dfs(int v, int fa) {
    siz[v] = 1;
    for (auto u: E[v]) {
        if (u == fa) continue;
        dfs(u, v);
        siz[v] += siz[u];
        if (siz[u] > siz[son[v]]) son[v] = u;
    }
}

void change(int v, int fa, int val) {
    cnt[col[v]] += val;
    if (cnt[col[v]] > maxn) {
        maxn = cnt[col[v]];
        sum = col[v];
    } else if (cnt[col[v]] == maxn) {
        sum += col[v];
    }
    for (auto u: E[v]) {
        if (u == fa || u == su) continue;//不删重儿子
        change(u, v, val);
    }
}

void dsu(int v, int fa, bool save) {
    for (auto u: E[v]) {
        if (u == fa || u == son[v]) continue;
        dsu(u, v, false);
    }
    if (son[v]) {
        dsu(son[v], v, true);
        su = son[v];//重儿子节点要保留
    }
    change(v, fa, 1);
    su = 0;
    ans[v] = sum;
    if (!save) {
        change(v, fa, -1);
        maxn = sum = 0;//这么删完之后其实cnt数组是清空了的要把辅助变量也归零
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> col[i];
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        E[u].pb(v);
        E[v].pb(u);
    }
    dfs(1, 0);
    dsu(1, 0, 1);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int _t = 1;
    for (int i = 1; i <= _t; i++) {
        solve();
    }
    return 0;
}
