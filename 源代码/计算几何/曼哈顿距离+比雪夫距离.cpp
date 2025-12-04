//  求n个点之间最大的曼哈顿距离
//  曼哈顿距离:abs(x1-x2)+abs(y1-y2)
//  比雪夫距离:max(abs(x1-x2),abs(y1-y2))
//  曼哈顿距离换切比雪夫距离。
//  曼哈顿坐标系是通过切比雪夫坐标系旋转 45度 后，再缩小到原来的一半得到的。
//  将一个点 (x,y) 的坐标变为 (x + y, x - y) 后，原坐标系中的曼哈顿距离等于新坐标系中的切比雪夫距离。
//  将一个点 (x,y) 的坐标变为((x + y)/2,(x - y)/2) 后，原坐标系中的切比雪夫距离等于新坐标系中的曼哈顿距离。
void solve() {
    int minx = 1e10, miny = 1e10, maxx = -1e10, maxy = -1e10;
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b;
        std::cin >> a >> b;
        int x = a + b, y = a - b;
        maxx = std::max(x, maxx), maxy = std::max(y, maxy);
        minx = std::min(x, minx), miny = std::min(y, miny);
    }
    std::cout << std::max(maxx - minx, maxy - miny);
}