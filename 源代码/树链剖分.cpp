#include<bits/stdc++.h>

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define unmap unordered_map
#define unset unordered_set
#define MAXQ priority_queue
#define lson (rt<<1)
#define rson ((rt<<1)|1)
#define mid ((l+r)>>1)
using namespace std;
template<typename T> using MINQ = priority_queue <T, vector<T>, greater<T>>;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;

//const int INF=
const int N = 1e5 + 10;
int n;
int dfs[N], top[N], son[N], siz[N], dep[N];
int val[N], fa[N], dfn[N], tot;
vector <pii> E[N];
pii Ed[N];
int a[N], t[N << 2];

void dfs1(int v, int f) {
    siz[v] = 1;
    fa[v] = f;
    dep[v] = dep[f] + 1;
    for (auto [u, w]: E[v]) {
        if (u == f) continue;
        val[u] = w;
        dfs1(u, v);
        siz[v] += siz[u];
        if (siz[u] > siz[son[v]]) son[v] = u;
    }
}

void dfs2(int v, int tp) {
    top[v] = tp;
    dfn[v] = ++tot;
    a[tot] = val[v];
    if (son[v]) dfs2(son[v], tp);
    for (auto [u, w]: E[v]) {
        if (u == son[v] || u == fa[v]) continue;
        dfs2(u, u);
    }
}

void pushup(int rt) {
    t[rt] = max(t[lson], t[rson]);
}

void build(int rt, int l, int r) {
    if (l == r) {
        t[rt] = a[l];
        return;
    }
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}

void update(int rt, int l, int r, int pos, int val) {
    if (l == r) {
        t[rt] = val;
        return;
    }
    if (pos <= mid) update(lson, l, mid, pos, val);
    else update(rson, mid + 1, r, pos, val);
    pushup(rt);
}

int query(int rt, int l, int r, int ll, int rr) {
    if (ll > r || l > rr) return 0;
    if (ll <= l && r <= rr) return t[rt];
    return max(query(lson, l, mid, ll, rr), query(rson, mid + 1, r, ll, rr));
}

int getans(int u, int v) {
    int tu = top[u], tv = top[v], ans = 0;
    if (u == v) return 0;
    while (tu != tv) {
        if (dep[tu] < dep[tv]) {
            swap(tu, tv);
            swap(u, v);
        }
        ans = max(query(1, 1, n, dfn[tu], dfn[u]), ans);
        u = fa[tu];
        tu = top[u];
    }
    if (dep[u] < dep[v]) swap(u, v);
    ans = max(ans, query(1, 1, n, dfn[v] + 1, dfn[u]));
    return ans;
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        E[u].push_back({v, w});
        E[v].push_back({u, w});
        Ed[i] = {u, v};
    }
    dfs1(1, 0);
    dfs2(1, 1);
    build(1, 1, n);
    char s[10];
    int x, y;
    while (true) {
        cin >> s;
        if (s[0] == 'D') break;
        cin >> x >> y;
        if (s[0] == 'C') {
            auto [u, v] = Ed[x];
            if (fa[v] == u) swap(u, v);
            update(1, 1, n, dfn[u], y);
        } else {
            cout << getans(x, y) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int _t = 1;
    for (int i = 1; i <= _t; i++) {
        solve();
    }
    return 0;
}
