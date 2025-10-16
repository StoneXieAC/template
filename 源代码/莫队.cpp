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
const int N = 3e5 + 10;
pii q[N];
int id[N], ans[N], a[N], b[N];
int n, m, len;
int cnt[N], res, sum[N];

int get(int x) {
    return (x - 1) / len + 1;
}

bool cmp(int i, int j) {
    if (get(q[i].first) == get(q[j].first)) return q[i].second < q[j].second;
    return get(q[i].first) < get(q[j].first);
}

void add(int x) {
    sum[cnt[x]]--;
    cnt[x]++;
    sum[cnt[x]]++;
    res = max(res, cnt[x]);
}

void del(int x) {
    sum[cnt[x]]--;
    if (res == cnt[x] && sum[cnt[x]] == 0) res--;
    cnt[x]--;
    sum[cnt[x]]++;
}

int query(int l, int r) {
    int dt = (r - l + 1) - res;
    if (res - dt >= 1) return res - dt;
    return 1;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> q[i].first >> q[i].second;
        id[i] = i;
    }
    len = sqrt(n);
    len += (int) (len * len != n);
    sort(id + 1, id + 1 + m, cmp);
    auto [L, R] = q[id[1]];
    for (int i = L; i <= R; i++) add(a[i]);
    ans[id[1]] = query(L, R);
    for (int i = 2; i <= m; i++) {
        auto [l, r] = q[id[i]];
        while (L > l) add(a[--L]);
        while (R < r) add(a[++R]);
        while (L < l) del(a[L++]);
        while (R > r) del(a[R--]);
        ans[id[i]] = query(l, r);
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int _t = 1;
    for (int i = 1; i <= _t; i++) {
        solve();
    }
    return 0;
}

