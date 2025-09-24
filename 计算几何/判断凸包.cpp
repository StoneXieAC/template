//叉乘判断多边形是否为凸包
const int N = 1e5 + 10;
const double EPS = 1e-7;
Point p[N];

bool check(int n) {
    bool f = 1;
    //如果输入点的方式为逆时针输入,则将 < 改成 >
    for (int i = 0; i < n; i++) {
        if ((p[i] - p[(i + 1) % n]) % (p[(i + 2) % n] - p[(i + 1) % n]) < 0)
            return 0;
    }
    return 1;
}
