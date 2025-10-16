//
#include<bits/stdc++.h>

#define mem(x, y) memset(x,y,sizeof(x))
#define endl '\n'
#define int long long
#define pb emplace_back
#define lson (rt<<1)
#define rson ((rt<<1)|1)
#define mid ((l+r)>>1)
using namespace std;
typedef long long lld;
typedef long double llf;
typedef pair<int, int> pii;
const int N = 1e6 + 10;
int cnt = 0, n;

struct Line {
    int l, r, h, mark;

    friend bool operator<(const Line &a, const Line &b) {
        return a.h < b.h;
    }
};

vector <Line> line;
int sum[N << 2], len[N << 2];
int X[N << 2];

void pushup(int rt, int l, int r) {
    if (sum[rt]) len[rt] = X[r + 1] - X[l];
    else len[rt] = len[lson] + len[rson];
}

void update(int rt, int l, int r, int ll, int rr, int val) {
    int lx = X[l], rx = X[r + 1];
    if (rx <= ll || rr <= lx) return;
    if (ll <= lx && rx <= rr) {
        sum[rt] += val;
        pushup(rt, l, r);
        return;
    }
    update(lson, l, mid, ll, rr, val);
    update(rson, mid + 1, r, ll, rr, val);
    pushup(rt, l, r);
}

void solve() {
    cin >> n;
    int x1, x2, y1, y2;
    for (int i = 1; i <= n; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        X[2 * i - 1] = x1;
        X[2 * i] = x2;
        line.push_back((Line) {x1, x2, y1, 1});
        line.push_back((Line) {x1, x2, y2, -1});
    }
    n <<= 1;
    sort(line.begin(), line.end());
    sort(X + 1, X + 1 + n);
    int tot = unique(X + 1, X + 1 + n) - X - 1;
    int ans = 0;
    for (int i = 0; i < line.size() - 1; i++) {
        auto L1 = line[i];
        auto L2 = line[i + 1];
        update(1, 1, tot - 1, L1.l, L1.r, L1.mark);
        ans += len[1] * (L2.h - L1.h);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
