//
#include<bits/stdc++.h>

#define mem(x, y) memset(x,y,sizeof(x))
#define endl '\n'
#define int long long
#define pb emplace_back
#define lson (rt<<1)
#define rson ((rt<<1)|1)
#define mid ((l+r)>>1)
//#define INF
using namespace std;
typedef long long lld;
typedef long double llf;
typedef pair<int, int> pii;
const int N = 1e6 + 10;
int lazy[N << 2], t[N << 2];
int a[N];

void pushdown(int rt, int l, int r) {
    lazy[lson] += lazy[rt];
    lazy[rson] += lazy[rt];
    t[lson] += lazy[rt] * (mid - l + 1);
    t[rson] += lazy[rt] * (r - mid);
    lazy[rt] = 0;
}

void pushup(int rt) {
    t[rt] = t[lson] + t[rson];
}

void update(int rt, int l, int r, int ll, int rr, int val) {
    if (rr < l || r < ll) return;
    if (ll <= l && r <= rr) {
        lazy[rt] += val;
        t[rt] += val * (r - l + 1);
        return;
    }
    pushdown(rt, l, r);
    update(lson, l, mid, ll, rr, val);
    update(rson, mid + 1, r, ll, rr, val);
    pushup(rt);
}

int query(int rt, int l, int r, int ll, int rr) {
    if (rr < l || r < ll) return 0;
    if (ll <= l && r <= rr) {
        return t[rt];
    }
    pushdown(rt, l, r);
    return query(lson, l, mid, ll, rr) + query(rson, mid + 1, r, ll, rr);
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

void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build(1, 1, n);
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            update(1, 1, n, l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
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

