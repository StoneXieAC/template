template<typename T = long long>
struct Tree {
    std::vector<T> sum;
    int n;

    Tree(int siz = 0) {
        sum.resize(siz + 2, T());
        n = siz;
    }

    void resize(int siz) {
        n = siz;
        sum.resize(siz + 2);
        init();
    }

    void init() {
        std::fill(sum.begin(), sum.end(), T());
    }

    void update(int x, T y) {
        for (; x <= n; x += (x & -x)) sum[x] += y;
    }

    T query(int x) {
        T res = T();
        for (; x; x -= (x & -x)) res += sum[x];
        return res;
    }

    T query(int x, int y) {
        T res = T();
        for (--x; x; x -= (x & -x)) res -= sum[x];
        for (; y; y -= (y & -y)) res += sum[y];
        return res;
    }
};
