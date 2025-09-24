//
#include<bits/stdc++.h>

#define mem(x, y) memset(x,y,sizeof(x))
#define endl '\n'
#define int long long
#define pb push_back
//#define INF
using namespace std;
typedef long long lld;
typedef long double llf;
typedef pair<int, int> pii;
const int N = 5e5 + 10;
int nex[N];

void getnex(const string &s) {
    int n = s.size();
    int i = 0, j = -1;
    nex[0] = -1;
    while (i < n) {
        if (s[i] == s[j] || j == -1)
            nex[++i] = ++j;
        else j = nex[j];
    }
}

int kmp(const string &a, const string &b) {
    int i = 0, j = 0, res = 0;
    getnex(b);
    while (i < a.size()) {
        if (j == -1 || a[i] == b[j]) {
            i++;
            j++;
        } else j = nex[j];
        if (j == b.size()) {
            j = nex[j];
            res++;
        }
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        cout << kmp(s, t) << endl;
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
