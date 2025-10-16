//neuoj date structure 14-4
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>

#define mem(x, y) memset(x,y,sizeof(x))
#define endl '\n'
//#define int long long
//#define INF
using namespace std;
typedef long long lld;
typedef long double llf;
typedef pair<int, int> pii;
const int N = 2e5 + 10, siz = 62;

int getid(char c) {
    if ('A' <= c && c <= 'Z') return c - 'A';
    if ('a' <= c && c <= 'z') return c - 'a' + 26;
    return c - '0' + 26 + 26;
}

struct AC {
    const int root = 1;
    int t[N][siz], fail[N], deg[N];
    bool vis[N];
    int cnt = root;

    void init() {
        for (int i = 1; i <= cnt; i++) memset(t[i], 0, sizeof(t[i]));
        memset(fail, 0, sizeof(int) * (cnt + 1));
        memset(vis, 0, sizeof(bool) * (cnt + 1));
        memset(deg, 0, sizeof(int) * (cnt + 1));
        cnt = root;
    }

    int insert(string &s) {
        int p = root;
        for (auto c: s) {
            int nex = getid(c);
            if (!t[p][nex]) t[p][nex] = ++cnt;
            p = t[p][nex];
        }
        return p;
    }

    void getfail() {
        queue<int> Q;
        for (int i = 0; i < siz; i++) {
            if (t[root][i]) {
                fail[t[root][i]] = root;
                Q.push(t[root][i]);
                deg[root]++;
            } else t[root][i] = root;
        }
        while (Q.size()) {
            int v = Q.front();
            Q.pop();
            for (int i = 0; i < siz; i++) {
                int &u = t[v][i];
                if (u) {
                    fail[u] = t[fail[v]][i];
                    deg[t[fail[v]][i]]++;
                    Q.push(u);
                } else u = t[fail[v]][i];
            }
        }
    }

    void query(string &s) {
        int p = root;
        for (auto c: s) {
            int nex = getid(c);
            p = t[p][nex];
            vis[p] = 1;
        }
    }

    void getans() {
        queue<int> Q;
        for (int i = 1; i <= cnt; i++) if (!deg[i]) Q.push(i);
        while (Q.size()) {
            int v = Q.front();
            Q.pop();
            deg[fail[v]]--;
            if (vis[v]) vis[fail[v]] = 1;
            if (!deg[fail[v]]) Q.push(fail[v]);
        }
    }
} ac;

void solve() {
    string t, s;
    cin >> t;
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        vec.push_back(ac.insert(s));
        if (ac.cnt + 1005 > N) {
            ac.getfail();
            ac.query(t);
            ac.getans();
            for (int x: vec) {
                if (ac.vis[x]) cout << "1\n";
                else cout << "0\n";
            }
            vec.clear();
            ac.init();
        }
    }
    if (vec.empty()) return;
    ac.getfail();
    ac.query(t);
    ac.getans();
    for (int x: vec) {
        if (ac.vis[x]) cout << "1\n";
        else cout << "0\n";
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _t = 1;
    for (int i = 1; i <= _t; i++) {
        solve();
    }
    return 0;
}
