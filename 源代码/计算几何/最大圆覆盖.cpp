#include<bits/stdc++.h>

#define endl '\n'
#define int long long
#define unmap unordered_map
#define unset unordered_set
#define MAXQ priority_queue
#define rep(i, a, b) for(int i=a;i<=(b);++i)
#define frep(i, a, b) for(int i=a;i<(b);++i)
using namespace std;
template<typename T> using MINQ = priority_queue <T, vector<T>, greater<T>>;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vi>;
constexpr double EPS = 1e-8;

struct Point {
    double x, y;

    Point(const double a = 0, const double b = 0) : x(a), y(b) {}

    friend Point operator-(const Point &a, const Point &b) {
        return {a.x - b.x, a.y - b.y};
    }

    friend double operator%(const Point &a, const Point &b) {
        return a.x * b.y - a.y * b.x;
    }
};

double dis(const Point &a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

double dis(const Point &a, const Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double ddis(const Point &a, const Point &b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int sign(double a) {
    if (fabs(a) < EPS) return 0;
    return a > 0 ? 1 : -1;
}

int dcmp(double a, double b) {
    return sign(a - b);
}

struct Cir {
    Point o;
    double r;

    Cir(Point oo, double rr) : o(oo), r(rr) {
    }

    Cir(double x = 0, double y = 0, double rr = 0) { o.x = x, o.y = y, r = rr; }
};

Cir calTrangleOuterCir(Point p1, Point p2, Point p3) {
    Cir c;
    c.r = dis(p1, p2) * dis(p2, p3) * dis(p1, p3) / fabs((p2 - p1) % (p3 - p1)) / 2.0;
    auto a11 = (p2.x - p1.x);
    auto a12 = (p2.y - p1.y);
    auto b1 = (p1.x * (p2.x - p1.x) + p1.y * (p2.y - p1.y) + 0.5 * ddis(p1, p2));
    auto a21 = (p3.x - p1.x);
    auto a22 = (p3.y - p1.y);
    auto b2 = (p1.x * (p3.x - p1.x) + p1.y * (p3.y - p1.y) + 0.5 * ddis(p1, p3));
    auto down = (a11 * a22 - a21 * a12);
    c.o.x = (b1 * a22 - b2 * a12) / down;
    c.o.y = (a11 * b2 - b1 * a21) / down;
    return c;
}

Cir calPolygonOuterCir(vector <Point> &p) {
    random_device rd;
    mt19937 g(rd());
    shuffle(p.begin(), p.end(), g);
    Cir c(p[0], 0);
    for (int i = 1; i < p.size(); i++) {
        if (dcmp(dis(c.o, p[i]), c.r) > 0) {
            c.r = 0;
            c.o = p[i];
            for (int j = 0; j < i; j++) {
                if (dcmp(dis(c.o, p[j]), c.r) > 0) {
                    c.r = dis(p[j], p[i]) / 2;
                    c.o = {(p[j].x + p[i].x) / 2, (p[j].y + p[i].y) / 2};
                    for (int k = 0; k < j; k++) {
                        if (dcmp(dis(c.o, p[k]), c.r) > 0) {
                            c = calTrangleOuterCir(p[i], p[j], p[k]);
                        }
                    }
                }
            }
        }
    }
    return c;
}

void solve() {
    int n, m;
    cin >> n;
    vector <Point> p1(n);
    for (auto &[x, y]: p1) cin >> x >> y;
    cin >> m;
    vector <Point> p2(m);
    for (auto &[x, y]: p2) cin >> x >> y;
    vector <Point> p;
    for (auto [x1, y1]: p1)
        for (auto [x2, y2]: p2)
            p.emplace_back(x2 - x1, y2 - y1);
    const auto c = calPolygonOuterCir(p);
    cout << c.r << " " << c.o.x << " " << c.o.y << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int _t = 1;
    cout << fixed << setprecision(10);
    for (int i = 1; i <= _t; i++) {
        solve();
    }
    return 0;
}
