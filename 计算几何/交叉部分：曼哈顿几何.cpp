#include<bits/stdc++.h>

#define endl '\n'
#define int long long
#define pb push_back
#define eb emplace_back
#define unmap unordered_map
#define unset unordered_set
#define MAXQ priority_queue
#define fir first
#define sec second
#define rep(i, a, b) for(int i=a;i<=(b);++i)
#define frep(i, a, b) for(int i=a;i<(b);++i)
using namespace std;
template<typename T> using MINQ = priority_queue <T, vector<T>, greater<T>>;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
const int INF = 1e15;

struct Point {
    int x, y;

    Point(int a = 0, int b = 0) : x(a), y(b) {}

    void read() { cin >> x >> y; }

    void print() { cout << x << " " << y << endl; }
};

struct Seg {
    Point p1, p2;

    Seg() {}

    void read() {
        p1.read();
        p2.read();
    }

    void print() {
        p1.print();
        p2.print();
    }
};

struct EndPoint {
    Point p;
    int idx, st;

    // 点  在线段中的下标 类型
    EndPoint() {}

    EndPoint(Point pp, int iidx, int sst) : p(pp), idx(iidx), st(sst) {}

    friend bool operator<(const EndPoint &a, const EndPoint &b) {
        //按y坐标升序
        if (a.p.y == b.p.y) return a.st < b.st;
            //y相同时，按照下端点、左端点、右端点、上端点的顺序排列
        else return a.p.y < b.p.y;
    }
};

int manhattanIntersection(vector <Seg> &S) {
    const int BOTTOM = 0, LEFT = 1, RIGHT = 2, TOP = 3;
    //定义一下常量，代表点的位置
    vector <EndPoint> EP;
    int i = 0, cnt = 0;
    for (auto &[p1, p2]: S) {
        if (p1.y == p2.y) {
            if (p1.x > p2.x) swap(p1, p2);
        } else if (p1.y > p2.y) swap(p1, p2);
        if (p1.y == p2.y) {
            EP.emplace_back(p1, i, LEFT);
            EP.emplace_back(p2, i, RIGHT);
        } else {
            EP.emplace_back(p1, i, BOTTOM);
            EP.emplace_back(p2, i, TOP);
        }
        i++;
    }
    sort(EP.begin(), EP.end());

    set<int> BT;
    BT.insert(INF);//防止set为空
    for (auto [p, idx, st]: EP) {
        if (st == TOP) BT.erase(p.x);
        else if (st == BOTTOM) BT.insert(p.x);
        else if (st == LEFT) {
            auto beg = BT.lower_bound(S[idx].p1.x);
            auto en = BT.upper_bound(S[idx].p2.x);
            cnt += distance(beg, en);
        }
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    vector <Seg> S(n);
    for (auto &s: S) s.read();
    cout << manhattanIntersection(S) << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int _t = 1;
    for (int i = 1; i <= _t; i++) {
        solve();
    }
    return 0;
}
