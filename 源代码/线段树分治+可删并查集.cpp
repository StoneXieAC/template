#include<bits/stdc++.h>

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define unmap unordered_map
#define unset unordered_set
#define MAXQ priority_queue
#define mid ((l+r)>>1)
#define lson (rt<<1)
#define rson ((rt<<1)|1)
using namespace std;
template<typename T> using MINQ = priority_queue <T, vector<T>, greater<T>>;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;

//const int INF=
const int N = 4e5 + 10;
int n, m, k, fa[N], h[N];

struct info {
    int x, y, add;

    info(int aa, int bb, int cc) : x(aa), y(bb), add(cc) {}
};

stack <info> st;
pii E[N];
vi t[N << 2];

int find(int v) {
    while (fa[v] != 0) v = fa[v];
    return v;
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (h[x] > h[y]) swap(x, y);
    st.emplace(x, y, h[x] == h[y] ? 1 : 0);
    fa[x] = y;
    if (h[x] == h[y]) h[y]++;
}

void update(int rt, int l, int r, int ll, int rr, int idx) {
    if (l > rr || r < ll) return;
    if (ll <= l && r <= rr) {
        t[rt].eb(idx);
        return;
    }
    update(lson, l, mid, ll, rr, idx);
    update(rson, mid + 1, r, ll, rr, idx);
}

void work(int rt, int l, int r) {
    int ans = 1;
    int lastsiz = st.size();
    for (auto i: t[rt]) {
        auto [a, b] = E[i];
        int fa = find(a), fb = find(b);
        if (fa == fb) {
            for (int k = l; k <= r; k++)
                cout << "No\n";
            ans = 0;
            break;
        }
        merge(a, b + n);
        merge(b, a + n);
    }
    if (ans) {
        if (l == r) cout << "Yes\n";
        else {
            work(lson, l, mid);
            work(rson, mid + 1, r);
        }
    }
    while (st.size() > lastsiz) {
        auto [x, y, add] = st.top();
        h[fa[x]] -= add;
        fa[x] = 0;
        st.pop();
    }
    return;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> E[i].first >> E[i].second;
        int l, r;
        cin >> l >> r;
        l++;
        update(1, 1, k, l, r, i);
    }
    fill(h, h + 2 * n + 1, 1);
    work(1, 1, k);
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int _t = 1;
    for (int i = 1; i <= _t; i++) {
        solve();
    }
    return 0;
}
