const int N = 1e5 + 10;
const double EPS = 1e-7;
Point p[N], s[N];

double dis(Point a, Point b) {
    //求ab距离
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double Segdis(Point a, Point b, Point c) {
    //点c到线段ab的距离
    return fabs((b - a) % (c - a)) / dis(a, b);
}

//andrew找凸包
int andrew(int n, Point point[], Point res[]) {
    //n>=2
    //point和res下标从0开始,方便取模
    sort(point, point + n, [&](const Point &a, const Point &b) {
        if (fabs(a.x - b.x) < EPS) return a.y < b.y;
        return a.x < b.x;
    });
    int m = 0;
    for (int i = 0; i < n; i++) {
        while (m > 1 && (res[m - 1] - res[m - 2]) % (point[i] - res[m - 2]) <= 0) --m;
        //如果想保留凸包边上的点,可以把 <= 换成 <
        res[m++] = point[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; i--) {
        while (m > k && (res[m - 1] - res[m - 2]) % (point[i] - res[m - 2]) <= 0) --m;
        res[m++] = point[i];
    }
    --m;
    //point[1]被重复记录了,删去
    return m;
}

//旋转卡壳求凸包直径
double rotate(int n, Point res[]) {
    //虽然n>=2时即认为凸包存在，但是旋转卡壳的时候要求凸包上的点>=3
    if (n == 2) return dis(res[1], res[0]);
    int cur = 0;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        while (Segdis(res[i], res[(i + 1) % n], res[cur]) <= Segdis(res[i], res[(i + 1) % n], res[(cur + 1) % n]))
            cur = (cur + 1) % n;
        ans = max(ans, dis(res[i], res[cur]));
        ans = max(ans, dis(res[(i + 1) % n], res[cur]));
    }
    return ans;
}
