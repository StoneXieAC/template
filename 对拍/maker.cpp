#include<bits/stdc++.h>

#define rep(i, a, b) for(int i = a; i <= (b); ++i)
#define frep(i, a, b) for(int i = a; i < (b); ++i)
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAXN = 1000010;
int a[MAXN];

signed main() {
    freopen("in.in", "w", stdout);
    srand(time(0));
    const int N = 10;
    cout << 1 << endl;
    int n = rand() % N + 1;
    rep(i, 1, n) {
        a[i] = rand() % n + 1;
    }
    cout << n << endl;
    rep(i, 1, n) {
        cout << a[i] << " ";
    }
    return 0;
}
